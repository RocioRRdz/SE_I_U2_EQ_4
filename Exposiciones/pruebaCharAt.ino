// Práctica charAt y 1 for

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}

String numeros[3];
String cadena = "E001R010R230J";

void loop() {
  int pos = 1;
  // put your main code here, to run repeatedly:
  if(cadena.length()==13){
    Serial.println("Largo de cadena aceptado.");
    if(cadena.charAt(0)=='E' && cadena.charAt(cadena.length()-1)=='J'){
      Serial.println("Estructura de cadena aceptada.");
      
      //Aquí abajo va lo mero mero
      for(int i=0; i<3; i++){
        numeros[i] = String(cadena.charAt(pos) + String(cadena.charAt(pos+1) + String(cadena.charAt(pos+2))));
        pos += 4;
      }


    }else{
      Serial.println("Estructura de cadena no aceptada.");
    }

  }else{
    Serial.println("Largo de cadena no aceptado.");
  }

  //Impresión del arreglo que contiene los números separados.
  for(int j=0; j<3; j++){
    Serial.println(numeros[j]);
  }
  delay(3000);
}
