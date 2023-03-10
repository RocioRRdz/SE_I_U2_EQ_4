int led[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; 
int tleds = 9;
int pb[] = {12, 13};
int tpb = 2;

void setup() {
  // put your setup code here, to run once:
  for (int k = 0; k < tleds; k++) {
    pinMode(led[k], OUTPUT);
  }
  for (int k = 0; k < tpb; k++) {
    pinMode(pb[k], INPUT_PULLUP);
  }
  Serial.begin(9600);
}

int i=0, j=0;
int v1, v2; //v1 = arriba/abajo          v2 = izquierda/derecha
int jugador=0;
int tabla[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

void loop() {
  // put your main code here, to run repeatedly:
  v1 = digitalRead(pb[0]);
  v2 = digitalRead(pb[1]);

  if (v1 == HIGH){
    i++;
    if (i > 2){
      i = 0;
    }
  }else{
    i--;
    if (i < 0){
      i = 2;
    }
  }

  if (v2 == HIGH){
    j++;
    if (j > 2){
      j = 0;
    }
  }else{
    j--;
    if (j < 0){
      j = 2;
    }
  }

  if (digitalRead(pb[2]) == HIGH) {

    if (tabla[i][j] == -1) {
      tabla[i][j] = jugador;

      digitalWrite(led[i*3 + j], jugador);

      jugador = 1 - jugador;
      int ganador = jugadorGanador;
    
      if (ganador != -1) {
        Serial.print("Jugador ganador: ");
        
        if (ganador == 0) {
          Serial.println("X");
        }else {
          Serial.println("O");
        }

          for (int k = 0; k < 9; k++) {
            digitalWrite(led[k], HIGH);
          }
          delay(5000);
          for (int k = 0; k < 9; k++) {
            digitalWrite(led[k], LOW);
          }

          for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
              tabla[k][l] = -1;
            }
          }
          jugador = 0;
          i = 0;
          j = 0;
        }
      }
    }
  }
}

void jugadorGanador() {
    for (int k = 0; k < 3; k++) {
      if (tabla[k][0] != -1 && tabla[k][0] == tabla[k][1] && tabla[k][0] == tabla[k][2]) {
        return tabla[k][0];
      }
    }

    for (int k = 0; k < 3; k++) {
      if (tabla[0][k] != -1 && tabla[0][k] == tabla[1][k] && tabla[0][k] == tabla[2][k]) {
        return tabla[0][k];
      }
    }

    if (tabla[0][0] != -1 && tabla[0][0] == tabla[1][1] && tabla[0][0] == tabla[2][2]) {
      return tabla[0][0];
    }
    if (tabla[0][2] != -1 && tabla[0][2] == tabla[1][1] && tabla[0][2] == tabla[2][0]) {
      return tabla[0][2];
    }

  return -1;
}
