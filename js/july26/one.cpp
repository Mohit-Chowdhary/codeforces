#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------
// BOARD SETUP
// ---------------------------------------------------------------------
const int N = 8;                 // 8x8 board
const int NUM_REGIONS = 13;      // 12 pentominoes + 1 tetromino

inline int idx(int r, int c) { return r * N + c; }

// ---------------------------------------------------------------------
// REGION MAP  -- TODO: fill this in yourself from the image.
// region[r][c] = which region (1..13) that cell belongs to.
// row 0 = TOP row of the image, col 0 = LEFT column.
// Currently filled with -1 as a placeholder so it's obvious what's missing.
// ---------------------------------------------------------------------
int region[N][N] = {
    { 1, 1, 1, 1, 1, 2, 2, 2 },
    { 3, 3, 3, 4, 4, 5, 5, 2 },
    { 3, 7, 3, 4, 4, 4, 5, 2 },
    { 6, 7, 7, 8, 8, 9, 5, 5 },
    { 6, 6, 7, 8, 8, 9, 9,13 },
    { 6,10, 7,11, 9, 9,12,13 },
    { 6,10,11,11,11,12,12,13 },
    {10,10,10,11,12,12,13,13 },
};

// ---------------------------------------------------------------------
// CLUES -- printed numbers on the board, taken straight from the image.
// (row, col, value). row 0 = top, col 0 = left.
// The "0" at bottom-left is the start square / move 0.
// ---------------------------------------------------------------------
struct Clue { int r, c, val; };
vector<Clue> clues = {
    {0, 5, 37},
    {0, 7, 1100},
    {2, 3, 23},
    {2, 5, 138},
    {3, 0, 528},
    {4, 1, 449},
    {4, 4, 16},
    {5, 1, 750},
    {5, 3, 88},
    {5, 5, 272},
    {5, 6, 1},
    {7, 0, 0},     // start square, score 0
};

// quick lookup: cell index -> required score value if/when visited
unordered_map<int,long long> clueAt;

const int START_R = 7, START_C = 0;

// ---------------------------------------------------------------------
// MOVE GENERATION
// A "move" travels 0 in one dim, 1 in another, 2 in the third, across
// (x,y,z=altitude). Since altitude only ever takes values 0 or 1, the
// "2" component can never be altitude. So every move is exactly one of:
//
//  TYPE A (flat):     planar offset (±1,±2) or (±2,±1), altitude SAME
//  TYPE B (vertical):  planar offset (±2,0) or (0,±2), altitude DIFFERS by 1
// ---------------------------------------------------------------------
struct MoveOffset { int dr, dc; bool vertical; };

vector<MoveOffset> allOffsets = {
    // Type A: flat knight moves, altitude unchanged
    {1,2,false},{1,-2,false},{-1,2,false},{-1,-2,false},
    {2,1,false},{2,-1,false},{-2,1,false},{-2,-1,false},
    // Type B: straight 2-jump, altitude must flip
    {2,0,true},{-2,0,true},{0,2,true},{0,-2,true},
};

// precomputed legal destination offsets per cell (just bounds-checked ones)
vector<MoveOffset> movesFrom[N*N];

void precomputeMoves() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            for (auto &m : allOffsets) {
                int nr = r + m.dr, nc = c + m.dc;
                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    movesFrom[idx(r,c)].push_back(m);
                }
            }
        }
    }
}

// ---------------------------------------------------------------------
// SEARCH STATE
// ---------------------------------------------------------------------
int towerOfRegion[NUM_REGIONS+1]; // region id -> cell idx of its tower, -1 if unassigned
bitset<64> visited;
vector<int> path;        // sequence of cell indices visited so far
vector<long long> scoreAtStep; // score recorded at each step (index-aligned with path)

int totalTowersNeeded = NUM_REGIONS;

// ---------------------------------------------------------------------
// LIGHTWEIGHT PROGRESS REPORTING
// Cheap counter + modulo check -- negligible overhead, just prints
// occasionally so you can see it's alive and how deep it's getting.
// ---------------------------------------------------------------------
long long nodeCount = 0;
int bestDepthSeen = 0;
int bestTowersSeen = 0;
const long long PRINT_EVERY = 2000000; // tune this if it prints too often/rarely

void maybeReportProgress(int depth, int towersHit) {
    nodeCount++;
    if (depth > bestDepthSeen) bestDepthSeen = depth;
    if (towersHit > bestTowersSeen) bestTowersSeen = towersHit;
    if (nodeCount % PRINT_EVERY == 0) {
        cerr << "[progress] nodes=" << nodeCount
             << " bestDepth=" << bestDepthSeen
             << " bestTowersHit=" << bestTowersSeen
             << " curDepth=" << depth
             << " curTowersHit=" << towersHit << "\n";
    }
}

int K_GUESS = -1; // fill in once determined; -1 disables checks past move 18

// ---------------------------------------------------------------------
// RECORDED MOVE NUMBERS: moves 3,6,9,12,15,18, then every K after.
// At each of these move numbers, the knight is REQUIRED to be standing
// on some clue cell with the matching score -- not just "if it happens
// to land there." This turns the search from "wander and hope" into
// "must check in on schedule," which prunes enormously earlier.
//
// K is unknown -- try candidate values and see which lets a full,
// consistent path exist. Set K_GUESS below and rerun for each candidate.
// ---------------------------------------------------------------------
bool isRecordedMove(int moveNum) {
    if (moveNum <= 18) return moveNum % 3 == 0;
    if (K_GUESS <= 0) return false; // no K chosen yet -- no extra checks past 18
    return (moveNum - 18) % K_GUESS == 0;
}

// Applies the score rule for move number n (1-indexed), given whether
// altitude stayed same / went up / went down. Returns -1 if illegal
// (e.g. non-divisible "down" move).
long long applyScore(long long score, int n, int altFrom, int altTo) {
    if (altFrom == altTo) {
        return score + n;               // same altitude
    } else if (altTo > altFrom) {
        return score * n;               // moved up
    } else {
        if (n == 0) return -1;
        if (score % n != 0) return -1;  // illegal unless evenly divisible
        return score / n;
    }
}

// altitude of a cell given current (possibly partial) tower assignment
int altitudeOf(int cell) {
    int reg = region[cell / N][cell % N];
    if (reg < 1) return 0; // unfilled region map -- treat as ground for now
    return (towerOfRegion[reg] == cell) ? 1 : 0;
}

bool towersRemaining(int countPlaced) {
    return countPlaced < totalTowersNeeded;
}

// ---------------------------------------------------------------------
// DFS
// cell        : current cell index
// moveNum     : the move number that is about to be made (i.e. next move is #moveNum)
// score       : current running score
// towersHit   : how many distinct region-towers visited so far
// ---------------------------------------------------------------------
bool dfs(int cell, int moveNum, long long score, int towersHit) {
    maybeReportProgress((int)path.size(), towersHit);

    // success condition: all towers visited (order of finishing doesn't
    // matter here, but you may want extra logic if the puzzle requires
    // stopping exactly when the last tower is hit)
    if (towersHit == totalTowersNeeded) {
        // Every clue square (except start) must have been visited by now --
        // its number was only recorded because the knight passed through it.
        for (auto &kv : clueAt) {
            int c = kv.first;
            if (c == idx(START_R, START_C)) continue;
            if (!visited[c]) return false; // missed a clue square, not a real solution
        }
        return true;
    }

    for (auto &m : movesFrom[cell]) {
        int r = cell / N, c = cell % N;
        int nr = r + m.dr, nc = c + m.dc;
        int next = idx(nr, nc);
        if (visited[next]) continue;

        int reg = region[nr][nc];
        if (reg < 1) continue; // region map not filled in yet -- skip

        int altFrom = altitudeOf(cell);
        int altTo;
        bool assignedTowerHere = false;

        if (!m.vertical) {
            // Type A: altitude must stay the same as current cell.
            // If 'next' happens to already be a fixed tower cell for its
            // region, that would force altTo=1, which is only legal if
            // altFrom is also 1. Otherwise altTo = altFrom (0 by default
            // unless next IS the assigned tower).
            if (towerOfRegion[reg] == next) altTo = 1;
            else altTo = 0;
            if (altTo != altFrom) continue; // inconsistent, illegal
        } else {
            // Type B: altitude must flip relative to 'cell'.
            altTo = 1 - altFrom;
            if (altTo == 1) {
                // 'next' must BE this region's tower.
                if (towerOfRegion[reg] != -1 && towerOfRegion[reg] != next) {
                    continue; // region's tower already placed elsewhere
                }
                if (towerOfRegion[reg] == -1) {
                    towerOfRegion[reg] = next;
                    assignedTowerHere = true;
                }
            } else {
                // 'next' must NOT be this region's tower (it's descending
                // to ground level); if next is already fixed as the tower
                // for its own region, that's a contradiction.
                if (towerOfRegion[reg] == next) continue;
            }
        }

        long long newScore = applyScore(score, moveNum, altFrom, altTo);
        if (newScore < 0) continue; // illegal division

        // live pruning: if 'next' is a clue square, score MUST match
        auto it = clueAt.find(next);
        bool onClue = (it != clueAt.end());
        if (onClue && it->second != newScore) {
            if (assignedTowerHere) towerOfRegion[reg] = -1;
            continue;
        }

        // ACTIVE checkpoint enforcement: if this move number is one of the
        // recorded ones, we MUST be on a (correctly-scored) clue cell now.
        if (isRecordedMove(moveNum) && !onClue) {
            if (assignedTowerHere) towerOfRegion[reg] = -1;
            continue;
        }

        // commit
        visited[next] = true;
        path.push_back(next);
        scoreAtStep.push_back(newScore);
        int newTowersHit = towersHit + (altTo == 1 ? 1 : 0);
        // NOTE: only counts as a "new" tower visit if we just arrived at
        // altitude 1 for the first time on this cell -- adjust if a tower
        // can be revisited logic differs from your reading of the rules.

        if (dfs(next, moveNum + 1, newScore, newTowersHit)) {
            return true; // success -- leave state committed
        }

        // undo (backtrack)
        visited[next] = false;
        path.pop_back();
        scoreAtStep.pop_back();
        if (assignedTowerHere) towerOfRegion[reg] = -1;
    }

    return false;
}

// ---------------------------------------------------------------------
// POST-CHECK: verify the "recorded every 3 moves up to 18, then every K"
// pattern once a full path is found. Fill in / adapt once you've
// determined which clue corresponds to which move number.
// ---------------------------------------------------------------------
void checkRecordPattern() {
    // TODO
}

int main() {
    for (auto &cl : clues) clueAt[idx(cl.r, cl.c)] = cl.val;
    for (int i = 1; i <= NUM_REGIONS; i++) towerOfRegion[i] = -1;

    precomputeMoves();

    int startCell = idx(START_R, START_C);
    visited[startCell] = true;
    path.push_back(startCell);
    scoreAtStep.push_back(0);

    cerr << "[start] launching search...\n";
    bool found = dfs(startCell, 1, 0, 0);
    cerr << "[end] total nodes explored: " << nodeCount << "\n";

    if (found) {
        cout << "Solution found!\n";
        for (size_t i = 0; i < path.size(); i++) {
            int r = path[i] / N, c = path[i] % N;
            cout << "move " << i << ": (" << r << "," << c << ") score=" << scoreAtStep[i] << "\n";
        }
    } else {
        cout << "No solution found (region map likely still incomplete).\n";
    }

    return 0;
}