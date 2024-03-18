#include <Arduino.h>
#include <Wire.h>


void requestEvent(){
  Wire.write("Hello World");
}
void updateLeg(int leg_address, int joint, int angle);
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  String data = "";
  Wire.requestFrom(80, 7);
  while(Wire.available()){
    data += (char)Wire.read();
  }
  
  updateLeg(80, 2, 90);
}


void updateLeg(int leg_address, int joint, int angle){
  float x = 365.25;
  char b[8];
  dtostrf(x, 4, 2, b);
  Wire.beginTransmission(leg_address);
  Wire.write(joint);
  Wire.write('/');
  Wire.write(b);
  Wire.endTransmission();

}