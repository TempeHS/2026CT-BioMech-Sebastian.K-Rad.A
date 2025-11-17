// Define the pins for the button and the buzzer
const int buttonPin = 2; // Connect the button to digital pin 2
const int buzzerPin = 3; // Connect the buzzer to digital pin 3

void setup() {
  // Initialize the button pin as an input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP); 
  // Initialize the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the button
  // INPUT_PULLUP means the button will read LOW when pressed
  int buttonState = digitalRead(buttonPin);

  // Check if the button is pressed (LOW state)
  if (buttonState == LOW) {
    // If pressed, turn on the buzzer with a specific tone (e.g., 1000 Hz)
    tone(buzzerPin, 1000); 
  } else {
    // If not pressed, turn off the buzzer
    noTone(buzzerPin);
  }
}