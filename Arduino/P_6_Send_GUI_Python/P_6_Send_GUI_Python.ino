
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

long val = 0;

void loop() {

  //Serial.println("Valor="+String(valor));
  Serial.println(val);
  val++;
  delay(1000);
}

//preprocesamiento
