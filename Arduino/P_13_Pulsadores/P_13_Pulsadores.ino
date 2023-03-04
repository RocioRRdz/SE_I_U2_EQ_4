int pullup1 = 3;
int pullup2 = 4; //conexion D

int v1, v2;

void setup() {
//pinMode(pullup, INPUT);
//pinMode(2, INPUT_PULLUP);
  pinMode(pullup1,INPUT_PULLUP);
  pinMode(pullup2,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  v1 = digitalRead(pullup1);
  v2 = digitalRead(pullup2);
  //Serial.println(valorPulsador);

  v1 = (v1==1)?0:1;
  v2 = (v2==1)?0:1;

  String c = "E" + String(v1) + "R" + String(v2) + "C";
  Serial.println(c);
  delay(100);
}

