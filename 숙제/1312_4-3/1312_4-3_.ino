//직렬 통신을 이용하여 정수 i를 전송하면, i번째 LED를 반전(토글) 시키는 회로를 구성하고 프로그램을 작성하시오
int Cur_LED[5] = {0,0,0,0};
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  
  
}

void loop()
{
  if(Serial.available() ) {
 int value1 = Serial.parseInt();
    Cur_LED[value1 - 1] = Cur_LED[value1 - 1] ^ 1;
    digitalWrite(value1+9,Cur_LED[value1 - 1]);
  }
}
