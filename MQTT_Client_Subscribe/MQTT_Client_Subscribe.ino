#include <ESP8266WiFi.h>
#include <MQTTClient.h>

const char* ssid     = "Aditi";
const char* password = "aditi12345";
WiFiClient WiFiclient;
MQTTClient MQTTclient;
void connectMQTTBroker();

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" WiFi Connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("connecting to MQTT broker...");
  MQTTclient.begin("broker.shiftr.io", WiFiclient);
  MQTTclient.onMessage(messageReceived);
  connectMQTTBroker();
}

void connectMQTTBroker() {
  while (!MQTTclient.connect("adi", "try", "try")) {//subscriber name,username,password
    Serial.print(".");
  }
  Serial.println("connected");
  MQTTclient.subscribe("Temp_Adi");//Topic ka name
}
void loop() {
  MQTTclient.loop();
  if(!MQTTclient.connected()) {
    connectMQTTBroker();
  }
  delay(10);
}
void messageReceived(String &topic, String &payload) {
  Serial.println("Topic: " + topic);
  Serial.println("Data: " + payload);
}
