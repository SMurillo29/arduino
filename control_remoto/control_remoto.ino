#include <IRremote.h>
#define boton_rojo  0xEFB24D
#define boton_verde 0xEF728D
#define boton_azul  0xEF0AF5


int SENSOR  = 11;
IRrecv irrecv(SENSOR);
decode_results codigo;

int LEDROJO =2;
int LEDVERDE =3;
int LEDAZUL =4;

void setup() {
 Serial.begin(9600);
 irrecv.enableIRIn();

 pinMode(LEDROJO,OUTPUT);
 pinMode(LEDVERDE,OUTPUT);
 pinMode(LEDAZUL,OUTPUT);
}

void loop() {
  if(irrecv.decode(&codigo)){
    Serial.println(codigo.value, HEX);
   
    if(codigo.value == boton_rojo)
    digitalWrite(LEDROJO,!digitalRead(LEDROJO));

    if(codigo.value == boton_verde)
    digitalWrite(LEDVERDE,!digitalRead(LEDVERDE));

    if(codigo.value == boton_azul)
    digitalWrite(LEDAZUL,!digitalRead(LEDAZUL));


    
    irrecv.resume();
    }
    delay(1000);
}
