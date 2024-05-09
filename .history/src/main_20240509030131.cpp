#include <Arduino.h>
#include <WiFi.h>
// #include<ESP8266WebServer.h>
// ESP8266WebServer webServer(60);
const char* ssid="VanNam";
const char* pass="bemuc123";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print(" ");
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED){
  delay(500);
  Serial.print("...");
  }
  Serial.println(" ");
  Serial.println("WiFi connected ");
  Serial.print("iP Address");
  Serial.print(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:

}
