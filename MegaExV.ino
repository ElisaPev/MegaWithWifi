//Mega Code
//Last Edited 24/03/2022
//Pins 3 and 4 ON, Rest of pins OFF to upload code to Mega
//With just pins 3,4 ON. Mega can talk to PC.
#include <ArduinoJson.h>//Uses it to send data
int randomNumber;
int ledPin = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //If you want to talk to PC
  Serial3.begin(115200); //Talk to ESP
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  randomNumber = random(2);//generates random number from 0-1
  Serial.println(randomNumber);
  if(randomNumber == 0){
    digitalWrite(ledPin, LOW);
  }
  else{
    digitalWrite(ledPin, HIGH);
  }
  delay(1000);

//Send Over Serial and apply JSON
  StaticJsonDocument<200> doc;
  doc["rNumber"] = randomNumber;
  serializeJson(doc, Serial3);// sends to ESP
  delay(1000);
  
  
}
