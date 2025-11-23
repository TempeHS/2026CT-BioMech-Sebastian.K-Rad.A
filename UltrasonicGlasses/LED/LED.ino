unsigned static int greenLED = 9;
unsigned static int redLED = 5;
unsigned static int buttonPIN = 6; 

int leftLED;
int rightLED;

int lastButtonState = HIGH;  
unsigned long lastDebounceTime = 0;   
unsigned long debounceDelay = 50; 




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(buttonPIN, INPUT_PULLUP);
  Serial.println("baud rate is at 9600");
}




void loop() {
  // put your main code here, to run repeatedly:

  //AI code
    int reading = digitalRead(buttonPIN);

  // Simple debounce logic
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastButtonState == HIGH) {
      // Button was just pressed
      leftLED = (leftLED + 1) % 3;  // Cycle through 0, 1, 2
      Serial.print("leftLED: ");
      Serial.println(leftLED);
    }
  }
  lastButtonState = reading;

//not AI code
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

 delay(100);
}
