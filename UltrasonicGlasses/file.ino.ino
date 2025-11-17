void setup() {
  // put your setup code here, to run once:
  buzzer_setup();
  LED_setup();
  ultrasonicsensor_setup();
}

void loop() {
  // put your main code here, to run repeatedly;
  buzzer();adada
  LED();
  ultrasonicsensor();
  delay(100);
}
