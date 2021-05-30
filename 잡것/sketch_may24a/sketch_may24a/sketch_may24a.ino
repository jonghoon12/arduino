byte LED[] = {2,3,4,5,6,7,8,9};
byte Cur_LED = 0x00;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 8; i++)
    pinMode(LED[i], OUTPUT);
  Serial.begin(9600);
//show_LED();
  for(int i = 0; i < 8; i++)
    digitalWrite(LED[i], Cur_LED & (0x01<<i));
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    Cur_LED = Serial.parseInt();
    Serial.println(Cur_LED);
//  show_LED();
    for(int i = 0; i < 8; i++)
    digitalWrite(Pin[i], Cur_LED & (0x01<<i));
  }
}
/*void show_LED(void)
{
  for(int i = 0; i < 8; i++)
    digitalWrite(Pin[i], Cur_LED & (0x01<<i));
}                                             */
