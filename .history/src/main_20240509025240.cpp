
#define BLYNK_TEMPLATE_ID "TMPL6srJFu3fO"
#define BLYNK_TEMPLATE_NAME "Dinh Tan Loc"
#define BLYNK_AUTH_TOKEN "cyivQ4OhTl262-oZw9W719_Wk-t7rlil"
#define BLYNK_PRINT Serial
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


/*Nodemcu ESP8266 WIFI control car with the New Blynk app.
   This code created by the SriTu Hobby team.
   Home Page
*/
BlynkTimer timer;






// Include the library files
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "VanNam_5G";
char pass[] = "bemuc123";







BLYNK_WRITE(V0) {
  int x = param[0].asInt();
  int y = param[1].asInt();

 
 if (y < maxRange && y > minRange && x < maxRange && x > minRange) // dừng
 {
   Serial.println("Dừng");
   digitalWrite(13,LOW);
 }
 else if (y >= maxRange && x >= minRange && x<= maxRange) // tới 
 {
   Serial.println("Đang tới");
   digitalWrite(13,HIGH);
  }
 else if (x >= maxRange && y >= minRange && y<=maxRange)// rẽ phải
 { 
  Serial.println("Đang rẽ phải");
 }
 
 else if (x<=minRange && y >= minRange && y<=maxRange)// rẽ trái
 { 
  Serial.println("Đang rẽ trái");
 }
 
  else if (y <= minRange && x >= minRange && x<= maxRange)// Lui
  {
    Serial.println("Đang lùi");
  }
  
}

void setup() {
  // Serial.begin(115200);
  // pinMode(ENA, OUTPUT);
  // pinMode(ENB, OUTPUT); 
  // pinMode(IN1, OUTPUT);
  // pinMode(IN2, OUTPUT);
  // pinMode(IN3, OUTPUT);
  // pinMode(IN4, OUTPUT);
  // Serial.begin(115200);

  // digitalWrite(ENA, LOW);
  // digitalWrite(ENB, LOW);
  // digitalWrite(IN1, LOW);
  // digitalWrite(IN2, LOW);
  // digitalWrite(IN3, LOW);
  // digitalWrite(IN4, LOW);

  // pinMode(hongngoai1, INPUT);


  // pinMode(Trig, OUTPUT);
  // pinMode(Echo, INPUT);
  pinMode(13,OUTPUT);

  
  Blynk.begin(auth, ssid, pass);
  
}




void loop() {
  digitalWrite(13,HIGH);
  delay(200);
  digitalWrite(13,LOW);

  Blynk.run();
  timer.run();
}