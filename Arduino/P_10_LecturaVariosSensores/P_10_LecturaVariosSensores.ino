int sensor = A0; //POT1
int sensor = A1; //POT2
int sensor = A2; //POT3

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

int v1, v2, v3;

void loop() {
  //put you main code here, to run repeatedly:
  vP1 = analogRead(sensor1);
  vP2 = analogRead(sensor2);
  vP3 = analogRead(sensor3);

  Serial.println("E" + String(vP1) + "G" + String(vP2) + "G" + String(vP3) + "J");

  delay(100);
}

//preprocesamiento

