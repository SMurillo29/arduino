#include <SoftwareSerial.h>

SoftwareSerial miBT(11, 12); /// SoftwareSerial(rxPin,txPin)

char dato = 0;
int ledfrontal = 10  ;
int ENA  = 2;
int IN1 =  3;
int IN2 = 4;
int ENB = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {
  Serial.begin(9600);
  miBT.begin(9600);
  Serial.println("Listo");

  pinMode(ledfrontal, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (miBT.available()) {
    dato = miBT.read();
    Serial.println(dato);

    if (dato == 'W' || dato == 'w') {
      led_frontal();
      Serial.println("gonorrea ome gonorrea ");
      Serial.println(dato);
    }

    if (dato == 'F')
      adelante();

    if (dato == 'B')
      atras();


    if (dato == 'L')
      izquierda();

    if (dato == 'R')
      derecha();

    if (dato == 'U' || dato == 'u')
      swich_carro();

  }
}

void led_frontal() {

  digitalWrite(ledfrontal, !digitalRead(ledfrontal));
}

void adelante() {
  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

}
void atras() {


  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);



}

void izquierda() {
  
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void derecha() {
  
  digitalWrite(ENB, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void swich_carro() {
  digitalWrite(ENA, !digitalRead(ENA));
  digitalWrite(ENB, !digitalRead(ENB));
}
