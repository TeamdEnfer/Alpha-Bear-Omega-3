import PyQt5.QtWidgets as qtw
import PyQt5.QtGui as qtgui

class MainWindow(qtw.QWidget):
    def __init__(self):
        super().__init__()
        # Add a title
        self.setWindowTitle("Alpha-Bear-Omega-3 GUI")

        # Set layout
        self.setLayout(qtw.QVBoxLayout())

        # Create a label
        my_label = qtw.QLabel("Hello World!")
        # Change font size of label
        my_label.setFont(qtgui.QFont('Fira Code', 18))
        self.layout().addWidget(my_label)

        # Create an entry box
        #my_entry = qtw.QLineEdit()
        #my_entry.setObjectName("name_field")
        #my_entry.setText("Enter your name")
        #self.layout().addWidget(my_entry)

        # Create a button
        my_button = qtw.QPushButton("Press me!",
            clicked = lambda: pressed())
        self.layout().addWidget(my_button)

        # Create a combo box
        my_combo = qtw.QComboBox(self)
        # Add items to the combo box
        my_combo.addItems(["Xbox One", "PS3"])
        self.layout().addWidget(my_combo)

        # Show the app
        self.show()

        # function called when button is pressed
        def pressed():
            # Add name to label
            my_label.setText(f'Controller: {my_combo.currentText()}')
            # Clear the entry box
            #my_entry.setText("")

application = qtw.QApplication([])
mainWindow = MainWindow()

# Run the app
application.exec_()
