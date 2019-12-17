
const byte columna[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

const byte nivel[] = {11, 12, 13};

void setup() {
  for (int x = 0; x < 11; x++ ) {
    pinMode(columna[x], OUTPUT);
  }

  for (int x = 11; x < 14; x++ ) {
    pinMode(nivel[x], OUTPUT);
  }
}

void loop() {
  //parpadeo();
  aleatorio();

}
void cuboON() {
  nivelON();
  columnaON();

  
  

}
void nivelON(){
  for (int x = 11; x < 14; x++ ) {
    digitalWrite(nivel[x], HIGH);
  }
  }
  void columnaON(){
    for (int x = 0; x < 11; x++ ) {
    digitalWrite(columna[x], HIGH);
  }
    }
void cuboOFF() {

  for (int x = 11; x < 14; x++ ) {
    digitalWrite(nivel[x], LOW);

  }
  for (int x = 0; x < 11; x++ ) {
    digitalWrite(columna[x], LOW);
  }
}
void parpadeo() {

  int time = 1000;

  while (time > 0) {
    cuboON();
    delay(time);
    cuboOFF();
    delay(time);
    time = time - 25;
  }


}
void aleatorio() {
  nivelON();
while (true){ 
  int x =random(2,10);
  digitalWrite(x,HIGH);  
  digitalWrite(x,LOW);
 // Serial.print(x);
  
 // delay(1000);
}
}
