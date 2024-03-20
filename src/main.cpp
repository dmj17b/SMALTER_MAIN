#include <Arduino.h>
#include <Wire.h>


void requestEvent(){
  Wire.write("Hello World");
}

void updateLeg(int leg_address, int joint, float angle);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  updateLeg(80, 1, 90);
  updateLeg(80, 2, 50);
  updateLeg(80, 3, 30);
  updateLeg(80, 4, 90);
  updateLeg(80, 5, 50);
  updateLeg(80, 6, 30);
  updateLeg(80, 7, 90);
  updateLeg(80, 8, 50);
  updateLeg(80, 9, 30);
  updateLeg(80, 10, 90);
  updateLeg(80, 11, 50);
  updateLeg(80, 12, 30);
}


// Function to update the angle of a joint in a leg through I2C
void updateLeg(int leg_address, int joint, float angle){
  char b[8];
  dtostrf(angle, 4, 2, b);
  Wire.beginTransmission(leg_address);
  Wire.write(joint);
  Wire.write('/');
  Wire.write(b);
  Wire.endTransmission();

}