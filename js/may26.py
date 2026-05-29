import tkinter as tk
import math

ROWS, COLS = 9, 9
CELL = 81

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

# arc_state[r][c]: None = empty, 0-3 = arc orientation
arc_state = [[None]*COLS for _ in range(ROWS)]

# Arc orientations - each defined by (start_angle, extent) in degrees for tkinter arc
# tkinter arc: 0=right, goes counterclockwise
# We draw quarter-circle arcs connecting corner to opposite corner
# orientation 0: top-left corner, curves to bottom-right (NW quadrant arc)
# orientation 1: top-right corner, curves to bottom-left (NE quadrant arc)
# orientation 2: bottom-left corner, curves to top-right (SW quadrant arc)
# orientation 3: bottom-right corner, curves to top-left (SE quadrant arc)

def draw_arc(canvas, r, c, orientation):
    x0 = c * CELL
    y0 = r * CELL
    x1 = x0 + CELL
    y1 = y0 + CELL

    # Each orientation: bounding box of the full circle, start angle, extent
    if orientation == 0:
        # Arc from top-left, quarter circle, fits top-left corner
        bbox = (x0 - CELL, y0 - CELL, x0 + CELL, y0 + CELL)
        start, extent = 270, 90
    elif orientation == 1:
        # Arc from top-right corner
        bbox = (x0, y0 - CELL, x0 + 2*CELL, y0 + CELL)
        start, extent = 180, 90
    elif orientation == 2:
        # Arc from bottom-left corner
        bbox = (x0 - CELL, y0, x0 + CELL, y0 + 2*CELL)
        start, extent = 0, 90
    else:
        # Arc from bottom-right corner
        bbox = (x0, y0, x0 + 2*CELL, y0 + 2*CELL)
        start, extent = 90, 90

    canvas.create_arc(*bbox, start=start, extent=extent,
                      style=tk.ARC, outline='black', width=2.5,
                      tags=('arc', f'arc_{r}_{c}'))

def on_right_click(event, canvas):
    c = event.x // CELL
    r = event.y // CELL
    if 0 <= r < ROWS and 0 <= c < COLS:
        if (r, c) in GREEN:
            return
        arc_state[r][c] = None
        redraw(canvas)
        update_export(export_text)

def redraw(canvas):
    canvas.delete('arc')
    canvas.delete('num')
    for r in range(ROWS):
        for c in range(COLS):
            s = arc_state[r][c]
            if s is not None and (r, c) not in GREEN:
                draw_arc(canvas, r, c, s)
            if (r, c) in GIVEN:
                x = c * CELL + CELL // 2
                y = r * CELL + CELL // 2
                canvas.create_text(x, y, text=str(GIVEN[(r,c)]),
                                   font=('Courier', 13, 'bold'),
                                   tags='num')

def on_click(event, canvas):
    c = event.x // CELL
    r = event.y // CELL
    if 0 <= r < ROWS and 0 <= c < COLS:
        if (r, c) in GREEN:
            return
        cur = arc_state[r][c]
        if cur is None:
            arc_state[r][c] = 0
        elif cur == 3:
            arc_state[r][c] = None
        else:
            arc_state[r][c] = cur + 1
        redraw(canvas)
        update_export(export_text)

def update_export(widget):
    lines = []
    for r in range(ROWS):
        row = []
        for c in range(COLS):
            if (r, c) in GREEN:
                row.append('G')
            elif arc_state[r][c] is not None:
                row.append(str(arc_state[r][c]))
            else:
                row.append('.')
        lines.append(' '.join(row))
    widget.config(state='normal')
    widget.delete('1.0', tk.END)
    widget.insert(tk.END, '\n'.join(lines))
    widget.config(state='disabled')

root = tk.Tk()
root.title('Arc Puzzle')
root.resizable(False, False)

W = COLS * CELL
H = ROWS * CELL

canvas = tk.Canvas(root, width=W, height=H, bg='white', highlightthickness=0)
canvas.grid(row=0, column=0, columnspan=2)

# Draw grid lines
for r in range(ROWS + 1):
    w = 2 if r == 0 or r == ROWS else 0.5
    canvas.create_line(0, r*CELL, W, r*CELL, width=w)
for c in range(COLS + 1):
    w = 2 if c == 0 or c == COLS else 0.5
    canvas.create_line(c*CELL, 0, c*CELL, H, width=w)

# Draw green cells
for (r, c) in GREEN:
    canvas.create_rectangle(c*CELL, r*CELL, (c+1)*CELL, (r+1)*CELL,
                             fill='#7ec87e', outline='')

# Redraw grid lines on top of green
for r in range(ROWS + 1):
    w = 2 if r == 0 or r == ROWS else 0.5
    canvas.create_line(0, r*CELL, W, r*CELL, width=w)
for c in range(COLS + 1):
    w = 2 if c == 0 or c == COLS else 0.5
    canvas.create_line(c*CELL, 0, c*CELL, H, width=w)

redraw(canvas)
canvas.bind('<Button-1>', lambda e: on_click(e, canvas))
canvas.bind('<Button-3>', lambda e: on_right_click(e, canvas))

label = tk.Label(root, text='Click white cells to cycle arc (0→1→2→3→clear)',
                 font=('Courier', 10), fg='gray')
label.grid(row=1, column=0, columnspan=2, pady=4)

export_label = tk.Label(root, text='Arc state:', font=('Courier', 10, 'bold'))
export_label.grid(row=2, column=0, columnspan=2, sticky='w', padx=8)

export_text = tk.Text(root, height=ROWS, width=COLS*2+2,
                      font=('Courier', 11), state='disabled', bg='#f5f5f5')
export_text.grid(row=3, column=0, columnspan=2, padx=8, pady=4)

update_export(export_text)

root.mainloop()