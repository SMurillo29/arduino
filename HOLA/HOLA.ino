void setup() {
  pinMode(10, OUTPUT); //entrada a
  pinMode(11, OUTPUT); //entrada b
}

void loop() {
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);//letra H
  delay(500);

  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);//letra O
  delay(500);

  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);//letra L
  delay(500);

  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);//letra A
  delay(500);
}
