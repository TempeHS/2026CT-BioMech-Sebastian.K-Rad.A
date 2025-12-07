#include "Ultrasonic.h"

Ultrasonic myUltraSonicSensor(8);

unsigned static int greenLED = 5;
unsigned static int redLED = 3;

//unsigned static int LbuttonPIN = 6;
//unsigned static int RbuttonPIN = 7;

void leftloop();
void rightloop();

// LEFT LED IS RED
// RIGHT LED IS GREEN

int leftLED = 1;
int rightLED = 2;

int SensorState = 1;

//int LbuttonState = 0;
//int LlastButtonState = HIGH;

//int RbuttonState = 0;
//int RlastButtonState = HIGH;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("baud rate is at 9600");

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  //pinMode(LbuttonPIN, INPUT);
  //pinMode(RbuttonPIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(200);

  unsigned long RangeInCentimeters;

  RangeInCentimeters = myUltraSonicSensor.distanceRead(); // two measurements 
  Serial.print(RangeInCentimeters); // 0~400cm
  Serial.println(" cm");

if (SensorState == 1 + RangeInCentimeters >= 20) {
  redLED = 0;
  } else (RangeInCentimeters <= 5); {
    redLED = 2;
  }
  
  // MAP distance to brightness (0-255)
  // Close (5cm) = bright (255), Far (50cm) = dim (0)
  leftLED = map(RangeInCentimeters, 5, 50, 255, 0);
  
  // Constrain to valid PWM range
  leftLED = constrain(leftLED, 0, 255);
  
  // Write brightness to LED
  analogWrite(redLED, leftLED);
  analogWrite(greenLED, rightLED);
  
  Serial.print("LED Brightness: ");
  Serial.println(leftLED);
}


void leftloop() {
  // LEFT

 // int LbuttonPressed = digitalRead(LbuttonPIN);
//
 // if (LlastButtonState == HIGH && LbuttonPressed == LOW) {
 //   LbuttonState = (LbuttonState + 1) % 3;
 // }
 // LlastButtonState = LbuttonPressed;
//
 // leftLED = LbuttonState;
 
 if (leftLED == 2) {
   analogWrite(redLED, 255);
 } else if (leftLED == 1) {
   analogWrite(redLED, 125);
 } else {          
   analogWrite(redLED, 0);
 }

}

void rightloop() {
  // RIGHT

// int RbuttonPressed = digitalRead(RbuttonPIN);
//
// if (RlastButtonState == HIGH && RbuttonPressed == LOW) {
//   RbuttonState = (RbuttonState + 1) % 3;
// }
// RlastButtonState = RbuttonPressed;
//
// rightLED = RbuttonState;
//

 if (rightLED == 2) {
   analogWrite(greenLED, 255);
 } else if (rightLED == 1) {
   analogWrite(greenLED, 125);
 } else {
   analogWrite(greenLED, 0);
 }

}
