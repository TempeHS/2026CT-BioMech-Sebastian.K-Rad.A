unsigned static int greenLED = 9;
unsigned static int redLED = 5;
unsigned static int buttonPIN = 6; 

int leftLED = 1;
int rightLED = 2;

//int lastButtonState = HIGH;  
//unsigned long lastDebounceTime = 0;   
//unsigned long debounceDelay = 50; 

// LEFT LED IS RED
// RIGHT LED IS GREEN

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(buttonPIN, INPUT);
  Serial.println("baud rate is at 9600");
}




void loop() {
  // put your main code here, to run repeatedly:
//
// //AI code
//   int reading = digitalRead(buttonPIN);
//
// // Simple debounce logic
// if (reading != lastButtonState) {
//   lastDebounceTime = millis();
// }
//
// if ((millis() - lastDebounceTime) > debounceDelay) {
//   if (reading == LOW && lastButtonState == HIGH) {
//     // Button was just pressed
//     leftLED = (leftLED + 1) % 3;  // Cycle through 0, 1, 2
//     Serial.print("leftLED: ");
//     Serial.println(leftLED);
//   }
// }
// lastButtonState = reading;


//
//int buttonState = digitalRead(buttonPIN);
//if (buttonState != leftLED) {
//  leftLED = buttonState;
//}
//
//int lastButtonState = HIGH; // Tracks previous button state
//  lastButtonState = buttonState;
//  // Detect button press (HIGH to LOW)
//  if (lastButtonState == HIGH && buttonState == LOW) {
//    leftLED = (leftLED + 1) % 3; // Cycle through 0, 1, 2
//  }
//

//Serial.println(buttonState);

 if (rightLED == 2) {
  analogWrite(greenLED, 255); 
 } else if (rightLED == 1) {
  analogWrite(greenLED, 100); 
 } else {
  analogWrite(greenLED, 0); 
 }

 if (leftLED == 2) {
  analogWrite(redLED, 255); 
 } else if (leftLED == 1) {
  analogWrite(redLED, 100); 
 } else {
  analogWrite(redLED, 0); 
 }

 delay(300);
}
