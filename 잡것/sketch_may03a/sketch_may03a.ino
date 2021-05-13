#define LED 12
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    long value = Serial.parseInt();
    digitalWrite(LED, value);
  }
}
