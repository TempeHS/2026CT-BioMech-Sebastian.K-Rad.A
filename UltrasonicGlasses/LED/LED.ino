
unsigned static int redLED = 4;
unsigned static int buttonPIN = 6; 
int onSTATE = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (onSTATE == 2) {
  analogWrite(redLED, 255); 
 } else if (onSTATE == 1) {
  analogWrite(redLED, 100); 
 } else {
  analogWrite(redLED, 0); 
 }

 delay(100);
}
