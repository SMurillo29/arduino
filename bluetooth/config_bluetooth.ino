const int LED = 13;
const int POWER_BT = 12;

String name_BT = "arduino_car";
char velocidad = "4"; //9600;
String pin = "1234";

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(POWER_BT, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(POWER_BT, HIGH);

  Serial.begin(9600);
  Serial.print("AT");
  delay(1000);

  Serial.print("AT+NAME");
  Serial.print(name_BT);
  delay(1000);

  Serial.print("AT+BAUD");
  Serial.print(velocidad);
  delay(1000);

  Serial.print("AT+PIN");
  Serial.print(pin);
  delay(1000);

   digitalWrite(LED, HIGH );
}

void loop() {


}
