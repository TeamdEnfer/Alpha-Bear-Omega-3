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


        self.show()

application = qtw.QApplication([])
mainWindow = MainWindow()

# Run the app
application.exec_()
