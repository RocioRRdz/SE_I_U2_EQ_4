from pynput import keyboard


def on_press(key):
    try:
        print('La tecla {} se presiono.'.format(key.char))
    except AttributeError:
        print('La tecla {} fue presionada.'.format(key))
    if key == keyboard.Key.esc:
        return False


def on_release(key):
    print('La tecla {} fue soltada.'.format(key))


with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
