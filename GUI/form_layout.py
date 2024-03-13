import PyQt5.QtWidgets as qtw
import PyQt5.QtGui as qtgui

class MainWindow(qtw.QWidget):
    def __init__(self):
        super().__init__()
        # Add a title
        self.setWindowTitle("PyQt5-form_layout-example-GUI")

        # Set form layout
        form_layout = qtw.QFormLayout(self)
        self.setLayout(form_layout)

        # Add widgets
        label_1 = qtw.QLabel("This is a label row")
        label_1.setFont(qtgui.QFont('Helvetica', 24))

        first_name = qtw.QLineEdit(self)
        last_name = qtw.QLineEdit(self)

        # Add rows to app
        form_layout.addRow(label_1)
        form_layout.addRow("First name: ", first_name)
        form_layout.addRow("Last name: ", last_name)
        form_layout.addRow(qtw.QPushButton("Press me!",
            clicked = lambda: pressed()))
        

        # Show the app
        self.show()

        # function called when button is pressed
        def pressed():
            label_1.setText(f'You pressed the button, {first_name.text()} {last_name.text()}')

application = qtw.QApplication([])
mainWindow = MainWindow()

# Run the app
application.exec_()
