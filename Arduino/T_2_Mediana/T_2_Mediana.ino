int potenciometro = A0;  
int val[30];  

void setup() {
  Serial.begin(9600);  // Iniciar la comunicación serial
}

void loop() {
  for (int i = 0; i < 30; i++) {
    val[i] = analogRead(potPin);
    delay(10);
  }
  
  // Ordenar los valores del arreglo
  for (int i = 0; i < 29; i++) {
    for (int j = i+1; j < 30; j++) {
      if (valores[i] > valores[j]) {
        int temp = valores[i];
        val[i] = valores[j];
        val[j] = temp;
      }
    }
  }
  
  // Calcular la mediana de los valores
  int mediana;
  if (30 % 2 == 0) {
    mediana = (val[15] + val[16]) / 2;
  } else {
    mediana = val[15];
  }
  
  Serial.println("Potenciometro:");
  for (int i = 0; i < 30; i++) {
    Serial.println(val[i]);
  }
  
  Serial.print("Mediana: ");
  Serial.println(mediana);
  
  delay(1000);
}
