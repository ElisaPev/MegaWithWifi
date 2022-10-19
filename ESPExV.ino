//ESP Code
//Last Edited 24/03/2022
//5,6,7 ON to upload code to ESP. All other pins off
//Once uploaded press RESET BUTTON to ensure code uploaded
//IF you want ESP to talk to SERIAL switch 7 OFF so only 5,6 ON
//then press RESET button
//ESP cannot talk to SERIAL whilst connected to Arduino
//Switch 1,2 ON, other PINS off for ESP and Arduino to talk
//Can have 1,2,3,4 ON so ESP and Arduino can talk but
//Arduino can also still talk to Serial.
//RX/TX switch set to RXD3/TXD3
#include <ArduinoJson.h>
int randomNumberESP;
int ledPin = 4;
void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  
}

void loop() {
  //json part to unpackage from mega then assign variables
  StaticJsonDocument<300> doc;
  DeserializationError error = deserializeJson(doc, Serial);
  
  //Print the data in the serial monitor
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    
    return;
  }
  else{
    Serial.println("JSON received and parsed");
  randomNumberESP = (doc["rNumber"].as<int>()); 
  }
  if(randomNumberESP == 0){
    digitalWrite(ledPin, LOW);
  }
  else{
    digitalWrite(ledPin, HIGH);
  }
  delay(1000);
}
