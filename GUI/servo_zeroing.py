from PyQt5 import QtCore
from PyQt5 import QtGui as qtgui
from PyQt5 import QtWidgets as qtw
import qdarktheme
import rospy
from std_msgs.msg import Bool, Int8, Float32



class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setWindowTitle("servo-zeroing-GUI")
        MainWindow.resize(480, 640)
        MainWindow.setAutoFillBackground(False)

        # Create central widget
        self.central_widget = qtw.QWidget(MainWindow)
        self.central_widget.setObjectName("central_widget")
        
        # Set font
        font = qtgui.QFont()
        font.setFamily("Ubuntu Mono")
        font.setPointSize(14)

        # Create button that switches between controllers (i.e modes)
        self.control_switch_button = qtw.QPushButton(self.central_widget)
        self.control_switch_button.setGeometry(QtCore.QRect(140, 400, 200, 40))
        self.control_switch_button.setFont(font)
        self.control_switch_button.setObjectName("control_switch_button")
        self.control_switch_button.setCheckable(True)
        self.control_switch_button.clicked.connect(self.switch_control_clicked)
        self.control_switch_button.setText("Controller: CHAMP")

        # Create a label showing which leg is currently being controlled
        self.leg_selection_label = qtw.QLabel(self.central_widget)
        self.leg_selection_label.setGeometry(QtCore.QRect(20, 40, 280, 36))
        self.leg_selection_label.setFont(font)
        self.leg_selection_label.setObjectName("leg_selection_label")
        self.leg_selection_label.setText("Current leg: None")

        # Create a warning label
        self.warning_label = qtw.QLabel(self.central_widget)
        self.warning_label.setGeometry(QtCore.QRect(20, 480, 440, 36))
        self.warning_label.setFont(qtgui.QFont('Ubuntu Mono Bold', 14))
        self.warning_label.setAlignment(QtCore.Qt.AlignCenter)
        self.warning_label.setObjectName("warning_label")
        
        # Create a grid layout for controls
        self.control_panel = qtw.QWidget(self.central_widget)
        self.control_panel.setGeometry(QtCore.QRect(20, 80, 440, 320))
        self.control_panel.setObjectName("control_panel")
        self.gridLayout = qtw.QGridLayout(self.control_panel)
        self.gridLayout.setContentsMargins(2, 2, 2, 2)
        self.gridLayout.setObjectName("gridLayout")

        # Create a combo box for selecting the leg controlled
        self.leg_selection_box = qtw.QComboBox(self.central_widget)
        self.leg_selection_box.setObjectName("leg_selection_box")
        self.leg_selection_box.addItems(["Avant Gauche", "Avant Droite", \
                                "Arrière Gauche", "Arrière Droite"])
        self.leg_selection_box.setFont(font)
        self.gridLayout.addWidget(self.leg_selection_box, 0, 0, 1, 2)
        
        # Create a spin box for the servo that controls the shoulder
        self.shoulder_spin = qtw.QDoubleSpinBox(self.central_widget,
            value=0,
            maximum=45.0,
            minimum=(-45.0),
            singleStep=0.5,
            suffix=" deg")
        self.shoulder_spin.setObjectName("shoulder_spin")
        self.shoulder_spin.setFont(font)
        self.gridLayout.addWidget(self.shoulder_spin, 1, 1, 1, 1)

        # Create a spin box for the servo that controls the femur
        self.femur_spin = qtw.QDoubleSpinBox(self.central_widget,
            value=45,
            maximum=90.0,
            minimum=0.0,
            singleStep=0.5,
            suffix=" deg")
        self.femur_spin.setObjectName("femur_spin")
        self.femur_spin.setFont(font)
        self.gridLayout.addWidget(self.femur_spin, 2, 1, 1, 1)

        # Create a spin box for the servo that controls the tibia
        self.tibia_spin = qtw.QDoubleSpinBox(self.central_widget,
            value=45,
            maximum=90.0,
            minimum=0.0,
            singleStep=0.5,
            suffix=" deg")
        self.tibia_spin.setObjectName("tibia_spin")
        self.tibia_spin.setFont(font)
        self.gridLayout.addWidget(self.tibia_spin, 3, 1, 1, 1)

        # Create labels for spin boxes
        self.shoulder_label = qtw.QLabel("épaule: ")
        self.shoulder_label.setFont(font)
        self.gridLayout.addWidget(self.shoulder_label, 1, 0, 1, 1)

        self.femur_label = qtw.QLabel("fémur: ")
        self.femur_label.setFont(font)
        self.gridLayout.addWidget(self.femur_label, 2, 0, 1, 1)

        self.tibia_label = qtw.QLabel("tibia: ")
        self.tibia_label.setFont(font)
        self.gridLayout.addWidget(self.tibia_label, 3, 0, 1, 1)

        # Create button for switching leg control
        self.leg_selection_button = qtw.QPushButton(self.control_panel,
            text="Change Leg",
            clicked = lambda: self.leg_selection_update())
        self.leg_selection_button.setObjectName("leg_selection_button")
        self.leg_selection_button.setFont(font)
        self.gridLayout.addWidget(self.leg_selection_button, 0, 2, 1, 1)

        # Create buttons for zeroing servos
        self.set_zero_shoulder_button = qtw.QPushButton(self.control_panel,
            text="Set Zero",
            clicked = lambda: self.servo_update(0, self.shoulder_spin.value()))
        self.set_zero_shoulder_button.setObjectName("set_zero_shoulder_button")
        self.set_zero_shoulder_button.setFont(font)
        self.gridLayout.addWidget(self.set_zero_shoulder_button, 1, 2, 1, 1)

        self.set_zero_femur_button = qtw.QPushButton(self.control_panel,
            text="Set Zero",
            clicked = lambda: self.servo_update(1, self.femur_spin.value()))
        self.set_zero_femur_button.setObjectName("set_zero_femur_button")
        self.set_zero_femur_button.setFont(font)
        self.gridLayout.addWidget(self.set_zero_femur_button, 2, 2, 1, 1)

        self.set_zero_tibia_button = qtw.QPushButton(self.control_panel,
            text="Set Zero",
            clicked = lambda: self.servo_update(2, self.tibia_spin.value()))
        self.set_zero_tibia_button.setObjectName("set_zero_tibia_button")
        self.set_zero_tibia_button.setFont(font)
        self.gridLayout.addWidget(self.set_zero_tibia_button, 3, 2, 1, 1)

        MainWindow.setCentralWidget(self.central_widget)
        self.control_switch_button
        self.leg_selection_label


        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def switch_control_clicked(self):
        if self.control_switch_button.isChecked():
            self.control_switch_button.setText("Controller: Manual")
        else:
            self.control_switch_button.setText("Controller: CHAMP")
        
        control_switch_flag_pub.publish(control_switch_flag)

        # Clear the warning label
        self.warning_label.clear()
        self.warning_label.setVisible(False)
    
    def leg_selection_update(self):
        if self.control_switch_button.isChecked():
            self.leg_selection_label.setText(f'Current leg: {self.leg_selection_box.currentText()}')
        else:
            self.leg_selection_label.setText("Current leg: None")
    
    def servo_update(self, joint_id: int, zero: float):
        if self.control_switch_button.isChecked():
            id = servo_id[self.leg_selection_box.currentIndex()][joint_id]
            servo_id_pub.publish(id)
            servo_set_zero_pub.publish(zero)
            self.warning_label.setVisible(True)
            self.warning_label.setStyleSheet("background-color: green; \
                                    border: 2px solid black;")
            self.warning_label.setText(f'Command has been sent for servo {id}.')
        else:
            self.warning_label.setVisible(True)
            self.warning_label.setStyleSheet("background-color: red; \
                                    border: 2px solid black;")
            self.warning_label.setText("Error: Controller must be set to 'Manual'!")
        
    
    def acknowledge_cmd():
        return



if __name__ == "__main__":
    import sys
    app = qtw.QApplication(sys.argv)
    # Apply the dark theme
    qdarktheme.setup_theme()

    # Create a publisher for control switching flag
    control_switch_flag_pub = rospy.Publisher('control_switch_flag', Bool, queue_size=1)
    servo_id_pub = rospy.Publisher('servo_id_topic', Int8, queue_size=1)
    servo_set_zero_pub = rospy.Publisher('servo_zero_topic', Float32, queue_size=1)
    rospy.init_node('GUI')

    MainWindow = qtw.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)

    # Create a boolean flag for control switching
    control_switch_flag = ui.control_switch_button.isChecked()

    # Create an array for servo IDs
    servo_id = [[0,1,2], [3,4,5], [6,7,8], [9,10,11]]
    
    MainWindow.show()

    sys.exit(app.exec_())
