volatile int state = HIGH;
volatile int flag = HIGH;
int count = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, state);
  pinMode(PUSH2, INPUT_PULLUP);
  attachInterrupt(PUSH2, blink, FALLING); 
// Interrupt is fired whenever button is pressed
}
void loop()
{
  digitalWrite(GREEN_LED, state); //LED starts ON
  if(flag) 
  {
    count++;
    Serial.println(count);
    flag = LOW;
  }
}
void blink()
{
  state = !state;
  flag = HIGH;
}
