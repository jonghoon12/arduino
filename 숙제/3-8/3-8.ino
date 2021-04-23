#define LED1 11
#define LED2 12
#define SW1 3
#define SW2 2
void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(LED2, OUTPUT);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sw_in1;
  sw_in1 = digitalRead(SW1);
  int sw_in2;
  sw_in2 = digitalRead(SW2);
  if(sw_in1==LOW)
  {
    digitalWrite(LED1, HIGH);
    delay(2000);
    digitalWrite(LED2, LOW);
  }
  else
    digitalWrite(LED1, LOW);
  if(sw_in2==LOW)
  {
    digitalWrite(LED2, HIGH);
    delay(2000);
    digitalWrite(LED1, LOW);
  }
  else
    digitalWrite(LED2, LOW);
}
