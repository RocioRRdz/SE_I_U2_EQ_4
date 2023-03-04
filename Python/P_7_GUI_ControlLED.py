import sys

import serial as conectaX  #para trabajar con Arduino

from PyQt5 import uic, QtWidgets, QtCore

qtCreatorFile = "P_7_GUI_ControlLED.ui"  # Nombre del archivo aquí.

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)

        # Área de los Signals
        #self.txt_puerto.setText("1")
        self.arduino = None
        self.btn_accion.clicked.connect(self.accion)

        self.btn_control_led.clicked.connect(self.control_led)

        #self.segundoPlano = QtCore.QTimer()
        #self.segundoPlano.timeout.connect(self.control)

    # Área de los Slots
    def control_led(self):
        if not self.arduino == None:
            if self.arduino.isOpen():
                texto = self.btn_control_led.text()
                if texto=="PRENDER":
                    self.btn_control_led.setText("APAGAR")
                    action = "1".encode()
                    self.arduino.write(action)
                else:
                    self.btn_control_led.setText("PRENDER")
                    self.arduino.write("0".encode())


    def control(self):
        try:
            valor = self.arduino.readline().decode()
            valor = valor.replace("\r", "")
            valor = valor.replace("\n","")
            print(valor)
        except Exception as error:
            print(error)


    def accion(self):
        try:
            if self.arduino == None:
                puerto = self.txt_puerto.text()
                self.arduino = conectaX.Serial(puerto, baudrate=9600, timeout=1)
                self.btn_accion.setText("DESCONECTAR")
                self.txt_estado.setText("CONECTADO")
                #self.segundoPlano.start(100)
            elif self.arduino.isOpen():
                #self.segundoPlano.stop()
                self.arduino.close()
                self.btn_accion.setText("CONECTAR")
                self.txt_estado.setText("DESCONECTADO")
            else:
                self.arduino.open()
                self.btn_accion.setText("DESCONECTAR")
                self.txt_estado.setText("CONECTADO")
                #self.segundoPlano.start(100)
        except Exception as error:
            print(error)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())

