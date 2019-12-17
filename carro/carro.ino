#include <SoftwareSerial.h>

SoftwareSerial miBT(2, 4); /// SoftwareSerial(rxPin,txPin)

char dato = 0;
int ledrojo =  3;
int ledverde  = 5;
int ledazul =  6;
int cRojo = 0;
int cVerde = 0;
int cAzul = 0;

void setup() {
  Serial.begin(9600);
  miBT.begin(9600);
  Serial.println("Listo");
  pinMode(ledrojo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledazul, OUTPUT);
}

void loop() {
  if (miBT.available()) {  //LEE  BT Y ENVIA A ARDUINO
    dato = miBT.read();

    if (dato == '4')
      digitalWrite(ledrojo, !digitalRead(ledrojo));


    if (dato == '5')
      digitalWrite(ledverde, !digitalRead(ledverde));

    if (dato == '6')
      digitalWrite(ledazul, !digitalRead(ledazul));

    if (dato == '1')
      rojoMas();

    if (dato == '7')
      rojoMenos();

    if (dato == '2')
      verdeMas();

    if (dato == '8')
      verdeMenos();
    if (dato == '3')
      azulMas();
    if (dato == '9')
      azulMenos();


  }//FIN DEL IF
}

//ROJO ANALOG
void rojoMas() {
  if (cRojo >= 255)
    cRojo = 250;
  analogWrite(ledrojo, cRojo);
  cRojo = cRojo + 5;
  info();
}
void rojoMenos() {
  if (cRojo <= 0)
    cRojo = 5;
  analogWrite(ledrojo, cRojo);
  cRojo = cRojo - 5;
  info();
}
//FIN ROJO ANALOG

//VERDE ABALOG
void verdeMas() {
  if (cVerde >= 255)
    cVerde = 250;
  analogWrite(ledverde, cVerde);
  cVerde = cVerde + 5;
  info();
}
void verdeMenos() {
  if (cVerde <= 0)
    cVerde = 5;
  analogWrite(ledverde, cVerde);
  cVerde = cVerde - 5;
  info();
}
//FIN VERDE ABALOG

//AZUL ANALOG
void azulMas() {
  if (cAzul >= 255)
    cAzul = 250;
  analogWrite(ledazul, cAzul);
  cAzul = cAzul + 5;
  info();
}
void azulMenos() {
  if (cAzul <= 0)
    cAzul = 5;
  analogWrite(ledazul, cAzul);
  cAzul = cAzul - 5;
  info();
}
//FIN AZUL ANALOG

void info() {
  Serial.print("rojo: " );
  Serial.print(cRojo);
  Serial.print(" verde: ");
  Serial.print(cVerde );
  Serial.print(" azul: " );
  Serial.println(cAzul);
}
