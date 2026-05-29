import tkinter as tk
from collections import deque
import math

LARGE = math.pi / 4
SMALL = 1 - math.pi / 4

ROWS, COLS = 9, 9
CELL = 72

GREEN = {
    (0,0),(0,3),(0,5),(0,7),
    (1,3),(1,6),(1,9),
    (2,0),(2,7),
    (3,8),
    (4,0),(4,4),
    (5,7),(5,8),
    (7,0),
    (8,1),(8,4),(8,6),(8,8)
}

GIVEN = {
    (0,2): 21,
    (1,0): 21, (1,4): 27, (1,7): 25,
    (2,1): 27, (2,5): 15, (2,8): 9,
    (4,0): 25, (4,3): 27, (4,5): 45, (4,8): 9,
    (6,0): 9,  (6,3): 63, (6,7): 45,
    (7,1): 63, (7,4): 9,  (7,8): 288,
    (8,6): 35
}

arc_state = [[None]*COLS for _ in range(ROWS)]

# ── drawing ───────────────────────────────────────────────────────────────────

def draw_arc(canvas, r, c, o):
    x0, y0 = c*CELL, r*CELL
    if   o == 0: bbox=(x0-CELL,y0-CELL,x0+CELL,y0+CELL); s,e=270,90
    elif o == 1: bbox=(x0,y0-CELL,x0+2*CELL,y0+CELL);    s,e=180,90
    elif o == 2: bbox=(x0-CELL,y0,x0+CELL,y0+2*CELL);    s,e=0,90
    else:        bbox=(x0,y0,x0+2*CELL,y0+2*CELL);        s,e=90,90
    canvas.create_arc(*bbox, start=s, extent=e, style=tk.ARC,
                      outline='black', width=2.5, tags=('arc',f'arc_{r}_{c}'))

def redraw(canvas):
    canvas.delete('arc','num')
    for r in range(ROWS):
        for c in range(COLS):
            if arc_state[r][c] is not None and (r,c) not in GREEN:
                draw_arc(canvas, r, c, arc_state[r][c])
            if (r,c) in GIVEN:
                canvas.create_text(c*CELL+CELL//2, r*CELL+CELL//2,
                    text=str(GIVEN[(r,c)]), font=('Courier',11,'bold'), tags='num')

# ── interaction ───────────────────────────────────────────────────────────────

def on_click(event, canvas):
    c, r = event.x//CELL, event.y//CELL
    if 0<=r<ROWS and 0<=c<COLS and (r,c) not in GREEN:
        cur = arc_state[r][c]
        arc_state[r][c] = 0 if cur is None else (cur+1)%4
        redraw(canvas)

def on_right_click(event, canvas):
    c, r = event.x//CELL, event.y//CELL
    if 0<=r<ROWS and 0<=c<COLS and (r,c) not in GREEN:
        arc_state[r][c] = None
        redraw(canvas)

# ── checker ───────────────────────────────────────────────────────────────────

def get_halves(r, c):
    s = arc_state[r][c]
    if s is None or (r,c) in GREEN:
        return {'T','R','B','L'}, set()
    if s == 0: return {'T','L'}, {'B','R'}
    if s == 1: return {'T','R'}, {'B','L'}
    if s == 2: return {'B','L'}, {'T','R'}
    else:      return {'B','R'}, {'T','L'}

def half_node(r, c, edge):
    h0e, h1e = get_halves(r, c)
    return (r,c,0) if (edge in h0e or not h1e) else (r,c,1)

def build_graph():
    adj = {(r,c,h):set() for r in range(ROWS) for c in range(COLS) for h in (0,1)}
    for r in range(ROWS):
        for c in range(COLS):
            for edge,nr,nc,nedge in [('T',r-1,c,'B'),('B',r+1,c,'T'),('L',r,c-1,'R'),('R',r,c+1,'L')]:
                if 0<=nr<ROWS and 0<=nc<COLS:
                    src = half_node(r,c,edge)
                    dst = half_node(nr,nc,nedge)
                    adj[src].add(dst); adj[dst].add(src)
            s = arc_state[r][c]
            if s is None or (r,c) in GREEN:
                adj[(r,c,0)].add((r,c,1)); adj[(r,c,1)].add((r,c,0))
    return adj

def flood_fill(adj):
    visited = {}; rid = 0
    for node in adj:
        if node not in visited:
            q = deque([node]); visited[node] = rid
            while q:
                cur = q.popleft()
                for nb in adj[cur]:
                    if nb not in visited:
                        visited[nb] = rid; q.append(nb)
            rid += 1
    return visited, rid

# ── smooth piece counting ─────────────────────────────────────────────────────
#
# Arc orientations and which edge midpoints they touch:
#   o=0 (TL corner): touches T-mid and L-mid
#   o=1 (TR corner): touches T-mid and R-mid
#   o=2 (BL corner): touches B-mid and L-mid
#   o=3 (BR corner): touches B-mid and R-mid
#
# Two arcs sharing an edge midpoint are smooth if their concavities are compatible.
# At a shared horizontal edge (top of cell A = bottom of cell B):
#   smooth pairs: A=o2,B=o0  or  A=o3,B=o1
#   (both arcs curve away from the shared edge on their respective sides)
# At a shared vertical edge (right of cell A = left of cell B):
#   smooth pairs: A=o1,B=o0  or  A=o3,B=o2
#
# A straight edge is NEVER smooth with anything.
# So each straight boundary segment = 1 smooth piece on its own.
# Each arc boundary segment starts as 1 piece, but merges with a neighbour arc
# if they share an edge midpoint AND are a smooth pair.
#
# smooth_pieces(region) = (# straight boundary segs) + (# arc boundary chains)
# where arc chains are found by union-find merging smooth arc pairs.

# Arc touches which edges:
ARC_EDGES = {0: ('T','L'), 1: ('T','R'), 2: ('B','L'), 3: ('B','R')}

# Smooth pairs at shared edges: (edge_of_cell_A, o_A, o_B) where B is the neighbour
# Horizontal shared edge: cell's B-edge meets neighbour's T-edge
SMOOTH_HORIZ = {(2,0), (3,1)}   # (o of top cell, o of bottom cell)
# Vertical shared edge: cell's R-edge meets neighbour's L-edge  
SMOOTH_VERT  = {(1,0), (3,2)}   # (o of left cell, o of right cell)

def count_smooth_pieces(region_nodes, visited):
    """
    region_nodes: set of (r,c,h) belonging to this region
    Returns number of smooth pieces on region boundary.
    """
    # Collect boundary segments for this region
    # Two types:
    # 1. STRAIGHT: a cell edge between this region and another (or grid border)
    # 2. ARC: the arc curve in a cell where h0 and h1 are in different regions

    straight_count = 0
    arc_cells = []  # list of (r,c) where arc is boundary of this region

    region_set = set(region_nodes)

    for (r,c,h) in region_set:
        s = arc_state[r][c]

        # Check arc boundary: arc cell where the two halves are in different regions
        if s is not None and (r,c) not in GREEN:
            n0 = (r,c,0); n1 = (r,c,1)
            rid0 = visited.get(n0); rid1 = visited.get(n1)
            if rid0 != rid1:
                # This arc is a boundary — only count once (when h==0)
                if h == 0:
                    arc_cells.append((r,c))

        # Check straight boundary edges
        for edge, nr, nc, nedge in [('T',r-1,c,'B'),('B',r+1,c,'T'),('L',r,c-1,'R'),('R',r,c+1,'L')]:
            h0e, _ = get_halves(r,c)
            owns = edge in h0e
            if not ((owns and h==0) or (not owns and h==1)):
                continue  # this half doesn't own this edge, skip
            if 0<=nr<ROWS and 0<=nc<COLS:
                neighbour = half_node(nr,nc,nedge)
                if neighbour not in region_set:
                    # only count from the lower-index cell to avoid double count
                    if (r,c) < (nr,nc):
                        straight_count += 1
            else:
                # grid border — always count, no double count possible
                straight_count += 1

    # Now count arc chains using union-find
    # Each arc cell starts as its own piece
    parent = {(r,c): (r,c) for (r,c) in arc_cells}

    def find(x):
        while parent[x] != x: parent[x] = parent[parent[x]]; x = parent[x]
        return x
    def union(x, y):
        parent[find(x)] = find(y)

    arc_set = set(arc_cells)

    for (r,c) in arc_cells:
        o = arc_state[r][c]
        # Check each neighbour this arc shares an edge midpoint with
        # Horizontal: check bottom neighbour (this cell's B, neighbour's T)
        if 'B' in ARC_EDGES[o]:
            nr = r+1
            if 0<=nr<ROWS and arc_state[nr][c] is not None and (nr,c) not in GREEN:
                o2 = arc_state[nr][c]
                if 'T' in ARC_EDGES[o2]:
                    if (o, o2) in SMOOTH_HORIZ and (nr,c) in arc_set:
                        # check both arcs are boundary of SAME region
                        rid_self  = visited.get((r,c,0))
                        rid_other = visited.get((nr,c,0))
                        if rid_self == rid_other:
                            union((r,c),(nr,c))
        # Horizontal: check top neighbour
        if 'T' in ARC_EDGES[o]:
            nr = r-1
            if 0<=nr<ROWS and arc_state[nr][c] is not None and (nr,c) not in GREEN:
                o2 = arc_state[nr][c]
                if 'B' in ARC_EDGES[o2]:
                    if (o2, o) in SMOOTH_HORIZ and (nr,c) in arc_set:
                        rid_self  = visited.get((r,c,0))
                        rid_other = visited.get((nr,c,0))
                        if rid_self == rid_other:
                            union((r,c),(nr,c))
        # Vertical: check right neighbour
        if 'R' in ARC_EDGES[o]:
            nc = c+1
            if 0<=nc<COLS and arc_state[r][nc] is not None and (r,nc) not in GREEN:
                o2 = arc_state[r][nc]
                if 'L' in ARC_EDGES[o2]:
                    if (o, o2) in SMOOTH_VERT and (r,nc) in arc_set:
                        rid_self  = visited.get((r,c,0))
                        rid_other = visited.get((r,nc,0))
                        if rid_self == rid_other:
                            union((r,c),(r,nc))
        # Vertical: check left neighbour
        if 'L' in ARC_EDGES[o]:
            nc = c-1
            if 0<=nc<COLS and arc_state[r][nc] is not None and (r,nc) not in GREEN:
                o2 = arc_state[r][nc]
                if 'R' in ARC_EDGES[o2]:
                    if (o2, o) in SMOOTH_VERT and (r,nc) in arc_set:
                        rid_self  = visited.get((r,c,0))
                        rid_other = visited.get((r,nc,0))
                        if rid_self == rid_other:
                            union((r,c),(r,nc))

    arc_chain_count = len(set(find(x) for x in arc_cells))
    return straight_count + arc_chain_count

# ── compute regions ───────────────────────────────────────────────────────────

def compute_regions():
    adj = build_graph()
    visited, _ = flood_fill(adj)

    # area
    area = {}
    for (r,c,h), rid in visited.items():
        s = arc_state[r][c]
        if s is None or (r,c) in GREEN:
            if h == 0: area[rid] = area.get(rid,0) + 1
        else:
            area[rid] = area.get(rid,0) + (SMALL if h==0 else LARGE)

    # group nodes by region
    region_nodes = {}
    for node, rid in visited.items():
        region_nodes.setdefault(rid, set()).add(node)

    # smooth pieces per region
    smooth = {}
    for rid, nodes in region_nodes.items():
        smooth[rid] = count_smooth_pieces(nodes, visited)

    # score = area * smooth
    score = {rid: area.get(rid,0) * smooth.get(rid,0) for rid in region_nodes}

    # clue regions
    clue_region = {}
    for (r,c) in GIVEN:
        if (r,c,0) in visited:
            clue_region[(r,c)] = visited[(r,c,0)]

    # conflicts
    region_clues = {}
    for (r,c),rid in clue_region.items():
        region_clues.setdefault(rid,[]).append((r,c))
    conflicts = []
    for rid, cells in region_clues.items():
        vals = [GIVEN[cell] for cell in cells]
        if len(set(vals)) > 1:
            conflicts.append(f"CONFLICT: {cells} same region, scores {vals}")

    return visited, area, smooth, score, clue_region, conflicts

def check():
    visited, area, smooth, score, clue_region, conflicts = compute_regions()
    lines = ["── clue regions ─────────────────"]
    for (r,c), expected in sorted(GIVEN.items()):
        rid = clue_region.get((r,c))
        if rid is None:
            lines.append(f"({r},{c}) exp={expected:4d}  ???")
            continue
        a = area.get(rid,0)
        sp = smooth.get(rid,0)
        sc = score.get(rid,0)
        ok = '✓' if abs(sc - expected) < 0.01 else '✗'
        lines.append(f"({r},{c}) exp={expected:4d}  a={a:.2f} sp={sp} sc={sc:.1f} {ok}")

    lines.append("")
    lines.append("── issues ───────────────────────")
    issues = []
    for rid,a in area.items():
        if abs(a - round(a)) > 1e-9:
            issues.append(f"non-int area {a:.3f} region {rid}")
    for msg in conflicts:
        issues.append(msg)
    if issues:
        for i in issues: lines.append(i)
    else:
        lines.append("none :)")

    result_text.config(state='normal')
    result_text.delete('1.0',tk.END)
    result_text.insert(tk.END,'\n'.join(lines))
    result_text.config(state='disabled')

# ── UI ────────────────────────────────────────────────────────────────────────

root = tk.Tk()
root.title('Arc Puzzle')
root.resizable(False, False)

W, H = COLS*CELL, ROWS*CELL

canvas = tk.Canvas(root, width=W, height=H, bg='white', highlightthickness=0)
canvas.grid(row=0, column=0, rowspan=10, padx=4, pady=4)

for r in range(ROWS+1):
    lw = 2 if r in (0,ROWS) else 0.5
    canvas.create_line(0,r*CELL,W,r*CELL,width=lw)
for c in range(COLS+1):
    lw = 2 if c in (0,COLS) else 0.5
    canvas.create_line(c*CELL,0,c*CELL,H,width=lw)
for (r,c) in GREEN:
    canvas.create_rectangle(c*CELL,r*CELL,(c+1)*CELL,(r+1)*CELL,fill='#7ec87e',outline='')
for r in range(ROWS+1):
    lw = 2 if r in (0,ROWS) else 0.5
    canvas.create_line(0,r*CELL,W,r*CELL,width=lw)
for c in range(COLS+1):
    lw = 2 if c in (0,COLS) else 0.5
    canvas.create_line(c*CELL,0,c*CELL,H,width=lw)

redraw(canvas)
canvas.bind('<Button-1>', lambda e: on_click(e, canvas))
canvas.bind('<Button-3>', lambda e: on_right_click(e, canvas))

tk.Label(root, text='Arc Puzzle', font=('Courier',13,'bold')).grid(row=0,column=1,pady=(8,2))
tk.Label(root, text='L:cycle  R:clear', font=('Courier',9), fg='gray').grid(row=1,column=1)
tk.Button(root, text='CHECK', font=('Courier',12,'bold'),
          bg='#4a90d9', fg='white', width=16,
          command=check).grid(row=2,column=1,pady=10)

result_text = tk.Text(root, height=30, width=36,
                      font=('Courier',10), state='disabled', bg='#fff8e1',
                      relief='sunken', bd=1)
result_text.grid(row=3,column=1,padx=8,pady=4,sticky='n')

root.mainloop()