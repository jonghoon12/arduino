/*#define LED1 12
#define LED2 11
#define LED3 10*/
byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);
#define LED 12
#define SW 13

void setup() {
/*pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);*/
/*for(int i=2; i<=9; i++)
    pinMode(i, OUTPUT);   */
  for(int i=0; i<Pin_num; i++)
    pinMode(Pin[i], OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
}

void loop() {
/*digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(500);               */
/*for(int i = 2; i <= 9; i++)
  {
    for(int j=2; j<=9; j++)
    {
      if(i==j)
      digitalWrite(j, HIGH);
      else
      digitalWrite(j, LOW);
    }
    delay(500);
  }                         */
  for(int i=0; i<Pin_num; i++)
  {
    for(int j=0; j<Pin_num; j++)
    {
      if(i==j)
      digitalWrite(Pin[j], HIGH);
      else
      digitalWrite(Pin[j], LOW);
    }
    delay(500);
  }                               
  for(int i=0; i<Pin_num; i++)
  {
    for(int j=0; j<Pin_num; j++)
    {
      if(i==j)
      digitalWrite(Pin[Pin_num - j], HIGH);
      else
      digitalWrite(Pin[Pin_num - j], LOW);
    }
    delay(500);
  }
/*static int loc = 0;
  for(int i=0; i<Pin_num; i++)
  {
      digitalWrite(Pin[i], LOW);
  }    
    digitalWrite(Pin[loc], HIGH);
    loc++;
    loc %= 8;
    delay(500);                   */
//좌우로 이동하며 점멸
//0~15 이진값 표현
  int sw_in;
  sw_in = digitalRead(SW);
  if(sw_in == HIGH)
  {
    digitalWrite(LED, HIGH);
    delay(1);
  }else
    digitalWrite(LED, LOW);
}
