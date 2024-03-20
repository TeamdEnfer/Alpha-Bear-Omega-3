from PyQt5 import QtCore as qtc
from PyQt5 import QtGui as qtgui
from PyQt5 import QtWidgets as qtw
import qdarktheme
import rospy
from std_msgs.msg import Bool, Int8, Float32
import QFloatSlider, QFloatSliderEntryBox



class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.setWindowTitle("servo-zeroing-GUI")
        MainWindow.resize(576, 720)
        MainWindow.setAutoFillBackground(False)

        # Create central widget
        self.central_widget = qtw.QWidget(MainWindow)
        self.central_widget.setObjectName("central_widget")
        
        # Set font
        qtgui.QFontDatabase.addApplicationFont("FiraCode-Regular.ttf")
        qtgui.QFontDatabase.addApplicationFont("FiraCode-Bold.ttf")
        font = qtgui.QFont()
        font.setFamily("Fira Code")
        font.setPointSize(14)

        # Create button that switches between controllers (i.e modes)
        self.control_switch_button = qtw.QPushButton(self.central_widget)
        self.control_switch_button.setGeometry(qtc.QRect(88, 500, 300, 40))
        self.control_switch_button.setFont(font)
        self.control_switch_button.setObjectName("control_switch_button")
        self.control_switch_button.setCheckable(True)
        self.control_switch_button.clicked.connect(self.switch_control_clicked)
        self.control_switch_button.clicked.connect(self.change_control_switch_color)
        self.control_switch_button.setText("Controller: CHAMP")

        # Create a label showing which leg is currently being controlled
        self.leg_selection_label = qtw.QLabel(self.central_widget)
        self.leg_selection_label.setGeometry(qtc.QRect(88, 40, 400, 40))
        self.leg_selection_label.setFont(font)
        self.leg_selection_label.setObjectName("leg_selection_label")
        self.leg_selection_label.setText("Current leg: None")

        # Create a warning label
        self.warning_label = qtw.QLabel(self.central_widget)
        self.warning_label.setGeometry(qtc.QRect(38, 480, 500, 40))
        self.warning_label.setFont(qtgui.QFont('Fira Code Bold', 14))
        self.warning_label.setAlignment(qtc.Qt.AlignCenter)
        self.warning_label.setObjectName("warning_label")
        
        # Create a grid layout for controls
        self.control_panel = qtw.QWidget(self.central_widget)
        self.control_panel.setGeometry(qtc.QRect(38, 80, 500, 360))
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
        
        # Create a float slider for the servo that controls the shoulder
        self.shoulder_slider_entry = QFloatSliderEntryBox.QFloatSliderEntryBox(
            qtc.Qt.Horizontal,
            invert_layout=False,
            id=0,
            decimals=2,
            regex="\-?\d{1,2}\.?\d{0,2}")
        self.shoulder_slider_entry._slider.setMinimum(-45.0)
        self.shoulder_slider_entry._slider.setMaximum(45.0)
        self.shoulder_slider_entry._slider.setSingleStep(0.05)
        self.shoulder_slider_entry._slider.setFont(font)
        self.shoulder_slider_entry._slider.valueChanged.connect(lambda: self.servo_update_cmd(self.shoulder_slider_entry._slider.getID(), self.shoulder_slider_entry._slider.getValue()))
        self.shoulder_slider_entry.setObjectName('shoulder_slider_entry')
        self.shoulder_slider_entry._entry.setFont(font)
        self.gridLayout.addWidget(self.shoulder_slider_entry, 1, 1, 1, 1)

        # Create a float slider for the servo that controls the femur
        self.femur_slider_entry = QFloatSliderEntryBox.QFloatSliderEntryBox(
            qtc.Qt.Horizontal,
            invert_layout=False,
            id=1,
            decimals=2,
            regex="\-?\d{1,2}\.?\d{0,2}")
        self.femur_slider_entry._slider.setMinimum(-10.0)
        self.femur_slider_entry._slider.setMaximum(90.0)
        self.femur_slider_entry._slider.setSingleStep(0.05)
        self.femur_slider_entry._slider.setFont(font)
        self.femur_slider_entry._slider.valueChanged.connect(lambda: self.servo_update_cmd(self.femur_slider_entry._slider.getID(), self.femur_slider_entry._slider.getValue()))
        self.femur_slider_entry.setObjectName('shoulder_slider_entry')
        self.femur_slider_entry._entry.setFont(font)
        self.gridLayout.addWidget(self.femur_slider_entry, 2, 1, 1, 1)

        # Create a float slider for the servo that controls the tibia
        self.tibia_slider_entry = QFloatSliderEntryBox.QFloatSliderEntryBox(
            qtc.Qt.Horizontal,
            invert_layout=False,
            id=2,
            decimals=2,
            regex="\-?\d{1,2}\.?\d{0,2}")
        self.tibia_slider_entry._slider.setMinimum(-10.0)
        self.tibia_slider_entry._slider.setMaximum(90.0)
        self.tibia_slider_entry._slider.setSingleStep(0.05)
        self.tibia_slider_entry._slider.setFont(font)
        self.tibia_slider_entry._slider.valueChanged.connect(lambda: self.servo_update_cmd(self.tibia_slider_entry._slider.getID(), self.tibia_slider_entry._slider.getValue()))
        self.tibia_slider_entry.setObjectName('shoulder_slider_entry')
        self.tibia_slider_entry._entry.setFont(font)
        self.gridLayout.addWidget(self.tibia_slider_entry, 3, 1, 1, 1)

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
            text="Change Leg")
        self.leg_selection_button.clicked.connect(self.update_leg_id)
        self.leg_selection_button.clicked.connect(self.leg_selection_update)
        self.leg_selection_button.setObjectName("leg_selection_button")
        self.leg_selection_button.setFont(font)
        self.gridLayout.addWidget(self.leg_selection_button, 0, 2, 1, 1)

        # Create buttons for zeroing servos
        self.set_zero_shoulder_button = qtw.QPushButton(self.control_panel,
            text="Set Zero",
            clicked = lambda: self.servo_update_zero(0, self.shoulder_slider_entry._slider.getValue()))
        self.set_zero_shoulder_button.setObjectName("set_zero_shoulder_button")
        self.set_zero_shoulder_button.setFont(font)
        self.gridLayout.addWidget(self.set_zero_shoulder_button, 1, 2, 1, 1)

        self.set_zero_femur_button = qtw.QPushButton(self.control_panel,
            text="Set Zero",
            clicked = lambda: self.servo_update_zero(1, self.femur_slider_entry._slider.getValue()))
        self.set_zero_femur_button.setObjectName("set_zero_femur_button")
        self.set_zero_femur_button.setFont(font)
        self.gridLayout.addWidget(self.set_zero_femur_button, 2, 2, 1, 1)

        self.set_zero_tibia_button = qtw.QPushButton(self.control_panel,
            text="Set Zero",
            clicked = lambda: self.servo_update_zero(2, self.tibia_slider_entry._slider.getValue()))
        self.set_zero_tibia_button.setObjectName("set_zero_tibia_button")
        self.set_zero_tibia_button.setFont(font)
        self.gridLayout.addWidget(self.set_zero_tibia_button, 3, 2, 1, 1)

        MainWindow.setCentralWidget(self.central_widget)
        self.control_switch_button
        self.leg_selection_label

        qtc.QMetaObject.connectSlotsByName(MainWindow)

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
    
    def servo_update_cmd(self, joint_id: int, cmd: float):
        if self.control_switch_button.isChecked():
            servo_id_pub.publish(self.update_servo_id(joint_id))
            servo_cmd_pub.publish(cmd)
        else:
            self.controller_error()

    def servo_update_zero(self, joint_id: int, zero: float):
        if self.control_switch_button.isChecked():
            id = self.update_servo_id(joint_id)
            servo_id_pub.publish(id)
            servo_cmd_pub.publish(zero)
            self.warning_label.setVisible(True)
            self.warning_label.setStyleSheet("background-color: green; \
                                    border: 2px solid black;")
            self.warning_label.setText(f'Command has been sent for servo {id}.')
        else:
            self.controller_error()

    def clear_error_msg(self):
        self.warnin_label.setVisible(False)
        self.warning_label.setText("")

    def controller_error(self):
        self.warning_label.setVisible(True)
        self.warning_label.setStyleSheet("background-color: red; \
                                                    border: 2px solid black;")
        self.warning_label.setText("Error: Controller must be set to 'Manual'!")
    
    def update_leg_id(self):
        self._legID = self.leg_selection_box.currentIndex()
    
    def update_servo_id(self, joint_id: int) -> int:
        return servo_id[self._legID][joint_id]

    def change_control_switch_color(self):
        if self.control_switch_button.isChecked():
            self.control_switch_button.setStyleSheet("background-color : orange")
        else:
            self.control_switch_button.setStyleSheet("background-color : grey")


if __name__ == "__main__":
    import sys
    app = qtw.QApplication(sys.argv)
    # Apply the dark theme
    qdarktheme.setup_theme()

    # Create a publisher for control switching flag
    control_switch_flag_pub = rospy.Publisher('control_switch_flag', Bool, queue_size=1)
    servo_id_pub = rospy.Publisher('servo_id_topic', Int8, queue_size=1)
    servo_cmd_pub = rospy.Publisher('servo_cmd_topic', Float32, queue_size=5)
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
