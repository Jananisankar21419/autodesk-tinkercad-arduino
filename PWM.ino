// C++ code
//
int a=0;
int b=0;
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) {
   char received= Serial.read();
   Serial.print("data received =");
   Serial.println(received);     
    if (received == 'a') {
      blink1();
    }
    if (received == 'b') {
    	blink2();
    }
  }
}
void blink1(){
for(a=0,b=255;a<=255,b>=0;a++,b--){
    Serial.print("Duty cycle in a: ");
   	Serial.print(a);
  	Serial.print(" Duty cycle in b: ");
    Serial.println(b);
    analogWrite(3,a);
  	analogWrite(5,b);
}
}
void blink2(){
for(b=0,a=255;b<=255,a>=0;b++,a--){
    Serial.print("Duty cycle in b: ");
    Serial.print(b);
  	Serial.print(" Duty cycle in a:");
    Serial.println(a);
    analogWrite(5,b);
    analogWrite(3,a);
    }
}
