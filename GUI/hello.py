import PyQt5.QtWidgets as qtw
import PyQt5.QtGui as qtgui

class MainWindow(qtw.QWidget):
    def __init__(self):
        super().__init__()
        # Add a title
        self.setWindowTitle("PyQt5-example-GUI")

        # Set (vertical) layout
        self.setLayout(qtw.QVBoxLayout())

        # Create a label
        my_label = qtw.QLabel("Hello World!")
        # Change font size of label
        my_label.setFont(qtgui.QFont('Times', 18))
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
        my_combo = qtw.QComboBox(self,
            editable=True,
            insertPolicy=qtw.QComboBox.InsertAtBottom)
        # Add items to the combo box
        my_combo.addItems(["Xbox One", "PS3"])
        self.layout().addWidget(my_combo)

        # Create a spin box
        my_spin = qtw.QSpinBox(self,
            value=10,
            maximum=100,
            minimum=0,
            singleStep=5,
            suffix="%")
        # Change font size of spin box
        my_spin.setFont(qtgui.QFont('Helvetica', 24))
        self.layout().addWidget(my_spin)

        # Create a double spin box
        my_spin_double = qtw.QDoubleSpinBox(self,
            value=12.5,
            maximum=84.3,
            minimum=0.25,
            singleStep=2.34,
            suffix="%")
        my_spin_double.setFont(qtgui.QFont('Helvetica', 24))
        self.layout().addWidget(my_spin_double)

        # Create a text box
        my_text = qtw.QTextEdit(self,
            #plainText="This text won't disappear automatically",
            acceptRichText=False,
            #html="<center><em><h2>Heading 2 text</h2></em></center>",
            lineWrapMode=qtw.QTextEdit.FixedColumnWidth,
            lineWrapColumnOrWidth=20,
            placeholderText="Hello World!",
            readOnly=False)
        my_text.setFont(qtgui.QFont('Times', 18))
        self.layout().addWidget(my_text)

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
