import PySimpleGUI as pg

# Step 1: Set Theme
#pg.theme("DarkAmber")

# Step 2: Create Layout
layout = [
    [pg.Text("Cyber ford project")],
    [pg.InputText()],
    [pg.Button("Ok"), pg.Button("Cancel")]
]

# Step 3: Create Window
str_header = "Cyber Ford Test GUI"
window = pg.Window(str_header, layout)

# Step 4: Event Loop
while True:
    event, values = window.read()
    if event == "Cancel" or event == pg.WIN_CLOSED:
        break
    else:
        print(values[0])

# Step 5: Close Window
window.close()