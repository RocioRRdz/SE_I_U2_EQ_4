int pot = A0;   // Pin del potenciómetro
int v[30];   // Arreglo para almacenar los valores del potenciómetro
int moda = 0;      // Variable para almacenar la moda
//int t = 30;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 30; i++) {
    v[i] = analogRead(pot);
    delay(100);
  }

  // Calcular la moda de los valores
  int repeticiones = 0;
  for (int i = 0; i < 30; i++) {
    int cont = 0;
    for (int j = 0; j < 30; j++) {
      if (v[j] == v[i]) {
        cont++;
      }
    }
    if (cont > repeticiones) {
      moda = v[i];
      repeticiones = cont;
    }
  }

  Serial.println("Valores:");
  for (int i = 0; i < 30; i++) {
    Serial.println(v[i]);

  }

  if (repeticiones == 1){
    Serial.println("No hay valores repetidos");
  }else{
    Serial.print("Moda: ");
    Serial.println(moda);
  }
  delay(1000);
}
