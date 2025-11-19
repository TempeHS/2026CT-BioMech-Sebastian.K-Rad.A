  // Library for Grove Ultrasonic Ranger

const int BUTTON_PIN = 5;    // Grove D5
const int BUZZER_PIN = 6;    // Grove D6 (PWM)
const int ULTRASONIC_PIN = 7; // Grove D7

Ultrasonic ultrasonic(ULTRASONIC_PIN); // Create ultrasonic object

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.println("Press button to buzz with pitch based on distance!");
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    long distance = ultrasonic.MeasureInCentimeters();
    // Map distance (e.g., 3-100 cm) to frequency (e.g., 200-2000 Hz)
    int freq = map(distance, 3, 100, 200, 2000);
    freq = constrain(freq, 200, 2000); // Keep frequency in range
    tone(BUZZER_PIN, freq);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | Frequency: ");
    Serial.println(freq);
  } else {
    noTone(BUZZER_PIN); // Stop buzzer
  }

  delay(50); // Debounce
}