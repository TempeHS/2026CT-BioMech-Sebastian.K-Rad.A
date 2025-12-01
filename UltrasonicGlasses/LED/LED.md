# LED Progress, 1/12/25
## Code Status: Complete
### By using   if (lastButtonState == HIGH && buttonPressed == LOW) {
    buttonState = (buttonState + 1) % 3;
  }   I have sucsseslfully got the LED to cyce through 3 states of brightness
### I copied every variable then assigned them either L (left) or R (right) to make it so I can have two different LEDs operate indpendently