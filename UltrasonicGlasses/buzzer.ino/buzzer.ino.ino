#include "Ultrasonic.h"
#include <U8g2lib.h>
#include <Wire.h>

const int BUTTON_PIN = 3;      // Grove D5
const int BUZZER_PIN = 5;      // Grove D6 (PWM)
const int ULTRASONIC_PIN = 8;  // Grove D7

Ultrasonic ultrasonic(ULTRASONIC_PIN);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Initialize OLED display
  //u8g2.begin();
  //u8g2.clearBuffer();
  //u8g2.setFont(u8g2_font_ncenB08_tr);
  //u8g2.drawStr(0, 15, "Ultrasonic Ready!");
  //u8g2.sendBuffer();
  
 //Serial.println("Press button to activate distance-based buzzer pitch!");
 //delay(2000);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  long distance = ultrasonic.RangeInCentimeters();

  // Update OLED display
 // u8g2.clearBuffer();
 // u8g2.setFont(u8g2_font_ncenB14_tr);  // Larger font for distance
 // u8g2.drawStr(0, 25, "Distance:");
 // 
 // // Display distance value
 // char distanceStr[16];
 // sprintf(distanceStr, "%ld cm", distance);
 // u8g2.drawStr(0, 50, distanceStr);
 // 
 // u8g2.sendBuffer();  // Update display

  if (buttonState == LOW) {  // Button pressed (INPUT_PULLUP: LOW = pressed)
    // Map distance (3-100 cm) to frequency (2000-200 Hz)
    // Closer distance = higher pitch UJK
    int freq = map(distance, 3, 100, 500, 100);
    freq = constrain(freq, 100, 500);
    
    tone(BUZZER_PIN, freq);

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | Frequency: ");
    Serial.println(freq);
  } else {
    noTone(BUZZER_PIN);  // Stop buzzer when button released
  }



  delay(50);  // Update rate
}