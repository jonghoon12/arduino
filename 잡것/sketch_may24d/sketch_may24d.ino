void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  static int i = 0;
  char str[20];
  sprintf(str, "%d-th value", i++);
  Serial.println(str);
  delay(500);
}
