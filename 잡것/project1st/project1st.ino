#include <Servo.h>
#include <Wire.h>                        // i2C 통신을 위한 라이브러리
#include <LiquidCrystal_I2C.h>        // LCD 1602 I2C용 라이브러리
LiquidCrystal_I2C lcd(0x27, 16, 2);   // 접근주소: 0x3F or 0x27

int tmp36 = A0;

Servo servo1;
int servoPin1 = 9;
#define ENB 5
#define EN3 7
#define EN4 6
int Motor_speed = 0;

unsigned long timeVal = 0; //이전시간




int interruptPin1 = 2; //바람 세기 스위치버튼
int interruptPin2 = 3; //회전 스위치버튼
int step = 0; //바람의세기 단계
boolean sw_state = false; //회전스위치 상태값
int angle = 0; //회전각
int addAngle = 10; //회전조절각

void setup()
{
  Serial.begin(9600);
  
  servo1.attach(servoPin1); //서보모터

  //DC모터
  pinMode(ENB, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);

  //인터럽트함수 선언
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), exchange1, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), exchange2, FALLING);


  //초기 세팅
  digitalWrite(EN3, HIGH);  //DC모터 방향
  digitalWrite(EN4, LOW);
  analogWrite(ENB, Motor_speed);  //DC모터 세기
  servo1.write(angle); //회전각 = 0
  delay(1000);

  Serial.begin(9600);
  lcd.init();                      // LCD 초기화
  lcd.backlight();                // 백 라이트 켜기
}

void loop()
{
  int sensor = analogRead(tmp36);

  float voltage = sensor * 5000.0 / 1024.0;   // 온도센서의 값을 전압으로 변환
  float celsius = (voltage - 500) / 10.0;     // 전압을 온도로 변환

  lcd.setCursor(0, 0);            // 1번째, 1라인
  lcd.print(celsius);
  lcd.setCursor(5, 0);            // 6번째, 1라인
  lcd.print(" C");
  lcd.setCursor(0, 1);            // 1번째, 2라인
  lcd.print(step);
  lcd.setCursor(1, 1);            // 2번째, 2라인
  lcd.print(" step");
  delay(500);
  
  if (step > 0 && sw_state == true) {
    if (millis() - timeVal >= 100) {
      angle = angle + addAngle;
      if (angle == 180) {
        addAngle = -10;
      }
      else if (angle == 0) {
        addAngle = 10;
      }
      servo1.write(angle);
      timeVal = millis();
    }
  }
  analogWrite(ENB, Motor_speed);
}
void exchange1() {
  step++;
  if (step == 4) step = 0;

  switch (step) {
    case 0:
      Motor_speed = 0;
      Serial.println(step);
      break;
    case 1:
      Motor_speed = 85;
      Serial.println(step);
      break;
    case 2:
      Motor_speed = 170;
      Serial.println(step);
      break;
    case 3:
      Motor_speed = 255;
      Serial.println(step);
      break;
  }
}
void exchange2() {
  sw_state = !sw_state;
  timeVal = millis();
}
