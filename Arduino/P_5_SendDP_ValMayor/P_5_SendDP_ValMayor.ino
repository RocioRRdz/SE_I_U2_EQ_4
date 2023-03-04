int potenciometro = A0;

int totMuestras = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int i, valor, valorMayor = -1; //99999;

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0; i<totMuestras; i++){ //--> Teorema del limite central
      valor += analogRead(potenciometro);

      if(valor>valorMayor){
        valorMayor = valor;
      }
  }

  //Serial.println("Valor="+String(valor));
  Serial.println(valorMayor);
  delay(1000);
}

//preprocesamiento