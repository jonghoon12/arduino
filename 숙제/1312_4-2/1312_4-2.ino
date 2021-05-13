byte Pin[] = {2,3,4,5,6,7,8,9};
byte Pin_num = sizeof(Pin) / sizeof(byte);
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
  digitalWrite(Pin[0], i%2);
  digitalWrite(Pin[1],(i>>1)%2);
  digitalWrite(Pin[2],(i>>2)%2);
  digitalWrite(Pin[3],(i>>3)%2);
  digitalWrite(Pin[4],(i>>4)%2);
  digitalWrite(Pin[5],(i>>5)%2);
  digitalWrite(Pin[6],(i>>6)%2);
  digitalWrite(Pin[7],(i>>7)%2);
}
