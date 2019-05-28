int LED = D7;
int button =16;
int buzzer=14;
int bulb = 12;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(button,INPUT);
  //pinMode(buzzer, OUTPUT);
  pinMode(bulb,OUTPUT);
  
}

void loop() {
  if(digitalRead(button)==0) //high brightness when push button is pressed
  analogWrite(bulb, 1032);    
  else
  analogWrite(bulb, 255);    // wait for a second
  
/*
  analogWrite(LED, 255); 
  //digitalWrite(buzzer,LOW);
  analogWrite(buzzer, 255);
  delay(1000);
  analogWrite(LED, 150);
  //digitalWrite(buzzer,HIGH);
  analogWrite(buzzer, 150);
  delay(1000);*/
}
