int led = 13; //pin digital 13

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.setTimeout(100);

pinMode(led, OUTPUT);
}


int estado;

void loop() {
  //put you main code here, to run repeatedly:

  if (Serial.available()>0){
    estado = Serial.readString().toInt();
    digitalWrite(led, estado); // 1 0
  }
  Serial.println(String(estado));

  delay(100);
}

//preprocesamiento

