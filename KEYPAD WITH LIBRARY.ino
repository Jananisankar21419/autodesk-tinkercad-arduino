#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
   Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
   }
  void loop(){
  char key = keypad.getKey();
    if (key){
	digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    Serial.println(key);
      for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
          if(key==keys[i][j]){
            if(j==0){
            digitalWrite(2,HIGH);
            }
            if(j==1){
            digitalWrite(3,HIGH);
            }
            if(j==2){
            digitalWrite(12,HIGH);
            }
            if(j==3){
            digitalWrite(13,HIGH);
            }
          } 
        }
      }
    }  
}