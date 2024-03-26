#!/usr/bin/env python3
import time
from tkinter import *

root = Tk()
root.title('Visualizer for task "disegno"')
root.geometry('1024x1128')

# Exit on CTRL+W.
def quit_root(unused_event):
    root.quit()
root.bind('<Control-w>', quit_root)

L = 10                  # Default to 10. Quite arbitrary.
UNIT = 50               # Side length of a unit square.
SIDE_LENGTH = UNIT * L  # Side length of the whole square.
HALF_SIDE = 8           # Half-side length of the tiny intersection squares.

class LineManager:
    def __init__(self):
        self.line_id = None
        self.eraser_id = None

    def find_second_endpoint(self, x, y):
        rounded_x = UNIT * (x // UNIT)
        if x - rounded_x > rounded_x + UNIT - x:
            rounded_x += UNIT
        rounded_y = UNIT * (y // UNIT)
        if y - rounded_y > rounded_y + UNIT - y:
            rounded_y += UNIT
        x, y = rounded_x, rounded_y

        x2, y2 = None, None
        if self.y1 == 0 or self.y1 == SIDE_LENGTH or abs(x - self.x1) <= abs(y - self.y1):
            x2, y2 = self.x1, y
        else:
            x2, y2 = x, self.y1
        x2 = max(0, min(canvas.winfo_width(), x2))
        y2 = max(0, min(canvas.winfo_height(), y2))

        return x2, y2

    # Find the intersection "dot" that the cursor hovers, if any.
    def get_hovered_dot(self, x, y):
        dots = [id for id in canvas.find_overlapping(x-3, y-3, x+3, y+3) if 'dot' in canvas.gettags(id)]
        if len(dots) == 0:
            return None
        return dots[0]

    # Create a new line on left-mouse-button press.
    def create_line(self, event):
        x, y = event.x, event.y
        dot = self.get_hovered_dot(x, y)
        if not dot: return
        dx, dy, _, _ = canvas.coords(dot)
        x, y = dx + HALF_SIDE, dy + HALF_SIDE
        if dx == 0: x = 0 # Left side of the square.
        if dy == 0: y = 0 # Bottom side of the square.
        self.x1, self.y1 = x, y
        self.x2, self.y2 = x, y
        self.line_id = canvas.create_line(x, y, x, y, fill='#00aa00', width=4)
        canvas.addtag_withtag('line', self.line_id)

    # Update the free endpoint of the current line on mouse movement.
    def update_line(self, event):
        if not self.line_id:
            return
        x, y = event.x, event.y
        x2, y2 = self.find_second_endpoint(x, y)
        self.x2, self.y2 = x2, y2
        canvas.coords(self.line_id, self.x1, self.y1, x2, y2)

    # On mouse-left-button release.
    def preserve_line(self, unused_event):
        if not self.line_id:
            return
        canvas.itemconfigure(self.line_id, fill='#aa0000', activefill='#ff0000')
        self.line_id = None

    # The following three actions are controlled by the right mouse button.
    def hide_cursor(self, unused_event):
        canvas.configure(cursor='none')

    def delete_lines(self, event):
        x, y = event.x, event.y
        if not self.eraser_id:
            self.eraser_id = canvas.create_rectangle(x-6, y-6, x+6, y+6, fill='#ffffff', outline='#000000')
        else:
            canvas.coords(self.eraser_id, x-6, y-6, x+6, y+6)
        lines = [id for id in canvas.find_overlapping(*canvas.coords(self.eraser_id)) if 'line' in canvas.gettags(id)]
        for line in lines:
            canvas.delete(line)

    def remove_eraser(self, unused_event):
        if not self.eraser_id:
            return
        canvas.configure(cursor='')
        canvas.delete(self.eraser_id)
        self.eraser_id = None

    def change_cursor_on_dot(self, event):
        dot = self.get_hovered_dot(event.x, event.y)
        if dot:
            canvas.configure(cursor='hand2')
        else:
            canvas.configure(cursor='')

# Check that the value of L input by the user is a non-negative integer.
# The lower- and upper-bound validation is performed by the button press action.
def validate_ell_text(text: str):
    ell_error.configure(text='')
    if len(text) > 2: return False
    if len(text) > 1 and text[0] == '0':
        return False
    return len([c for c in text if not ('0' <= c <= '9')]) == 0

def on_ell_button_click(unused_event=None):
    if len(ell_entry.get()) == 0:
        inputL = L
    else:
        inputL = int(ell_entry.get())
    if inputL < 2 or inputL > 15:
        ell_error.configure(text='L must lie between 2 and 15 inclusive')
        return
    reset(inputL)

ell_frame = Frame(root, bd=0)
ell_frame.pack(pady=50)
ell_label = Label(ell_frame, text='L =', font=('Arial', 20), padx=10, bd=0)
ell_label.pack(side=LEFT)
ell_entry = Entry(ell_frame, font=('Courier New', 20), width=3, justify=CENTER,
                  validate='all', validatecommand=(ell_frame.register(validate_ell_text), '%P'))
ell_entry.pack(side=LEFT)
ell_button = Button(ell_frame, text='Reset', font=('Arial', 16), bg='#ffffff', activebackground='#eeeeff', command=on_ell_button_click)
ell_button.pack(side=LEFT, padx=20)
ell_entry.bind('<Return>', on_ell_button_click)
ell_error = Label(ell_frame, text='', font=('Arial', 16, 'bold'), width=35, anchor='w', bd=0, fg='#ff0000')
ell_error.pack(side=LEFT)

# Validates the user drawing and returns:
#   - the list of segments (as quadruples) and True if it's valid;
#   - the list of "free" endpoints (as pairs) and False if it's invalid.
# Note that the drawing can be invalid even if there are no free endpoints.
def get_segments(grid) -> (list, bool):
    def is_valid_endpoint(x, y):
        horizontal = int(grid[x-1][y][0]) + int(grid[x][y][0])
        vertical = int(grid[x][y-1][1]) + int(grid[x][y][1])
        return horizontal + vertical != 1 # Trust me.

    invalid_endpoints = []
    for x in range(1, L):
        for y in range(1, L):
            if not is_valid_endpoint(x, y):
                invalid_endpoints.append((x, y))

    if len(invalid_endpoints) > 0:
        return invalid_endpoints, False

    segments = []
    start = None
    for y in range(1, L):
        for x in range(L+1):
            if start is not None and (x == L or grid[x][y-1][1] or grid[x][y][1]):
                if start == 0 and x == L:
                    return [], False # A full-length horizontal segment with no intersections.
                segments.append((start, y, x, y))
                start = None
            if start is None and x < L and grid[x][y][0]:
                start = x
    start = None
    for x in range(1, L):
        for y in range(L+1):
            if start is not None and (y == L or grid[x-1][y][0] or grid[x][y][0]):
                if start == 0 and y == L:
                    return [], False # A full-length vertical segment with no intersections.
                segments.append((x, start, x, y))
                start = None
            if start is None and y < L and grid[x][y][1]:
                start = y

    return segments, True

def generate_input():
    lines = canvas.find_withtag('line')

    # grid[x][y][0] = "is the unit segment (x,y)-(x+1,y) drawn?"
    # grid[x][y][1] = "is the unit segment (x,y)-(x,y+1) drawn?"
    grid = [[[False, False] for _ in range(L)] for _ in range(L)]

    for line in lines:
        x1, y1, x2, y2 = map(lambda x: round(x/UNIT), canvas.coords(line))
        y1, y2 = L - y1, L - y2
        if y1 == y2:
            x1, x2 = min(x1, x2), max(x1, x2)
            for x in range(x1, x2):
                grid[x][y1][0] = True
        elif x1 == x2:
            y1, y2 = min(y1, y2), max(y1, y2)
            for y in range(y1, y2):
                grid[x1][y][1] = True

    res, ok = get_segments(grid)
    if not ok:
        display_input_error('Invalid drawing  :(', res) # This also highlights the free endpoints.
        return
    if len(res) < 4:
        display_input_error('There must be at least 4 segments  :o', [])
        return
    create_input_window(res)

def display_input_error(message, invalid_endpoints):
    generate_input_error.configure(text=message)
    # Draw a circle around every invalid endpoint.
    RADIUS = 12
    for x, y in invalid_endpoints:
        x, y = x*UNIT, SIDE_LENGTH - y*UNIT
        circle = canvas.create_oval(x - RADIUS, y - RADIUS, x + RADIUS, y + RADIUS,
                                    outline='#ff8500', width=5)
        canvas.addtag_withtag('circle', circle)

def remove_input_error(unused_event):
    if generate_input_error.cget('text') == '':
        return
    generate_input_error.configure(text='')
    for circle in canvas.find_withtag('circle'):
        canvas.delete(circle)

def create_input_window(segments):
    input_window = Toplevel(root)
    input_window.title('Generated input')
    input_window.geometry('500x800')
    input_window.resizable(0, 0) # Fixed window size.

    input_content = f'{len(segments)} {L}\n' + '\n'.join([' '.join(map(str, segment)) for segment in segments])

    def copy_input():
        input_window.clipboard_clear()
        input_window.clipboard_append(input_content + '\n')
        input_window.update()

    copy_button = Button(input_window, text='COPY', font=('Arial', 14),
                         bg='#ffffff', activebackground='#eeeeff', command=copy_input)
    copy_button.pack(anchor='w', padx=20, pady=20)

    # Use a disabled Text widged to make it possible to select the text.
    text = Text(input_window, font=('Courier New', 14), relief='flat', bg=input_window.cget('bg'), highlightthickness=0, wrap='word')
    text.insert(1.0, input_content)
    text.pack(padx=20, pady=20)
    text.configure(state='disabled')

root.bind('<Button>', remove_input_error)

generate_input_button = Button(root, text='Generate input!', font=('Arial', 22),
                               fg='#339933', bg='#ddffdd', activeforeground='#ddffdd', activebackground='#339933',
                               command=generate_input)
generate_input_button.pack(pady=20)
generate_input_error = Label(root, text='', font=('Arial', 16, 'bold'), bd=0, fg='#ff0000')
generate_input_error.pack()

canvas = Canvas(root, width=SIDE_LENGTH, height=SIDE_LENGTH, background='#ffffff', closeenough=3)
lm = LineManager()

def setup_canvas(w: Canvas):
    w.pack(padx=20, pady=20)
    for x in range(0, SIDE_LENGTH+1, UNIT):
        for y in range(0, SIDE_LENGTH+1, UNIT):
            if (x == 0 or x == SIDE_LENGTH) and (y == 0 or y == SIDE_LENGTH):
                continue
            x1, y1 = max(0, x - HALF_SIDE), max(0, y - HALF_SIDE)
            x2, y2 = min(SIDE_LENGTH, x + HALF_SIDE), min(SIDE_LENGTH, y + HALF_SIDE)
            id = w.create_rectangle(x1, y1, x2, y2, fill='#bbbbbb', activefill='#333333', width=0)
            w.addtag_withtag('dot', id)
    w.bind('<Button-1>', lm.create_line)
    w.bind('<B1-Motion>', lm.update_line)
    w.bind('<B1-ButtonRelease>', lm.preserve_line)
    w.bind('<Button-3>', lm.hide_cursor)
    w.bind('<Button-3>', lm.delete_lines, add='+')
    w.bind('<B3-Motion>', lm.delete_lines)
    w.bind('<B3-ButtonRelease>', lm.remove_eraser)
    w.bind('<Motion>', lm.change_cursor_on_dot, add='+')

def reset(newL):
    globals()['L'] = newL
    globals()['SIDE_LENGTH'] = UNIT * L
    lm.__init__()
    canvas.destroy()
    globals()['canvas'] = Canvas(root, width=SIDE_LENGTH, height=SIDE_LENGTH, background='#ffffff', closeenough=3)
    setup_canvas(canvas)

setup_canvas(canvas)

if __name__ == '__main__':
    root.mainloop()
