byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);
int i;
byte led_value
void setup() {
  // put your setup code here, to run once:
  for(int j=0; j<Pin_num; j++)
    pinMode(Pin[j], OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    i=Serial.parseInt();
    if(i==1)
    {
      led_value = led_value ^ 1;
      digitalWrite(2,led_value);
    }
  }
}
