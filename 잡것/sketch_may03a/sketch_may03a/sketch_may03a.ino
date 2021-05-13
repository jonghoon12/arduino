//0~255입력받아 이진수로 표현
byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);
void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<Pin_num; i++)
    pinMode(Pin[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    long value = Serial.parseInt();
    
  }
}
