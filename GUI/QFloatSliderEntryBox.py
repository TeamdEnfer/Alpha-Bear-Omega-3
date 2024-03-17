from PyQt5 import QtCore, QtWidgets, QtGui
import QFloatSlider

class QFloatSliderEntryBox(QtWidgets.QWidget):
    def __init__(self, slider_orientation=QtCore.Qt.Horizontal, 
                 invert_layout=False, decimals=2, regex=".*", *args, **kargs):
        super(QFloatSliderEntryBox, self).__init__(*args, **kargs)

        # Set (vertical) layout
        if slider_orientation == QtCore.Qt.Horizontal:
            self.layout = QtWidgets.QVBoxLayout()
        else:
            self.layout = QtWidgets.QHBoxLayout()

        # Create a QFloatSlider
        self._slider = QFloatSlider.QFloatSlider(slider_orientation, decimals, *args, **kargs,
            valueChanged = lambda: self.slider_value_changed())

        # Create a validator
        self._regex = QtCore.QRegExp(regex)
        self._validator = QtGui.QRegExpValidator(self._regex, self)

        # Create an entry box
        self._entry = QtWidgets.QLineEdit(self,
            returnPressed = lambda: self.entry_value_changed())
        self._entry.setPlaceholderText('slider value')
        self._entry.setValidator(self._validator)

        # Add widgets to layout
        if invert_layout:
            self.layout.addWidget(self._slider)
            self.layout.addWidget(self._entry)
        else:
            self.layout.addWidget(self._entry)
            self.layout.addWidget(self._slider)
        self.setLayout(self.layout)

    def entry_value_changed(self):
        self._slider.setValue(float(self._entry.text()))

    def slider_value_changed(self):
        self._entry.setText(f'{self._slider.getValue()}')
