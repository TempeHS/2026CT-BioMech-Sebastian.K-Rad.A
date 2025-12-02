const int buttonPin = 6; // Pin where the button is connected
const int buzzerPin = 7; // Pin where the buzzer is connected

void setup() {
    pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
    pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
}

void loop() {
    if (digitalRead(buttonPin) == LOW) { // Check if button is pressed
        tone(buzzerPin, 150); // Play a tone at 1000 Hz
        delay(500); // Play for 500 milliseconds
        noTone(buzzerPin); // Stop the tone
        delay(500); // Wait for a moment before checking again
    }
}