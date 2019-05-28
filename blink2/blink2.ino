int LED =15;
int bulb=2;
int buzzer=14;
//executed only once
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(bulb,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  //alternating LED's
  /*digitalWrite(LED,HIGH);
  digitalWrite(bulb,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  digitalWrite(bulb,LOW);
  delay(1000);*/
  //buzzer in 2 sec and LED in 1 second
  digitalWrite(LED,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
  digitalWrite(LED,HIGH);
  digitalWrite(buzzer,LOW);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
}
