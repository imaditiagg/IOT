int LED = D4; // pin number for LED
int button = D7;  // pin number of button

void setup() {
  pinMode(LED, OUTPUT); //set LED as OUTPUT
  pinMode(button, INPUT); //set LED as INPUT
}

void loop() {
  if(digitalRead(button)==1){    // Checking if button is high
    digitalWrite(LED, 1);   // turn the LED 1 ON
  }
  else{
    digitalWrite(LED, 0);     // turn the LED 1 OFF
  }
}
