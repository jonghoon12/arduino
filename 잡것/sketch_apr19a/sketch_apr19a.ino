#define LED 12
#define SW 2
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sw_in;
  sw_in = digitalRead(SW);
  if(sw_in==LOW)
  {
    digitalWrite(LED, HIGH);
    delay(1);
  }
  else
    digitalWrite(LED, LOW);
}
