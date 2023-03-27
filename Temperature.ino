#include <Wire.h>
#include "Adafruit_TMP006.h"
Adafruit_TMP006 tmp006(0x41);  // start with a diferent i2c address!

void setup() { 
  Serial.begin(9600);
  Serial.println("Adafruit TMP006 example");
 
  if (! tmp006.begin()) {
    Serial.println("No sensor found");
    while (1);
  }

  Serial.println("Send s to enter sleep mode, or w to wake up.  Measurements are not updated while asleep!");
}

void loop() {
  // Check for sleep/wake command.
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == 'w') {
      Serial.println("Waking up!");
      tmp006.wake();
    }
    else if (c == 's') {
      Serial.println("Going to sleep!");
      tmp006.sleep();
    }
  }

  // Grab temperature measurements and print them.
  float objt = tmp006.readObjTempC();
  Serial.print("Object Temperature: "); Serial.print(objt); Serial.println("*C");
  float diet = tmp006.readDieTempC();
  Serial.print("Die Temperature: "); Serial.print(diet); Serial.println("*C");
   
  delay(4000); // 4 seconds per reading for 16 samples per reading
}
