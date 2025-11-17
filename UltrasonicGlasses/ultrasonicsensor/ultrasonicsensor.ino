#include "Ultrasonic.h"

Ultrasonic myUltraSonicSensor(5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long RangeInCentimeters;

  RangeInCentimeters = myUltraSonicSensor.distanceRead(); // two measurements 
  Serial.print(RangeInCentimeters); // 0~400cm
  Serial.println(" cm");
  delay(250);
}
