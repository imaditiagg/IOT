#define s1=0;
#define s0=2;
void setup() {
  // put your setup code here, to run once:
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  // s1 and s0 should be 0 and 0 in case of potentiometer
  /*digitalWrite(s0,0);
  digitalWrite(s1,0);*/
  Serial.begin(9600);
  // s1 and s0 should be 1 and 1 in case of gas sensor
  digitalWrite(s0,1);
  digitalWrite(s1,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t pot  = AnalogRead(A0);
  Serial.println(pot);
  delay(1000);
}
