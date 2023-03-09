import sys
import serial as conecta

from PyQt5 import uic, QtWidgets, QtCore

qtCreatorFile = "P_11_SerializacionActuadores"  # Nombre del archivo aquí.

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)

        # Área de los Signals
        #self.txt_puerto.setText("COM3")

        self.btn_accion.clicked.connect(self.accion)
        self.arduino = None

        self.segundoPlano = QtCore.QTimer()
        self.segundoPlano.timeout.connect(self.control)

        self.btn_control_led.setText("ENVIAR") #ENVIAR CADENA ACTUADORES
        self.btn_control_led.clicked.connect(self.control_led)
        #self.btn_control_led.setEnabled(False)

    # Área de los Slots
    def control_led(self):
        if not self.arduino == None:
            if self.arduino.isOpen():
                pass

                #1. LEER DESDE EL ARDUINO LA INFORMACION DE LOS SENSORES
                #2. PROCESAR LOS DATOS PARA TOMAR UNA DECISION

                a = 1
                b = 10
                c = 220

                #E. ENVIAR LA DECISION TOMADA A ARDUINO....

                #PWM = [0 - 255]
                actuador1 = str(a)
                actuador2 = str(b)
                actuador3 = str(c)

                actuador1 = "0" * (3-len(actuador1)) +actuador1
                actuador2 = "0" * (3-len(actuador2)) +actuador2
                actuador3 = "0" * (3-len(actuador3)) +actuador3



                cadena = "E" + actuador1 + "R" + \
                        actuador2 + "R" + actuador3 + "J"

                print(cadena)
                #E1R10R220J --> E001R0R220J
                #E1R10R220J

                #self.arduino.write("0", encode())

     def accion(self):
        try:
            txt_btn = self.btn_accion.text()
            if txt_btn == "CONECTAR": ##arduino == None
                self.txt_estado.setText("CONECTADO")
                self.btn_accion.setText("DESCONECTAR")
                puerto = self.txt_puerto.text()
                #puerto = "COM" + self.txt_puerto.text()
                self.arduino = conecta.Serial(puerto, baudrate=9600, timeout=1)
                self.segundoPlano.start(10)
            elif txt_btn == "DESCONECTAR":
                self.txt_estado.setText("DESCONECTADO")
                self.btn_accion.setText("RECONECTAR")
                self.segundoPlano.stop()
                self.arduino.close()
            else: #RECONECTAR
                self.txt_estado.setText("RECONECTADO")
                self.btn_accion.setText("DESCONECTAR")
                self.arduino.open()
                self.segundoPlano.start(10)
        except Exception as error:
            print(error)
        #self.arduino.isOpen()

    def control(self):
        if not self.arduino == None:
            if self.arduino.isOpen():
                if self.arduino.inWaiting():
                    #leer
                    variable = self.arduino.readline().decode()
                    variable = variable.replace("\r","")
                    variable = variable.replace("\n","")
                    #print(variable)
                    if not variable == "":
                        self.lw_datos.addItem(variable)
                        self.lw_datos.setCurrentRow(self.lw_datos.count()-1)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())

