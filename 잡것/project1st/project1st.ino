#include <Servo.h> 
#include <Wire.h>                        // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // LCD 1602 I2C용 라이브러리
LiquidCrystal_I2C lcd(0x3F,16,2);     // 접근주소: 0x3F or 0x27

int tmp36 = A0;

Servo servo1; 
int servoPin1 = 9;
int motorPin = 5;

unsigned long timeVal = 0; //이전시간

int segValue[4][7] = {
  {0,0,0,0,0,0,1}, //0
  {1,0,0,1,1,1,1}, //1
  {0,0,1,0,0,1,0}, //2
  {0,0,0,0,1,1,0}, //3
};
int segPin[8]={4,6,7,8,10,11,12}; //a,b,c,d,e,f,g 핀


int interruptPin1 = 2; //바람 세기 스위치버튼
int interruptPin2 = 3; //회전 스위치버튼
int step = 0; //바람의세기 단계
boolean sw_state = false; //회전스위치 상태값
int angle = 0; //회전각
int addAngle = 10; //회전조절각

void setup() 
{ 
  pinMode(motorPin, OUTPUT); //DC모터
  servo1.attach(servoPin1); //서보모터
    
  for(int i=0;i<7;i++){ //7-Segment Display핀 모드를 선언과 동시체 초기 0단계 표시
    pinMode(segPin[i], OUTPUT);
    digitalWrite(segPin[i], segValue[0][i]);
  }
  
    //인터럽트함수 선언
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), exchange1, FALLING); 
  attachInterrupt(digitalPinToInterrupt(interruptPin2), exchange2, FALLING);
  

  //초기 세팅
  analogWrite(motorPin, 0); //바람세기 = 0
  servo1.write(angle); //회전각 = 0
  delay(1000);
  
  Serial.begin(9600);  
  lcd.init();                      // LCD 초기화
  lcd.backlight();                // 백 라이트 켜기
}

void loop() 
{   
  int sensor = analogRead(tmp36);
      
  float voltage = sensor * 5000.0/1024.0;     // 온도센서의 값을 전압으로 변환
  float celsius = (voltage - 500) / 10.0;     // 전압을 온도로 변환
  
  lcd.setCursor(0,0);             // 1번째, 1라인
  lcd.print("temperature is ");
  lcd.setCursor(6,1);             // 7번째, 2라인
  lcd.print(celsius);
  lcd.setCursor(11,1);             // 12번째, 2라인
  lcd.print(" C");
  delay(500);
  if(step>0 && sw_state==true){
    if(millis()-timeVal>=100){
        angle=angle+addAngle;
        if(angle==180){
          addAngle=-10;
        }
        else if(angle==0){
          addAngle=10;
        }  
        servo1.write(angle);        
        timeVal = millis();
    }
  }   
}
void exchange1() {
  step++;
  if(step==4) step=0;
  for(int j=0;j<7;j++){
     digitalWrite(segPin[j], segValue[step][j]);        
  }
  switch(step){
    case 0:
     analogWrite(motorPin, 0);
     break;
    case 1:
     analogWrite(motorPin, 85);
     break;
    case 2:
     analogWrite(motorPin, 170);
     break;
    case 3:
     analogWrite(motorPin, 255);
     break;
  }
}
void exchange2() {
  sw_state=!sw_state;
  timeVal = millis();
}
