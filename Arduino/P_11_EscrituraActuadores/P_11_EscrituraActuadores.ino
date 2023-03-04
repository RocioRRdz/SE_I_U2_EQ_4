//Actuadores analogicos. ->PWM
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
}

String cadena;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    cadena = Serial.readString();
    Serial.println(cadena); //confirmacion de lectura
  //E001R010R220j
  //Serial.println(cadena.length());

    if(cadena.length() ==13){ //cadena es valida
    //Serial.println(cadena);
      if (cadena.charAt(0)=="E" && cadena.charAt(cadena.length()-1) == "J"){
        String c = cadena.substring(1, cadena.length()-1);
        Serial.println("C:" + c + ":D");

        //strtok
        //charArt y un for
        //indexOf **
        //en lugar de readString usar read
        //substring

        //EXPONER SOBRE Keystrokes en python (modulos, 3 ejemplos
        //EXPONERPulsadores en su configuracion pullup con arduino

        char *cad =c.c_str();
        char *garuco = strtok(cad, "R");

        int cont = 0;
        while(garuco != NULL){
          //Serial.println(garuco);
          switch(cont){
            case 0:
              vA = String(garuco).toInt();
              //analogWrite(actuador1,vA);
            break;

            case 1:
              vB = String(garuco).toInt();
            break;  
            
            case 2:
              vAC = String(garuco).toInt();
            break;
          }
          cont++;
          garuco= strtok(NULL, "R");
        }

        Serial.println(String(vA) + " " + String(vB) + "" + String(vC))
        }
    }
  }

  delay(100);
}


//Exponer como solucionar este problema, de acuerdo a los comentarios.