from pynput import mouse


# Muestra las coordenadas del movimiento del mouse
def on_move(x, y):
    print('Puntero movido a {0}'.format(
        (x, y)))


# Recolecta los eventos de movimiento del mouse
with mouse.Listener(
        on_move=on_move) as listener:
    listener.join()
