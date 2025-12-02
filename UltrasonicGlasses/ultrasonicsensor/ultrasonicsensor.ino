#include "Ultrasonic.h"

Ultrasonic myUltraSonicSensor(8);
unsigned static int greenLED = 5;
unsigned static int redLED = 3;
unsigned static int LbuttonPIN = 6;
unsigned static int RbuttonPIN = 7;

// LEFT LED IS RED
// RIGHT LED IS GREEN

int leftLED = 1;
int rightLED = 2;

int SensorState = 1;

int LbuttonState = 0;
int LlastButtonState = HIGH;

int RbuttonState = 0;
int RlastButtonState = HIGH;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(LbuttonPIN, INPUT);
  pinMode(RbuttonPIN, INPUT);
  Serial.println("baud rate is at 9600");
}

void loop() {
  // put your main code here, to run repeatedly:
  leftloop();
  rightloop();

  unsigned long RangeInCentimeters;

if (SensorState == 1) {
  if (RangeInCentimeters >= 20) {
    redLED = 0;
  } else (RangeInCentimeters <= 5); {
    redLED = 2;
  }
}

  RangeInCentimeters = myUltraSonicSensor.distanceRead(); // two measurements 
  Serial.print(RangeInCentimeters); // 0~400cm
  Serial.println(" cm");

}




void leftloop() {
  // LEFT


  int LbuttonPressed = digitalRead(LbuttonPIN);

  if (LlastButtonState == HIGH && LbuttonPressed == LOW) {
    LbuttonState = (LbuttonState + 1) % 3;
  }
  LlastButtonState = LbuttonPressed;

  leftLED = LbuttonState;

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

  if (rightLED == 2) {
    analogWrite(greenLED, 255);
  } else if (rightLED == 1) {
    analogWrite(greenLED, 125);
  } else {
    analogWrite(greenLED, 0);
  }

  int RbuttonPressed = digitalRead(RbuttonPIN);

  if (RlastButtonState == HIGH && RbuttonPressed == LOW) {
    RbuttonState = (RbuttonState + 1) % 3;
  }
  RlastButtonState = RbuttonPressed;

  rightLED = RbuttonState;

  delay(200);
}
