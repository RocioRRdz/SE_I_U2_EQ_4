int pullup = 2; //conexion D
int led = 13; //pin para el LED incorporado en la placa Arduino (Marcado como "L").

int valorPulsador = 0;

void setup() {
//pinMode(pullup, INPUT);
//pinMode(2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorPulsador = digitalRead(pullup);
  //Serial.println(valorPulsador);
 
  if (valorPulsador == HIGH) { //pulsador desactivado (5V)
    digitalWrite(led, HIGH);
    Serial.println("1"); //Esta prendido el led
  }
  else { //pulador activado (GND)
    digitalWrite(led, LOW);
    Serial.println("0"); //apagado el led
  }
  delay(1000);
}

