#include <SoftwareSerial.h>

SoftwareSerial miBT(10, 11); /// SoftwareSerial(rxPin,txPin)
int LED = 13;
char dato = 0;

void setup() {
  Serial.begin(9600);
  miBT.begin(9600);
  Serial.println("Listo");

  pinMode(LED, OUTPUT);

}

void loop() {
  if (miBT.available()) {
    dato = miBT.read();
    Serial.println(dato);

    if (dato == 'W' || dato == 'w') {
      led_frontal();
      Serial.println("Salida ");
      Serial.println(dato);
    }

}
}

void led_frontal() {

  digitalWrite(LED, !digitalRead(LED));
}
