int led[8] = {5, 6, 7, 8, 9, 10, 11, 12};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  if (Serial.available()) {
    String palabra = Serial.readString();
    for (int i = 0; i < palabra.length(); i++) {
      char letra = palabra.charAt(i);
      encenderLetra(letra);
    }
  }
}

void encenderLetra(char letra) {
  int asciiCode = (int)letra;
  String binario = decToBin(asciiCode);
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(leds[i], binario.charAt(i) == '1');
  }

  delay(5000);

  for (int j = 0; j < 8; j++) {
    digitalWrite(leds[j], LOW);
  }

  delay(2000);
}

String decToBin(int a) {
  String binario = "";
  for (int i = 7; i >= 0; i--) {
    binario += (a & (1 << i)) ? '1' : '0';
  }
  return binario;
}
