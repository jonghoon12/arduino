byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);
int led_value[10] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
int i;
void setup() {
  // put your setup code here, to run once:
  for(int j=0; j<Pin_num; j++)
    pinMode(Pin[j], OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  i=Serial.parseInt();
  if (i == i && led_value[i] == LOW)
  {
    digitalWrite(Pin[i-1], HIGH);
    led_value[i] = HIGH;
  } else if (i == i && led_value[i] == HIGH)
  {
    digitalWrite(Pin[i-1], LOW);
    led_value[i] = LOW;
  }
  delay(100);
}
