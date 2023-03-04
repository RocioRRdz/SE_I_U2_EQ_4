// Práctica charAt y 1 for

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}


String cadena = "E001R010R230J";
String vA, vB, vC;
int indexA, indexB, indexC;
void loop() {
  int pos = 1;
  // put your main code here, to run repeatedly:
  if(cadena.length()==13){
    Serial.println("Largo de cadena aceptado.");
    if(cadena.charAt(0)=='E' && cadena.charAt(cadena.length()-1)=='J'){
      Serial.println("Estructura de cadena aceptada.");
      
      //Aquí abajo va lo mero mero
      indexA = cadena.indexOf("E");
      vA = String(cadena[indexA+1]) + String(cadena[indexA+2]) + String(cadena[indexA+3]);

      indexB = cadena.indexOf("R");
      vB = String(cadena[indexB+1]) + String(cadena[indexB+2]) + String(cadena[indexB+3]);

      indexC = cadena.indexOf("J");
      vC = String(cadena[indexC-3]) + String(cadena[indexC-2]) + String(cadena[indexC-1]);

    }else{
      Serial.println("Estructura de cadena no aceptada.");
    }

  }else{
    Serial.println("Largo de cadena no aceptado.");
  }

  Serial.println("vA: " + String(vA));
  Serial.println("vB: " + vB);
  Serial.println("vC: " + vC);

  delay(3000);
}
