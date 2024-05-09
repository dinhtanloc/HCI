
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

#define ENA   5          // Điều khiển tốc độ động cơ bên trái     GPIO5(D1)
#define ENB   12          // Điều khiển tốc độ động cơ bên phải    GPIO12(D6)
#define IN1  4          // L298N in1 Động cơ trái quay             GPIO4(D2)
#define IN2  0          // L298N in2 Động cơ trái quay ngược lại   GPIO0(D3)
#define IN3  2           // L298N in3 Động cơ phải quay            GPIO2(D4)
#define IN4  14           // L298N in4 Động cơ phải quay ngược lại GPIO14(D5)
#define Echo A0
#define Trig A3
#define hongngoai1 A4




// Include the library files
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Cá mập xanh";
char pass[] = "123456789";

int minRange = 312;
int maxRange = 712;







BLYNK_WRITE(V0) {
  int x = param[0].asInt();
  int y = param[1].asInt();
  Serial.println("--------------");
  Serial.println("x",x);
  Serial.println("--------------");
  Serial.println("y",y);

 
//  if (y < maxRange && y > minRange && x < maxRange && x > minRange) // dừng
//  {
//    Serial.println("Dừng");
//    digitalWrite(13,LOW);
//  }
//  else if (y >= maxRange && x >= minRange && x<= maxRange) // tới 
//  {
//    Serial.println("Đang tới");
//    digitalWrite(13,HIGH);
//   }
//  else if (x >= maxRange && y >= minRange && y<=maxRange)// rẽ phải
//  { 
//   Serial.println("Đang rẽ phải");
//  }
 
//  else if (x<=minRange && y >= minRange && y<=maxRange)// rẽ trái
//  { 
//   Serial.println("Đang rẽ trái");
//  }
 
//   else if (y <= minRange && x >= minRange && x<= maxRange)// Lui
//   {
//     Serial.println("Đang lùi");
//   }
  
}

void setup() {
  Serial.begin(9600);
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
  digitalWrite(13,HIGH);


  
  Blynk.begin(auth, ssid, pass);
  digitalWrite(13,LOW);
  
}




void loop() {
  // digitalWrite(13,HIGH);
  // delay(200);
  // digitalWrite(13,LOW);

  Blynk.run();
  // timer.run();
}