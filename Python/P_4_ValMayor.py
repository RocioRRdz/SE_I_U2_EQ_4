import serial as s

arduino = None

arduino = s.Serial("COM4", baudrate=9600, timeout=1)

lista = []
Muestras = 30
valorMayor = -1024

for i in range(Muestras):
    valor = 0
    for j in range(Muestras):
        cadena = arduino.readline()
        cadena = cadena.decode()
        cadena = cadena.replace("\n","")
        cadena = cadena.replace("\r", "")
        if cadena!="":
            valor += int(cadena)

    if valor > valorMayor:
        valorMayor = valor
    lista.append(valor)

print("Lista:", lista)
print("Valor mayor:", valorMayor)