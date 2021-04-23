byte Pin[]={2,3,4,5,6,7,8,9};
byte Pin_num=sizeof(Pin)/sizeof(byte);
int j=2;
void setup() 
{
  // put your setup code here, to run once:
  for(int i=0; i<Pin_num; i++) 
  {
    pinMode(Pin[i], OUTPUT); 
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  if(j==9)
  {
    while(1)
    {
      if(j==2)
      {
        break;
      }
      digitalWrite(Pin[j-2], HIGH);
      delay(500);
      digitalWrite(Pin[j-2], LOW);
      j--;
    }
  }
  if(j==2)
  {
    while(1) 
    {
      if(j==9) 
      {
        break;
      }
      digitalWrite(Pin[j-2], HIGH);
      delay(500);
      digitalWrite(Pin[j-2], LOW);
      j++;
    }
  }
}
