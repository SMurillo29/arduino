#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3); /// SoftwareSerial(rxPin,txPin)



void setup() {
 Serial.begin(9600);
 Serial.println("Listo");
 miBT.begin(9600);
}

void loop() {
 if (miBT.available()){   //LEE  BT Y ENVIA A ARDUINO
  Serial.write(miBT.read());
  Serial.println(" dato");
  }

   if(Serial.available()){  //LEE A ARDUINO Y ENVIA A BT
    miBT.write(Serial.read());
    }
}
