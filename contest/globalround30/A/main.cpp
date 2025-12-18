#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<long long> baseSwords(n);
        for (auto &x : baseSwords) cin >> x;

        vector<long long> b(m), c(m);
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < m; i++) cin >> c[i];

        vector<pair<long long,long long>> monsters(m);
        for (int i = 0; i < m; i++) monsters[i] = {b[i], c[i]};

        sort(monsters.begin(), monsters.end());
        multiset<long long> swords(baseSwords.begin(), baseSwords.end());

        priority_queue<pair<long long,long long>> candidates; // (c, b)
        int kills = 0, idx = 0;

        while (!swords.empty()) {
            long long strongest = *prev(swords.end());
            while (idx < m && monsters[idx].first <= strongest) {
                candidates.push({monsters[idx].second, monsters[idx].first});
                idx++;
            }
            if (candidates.empty()) break;

            vector<pair<long long,long long>> stash;
            auto pick = pair<long long,long long>{-1, -1};

            while (!candidates.empty()) {
                auto cur = candidates.top();
                long long need = cur.second;
                auto it = swords.lower_bound(need);
                if (it != swords.end()) { pick = cur; break; }
                stash.push_back(cur);
                candidates.pop();
            }

            for (auto &x : stash) candidates.push(x);
            if (pick.first == -1) break;

            long long reward = pick.first, need = pick.second;
            auto it = swords.lower_bound(need);
            long long used = *it;
            swords.erase(it);
            kills++;
            if (reward > 0) swords.insert(max(used, reward));
        }

        cout << kills << "\n";
    }
}
