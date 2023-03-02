 //TMP36 Pin Variables
#define trigPin 3
#define echoPin 2
int sensorPin = A0;
int sensor = 13;              // the pin that the sensor is atteched to
long duration;
int distance;
int val = 0;

void setup()
 {
pinMode(sensorPin,INPUT);
  pinMode(13,INPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
Serial.begin(9600);
  
   }
void loop() 
{
  
  //TEMPERATURE SENSOR CODE
int adcData = analogRead(sensorPin);  
Serial.println(adcData);
float voltage = (adcData)*(5.0/1024)*1000;
Serial.print(voltage); Serial.println(" volts");
float temperatureC = (voltage - 500)/10 ;  //converting from 10 mv per degree with 500 mV offset
     //to degrees ((voltage - 500mV)/10)
Serial.print(temperatureC); Serial.println(" degrees C");
  // now convert to Fahrenheit
float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
//Serial.print(temperatureF); Serial.println(" degrees F");
delay(1000); //waiting a second

//PIR SENSOR CODE  
  val = digitalRead(sensor);   // read sensor value
  
    if (val == 1) {
      Serial.println("Motion detected!"); 
      
    }
   
  else {
              
      if (val == 0 ){
        Serial.println("Motion stopped!");
        
    }
}
  
//ULTRASOUND SENSOR CODE
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.03432/ 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if(temperatureC>=1 && temperatureC<=40 && val==1 && distance>=1 && distance<=10){
  digitalWrite(8,HIGH);
  }
  if((temperatureC>40 && temperatureC<=80) && (val==1) && (distance=30)){
  digitalWrite(9,HIGH);
  }
  if((temperatureC>80 && temperatureC<=100) && (val==1) && (distance=100)){
  digitalWrite(10,HIGH);
  }
}