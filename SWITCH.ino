// C++ code
//
void setup()
{
 // pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  //pinMode(8,INPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  if(digitalRead(3)==1){
  digitalWrite(4,LOW);
  delay(500);
  }
  if(digitalRead(8)==0){
  digitalWrite(5,HIGH);
  delay(500);
  }
}