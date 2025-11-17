
unsigned static int redLED = 4;
unsigned static int buttonPIN = 6; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
 if onSTATE == true {
  then redLED = HIGH
 } else {
  onSTATE = true
 }
}
