import tkinter as tk
from collections import deque
import math
LARGE = math.pi / 4        # ~0.785
SMALL = 1 - math.pi / 4   # ~0.215

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
    if s == 0:   return {'T','L'}, {'B','R'}
    elif s == 1: return {'T','R'}, {'B','L'}
    elif s == 2: return {'B','L'}, {'T','R'}
    else:        return {'B','R'}, {'T','L'}

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

def compute_regions():
    adj = build_graph()
    visited, _ = flood_fill(adj)
    area = {}

    for (r,c,h), rid in visited.items():
        s = arc_state[r][c]
        if s is None or (r,c) in GREEN:
            if h == 0:
                area[rid] = area.get(rid, 0) + 1
        else:
            # h0 owns the corner = small piece, h1 = large piece
            contrib = SMALL if h == 0 else LARGE
            area[rid] = area.get(rid, 0) + contrib
    clue_region = {}
    for (r,c) in GIVEN:
        if (r,c,0) in visited:
            clue_region[(r,c)] = visited[(r,c,0)]
    # conflicts: two clues in same region with different values
    region_clues = {}
    for (r,c),rid in clue_region.items():
        region_clues.setdefault(rid,[]).append((r,c))
    conflicts = []
    for rid, cells in region_clues.items():
        vals = [GIVEN[cell] for cell in cells]
        if len(set(vals)) > 1:
            conflicts.append(f"CONFLICT: {cells} same region, scores {vals}")
    return visited, area, clue_region, conflicts

def check():
    visited, area, clue_region, conflicts = compute_regions()
    lines = ["── regions ──────────────────"]
    for (r,c), expected in sorted(GIVEN.items()):
        rid = clue_region.get((r,c))
        a = area.get(rid,'?') if rid is not None else '?'
        lines.append(f"({r},{c}) exp={expected:4d}  area={a}")
    lines.append("")
    lines.append("── issues ───────────────────")
    issues = []
    for rid,a in area.items():
        if isinstance(a,float) and a != int(a):
            issues.append(f"non-int area {a} in region {rid}")
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

# left: canvas
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

# right: controls
tk.Label(root, text='Arc Puzzle', font=('Courier',13,'bold')).grid(row=0,column=1,columnspan=2,pady=(8,2))
tk.Label(root, text='L-click: cycle  R-click: clear', font=('Courier',9), fg='gray').grid(row=1,column=1,columnspan=2)

tk.Button(root, text='CHECK', font=('Courier',12,'bold'),
          bg='#4a90d9', fg='white', width=16,
          command=check).grid(row=2,column=1,columnspan=2,pady=10)

result_text = tk.Text(root, height=28, width=34,
                      font=('Courier',10), state='disabled', bg='#fff8e1',
                      relief='sunken', bd=1)
result_text.grid(row=3,column=1,columnspan=2,padx=8,pady=4,sticky='n')

root.mainloop()