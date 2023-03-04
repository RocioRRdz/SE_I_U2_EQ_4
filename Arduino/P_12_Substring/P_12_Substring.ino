int s1 = A0;
int s2 = A1;
int s3 = A2;

//ensayo: porque conviene ono aplicar la igualacion de cadenas cuando es enviada entre dispositivos electronicos. +condiciones especificas

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
Serial.setTimeout(10); //puede ser opcional
}

void loop() {
// put your main code here, to run repeatedly:
  int v1 = analogRead(s1);
  int v2 = analogRead(s2);
  int v3 = analogRead(s3);

  String c = "E" + String(v1) + "R" + String(v2) + "R" + String(v3) + "C";
  Serial.println(c);
  delay(500);

  String variable = Serial.readString();
    if (variable != "") {
      if (variable[0] == 'E' && variable[variable.length()-1] == 'C') {
        String subcadena = variable.substring(1, variable.length()-1);
        
        String datos[3];
        int pos = 0;
        for (int i=0; i<3; i++) {
          int idx = subcadena.indexOf('R', pos);
          if (idx != -1) {
            datos[i] = subcadena.substring(pos, idx);
            pos = idx + 1;
          } else {
            datos[i] = subcadena.substring(pos);
          }
        }
      String cadena = datos[0] + "A" + datos[1] + "A" + datos[2];
      Serial.println(cadena);
    }
  }
}





