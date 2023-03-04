from pynput import keyboard as kb


def pulsa(tecla):
    print('Se ha pulsado la tecla ' + str(tecla))


# Recolecta la infomacion de las teclas presionadas
with kb.Listener(pulsa) as escuchador:
    escuchador.join()
