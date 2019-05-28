int LED =15;
int bulb=2;


//executed only once
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(bulb,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  digitalWrite(bulb,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  digitalWrite(bulb,LOW);
  delay(1000);
  
  

}
