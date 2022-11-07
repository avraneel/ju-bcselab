from tkinter.filedialog import *
import tkinter as tk

root = tk.Tk()
root.geometry("700x700")
root.title("My notepad")
root.config(bg = "white")

# For Edit menu :
def cut():
    text_area.clipboard_clear()
    text_area.clipboard_append(text_area.selection_get())
    text_area.delete(tk.SEL_FIRST, tk.SEL_LAST)

def copy():
    text_area.clipboard_clear()
    text_area.clipboard_append(text_area.selection_get())

def paste():
    text_area.insert(tk.INSERT, text_area.clipboard_get())

def undo():
    text_area.edit_undo()

def redo():
    text_area.edit_redo()

menu_bar = tk.Menu(root)

# Edit Menu :
edit_menu = tk.Menu(menu_bar, tearoff = 0)
edit_menu.add_command(label = "Cut", command = cut)
edit_menu.add_command(label = "Copy", command = copy)
edit_menu.add_command(label = "Paste", command = paste)
menu_bar.add_cascade(label = "Edit", menu = edit_menu)
edit_menu.add_separator()
edit_menu.add_command(label = "Undo", command = undo)
edit_menu.add_command(label = "Redo", command = redo)

root.config(menu = menu_bar)

text_area = tk.Text(root, width = 50, height = 20, bg = "white", font = ("Times New Roman", 12), undo = True, autoseparators=True, maxundo = -1) 
text_area.pack(expand = True, fill = "both", padx = 5, pady = 5)

root.mainloop()
