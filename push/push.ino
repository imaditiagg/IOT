int LED =D8;
int button = D0;
int buzzer=14;


void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // turn on buzzer when push button is pressed and glow LED when button is not pressed
 if(digitalRead(button)==0){
  digitalWrite(buzzer,LOW);
  digitalWrite(LED,LOW);
 }
  else{
  digitalWrite(LED,HIGH);
  digitalWrite(buzzer,HIGH);
  
  }
}
