from PyQt5 import QtCore, QtWidgets

class QFloatSlider(QtWidgets.QSlider):

    # Create our own signal that we can connect to if necessary
    floatValueChanged = QtCore.pyqtSignal(float)

    # Create a local attribute to convert between float and int values
    _multiple: int

    def __init__(self, orientation=QtCore.Qt.Horizontal, decimals=2, *args, **kargs):
        super(QFloatSlider, self).__init__(orientation, *args, **kargs)
        self._multiple = pow(10, decimals)

    def emitFloatValueChanged(self):
        value = float(super(QFloatSlider, self).value()) / self._multiple
        self.floatValueChanged.emit(value)
    
    def setMinimum(self, value: float) -> None:
        super(QFloatSlider, self).setMinimum(value * self._multiple)
    
    def setMaximum(self, value: float) -> None:
        super(QFloatSlider, self).setMaximum(value * self._multiple)
    
    def setValue(self, value: float) -> None:
        super(QFloatSlider, self).setValue(int(value * self._multiple))
    
    def setSingleStep(self, value: float) -> None:
        super(QFloatSlider, self).setSingleStep(value * self._multiple)

    def getValue(self) -> float:
        return float(super(QFloatSlider, self).value()) / self._multiple
    
    def getSingleStep(self) -> float:
        return float(super(QFloatSlider, self).singleStep()).value() / self._multiple
    
