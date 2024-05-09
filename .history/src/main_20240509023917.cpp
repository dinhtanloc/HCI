#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>


/*Nodemcu ESP8266 WIFI control car with the New Blynk app.
   This code created by the SriTu Hobby team.
   Home Page
*/

#define BLYNK_TEMPLATE_ID "TMPL6srJFu3fO"
#define BLYNK_TEMPLATE_NAME "Dinh Tan Loc"
#define BLYNK_AUTH_TOKEN "cyivQ4OhTl262-oZw9W719_Wk-t7rlil"
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;
#define BLYNK_PRINT Serial

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
char ssid[] = "VanNam_5G";
char pass[] = "bemuc123";

int minRange = 312;
int maxRange = 712;
int tocdoxe = 800; 
int distance;
int giatrihongngoai;
int timecho = 1000;
unsigned long thoigian;
unsigned long hientai;
char value;
int Left;
int Right;
int L = 0;
int R = 0;
bool tien_len_flag = true;




void tien(bool flag)
{
  if(flag){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, tocdoxe);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, tocdoxe+300);

  }
}
/********************************** Lùi lại ******************************************/
void lui()
{
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, tocdoxe);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, tocdoxe+300);
}
/********************************** Dừng lại ******************************************/
void dung()
{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 0);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, 0);
}
/********************************** Rẽ trái ******************************************/
void retrai()
{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, tocdoxe);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, tocdoxe);
}
/********************************** Rẽ phải ******************************************/
void rephai()
{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, tocdoxe);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, tocdoxe);
}

BLYNK_WRITE(V0) {
  int x = param[0].asInt();
  int y = param[1].asInt();

 
 if (y < maxRange && y > minRange && x < maxRange && x > minRange) // dừng
 {
   dung(); 
   Serial.println("Dừng");
   digitalWrite(13,LOW);
 }
 else if (y >= maxRange && x >= minRange && x<= maxRange) // tới 
 {
   tien(tien_len_flag); Serial.println("Đang tới");
   digitalWrite(13,HIGH);
  }
 else if (x >= maxRange && y >= minRange && y<=maxRange)// rẽ phải
 { 
  rephai(); Serial.println("Đang rẽ phải");
 }
 
 else if (x<=minRange && y >= minRange && y<=maxRange)// rẽ trái
 { 
  retrai(); Serial.println("Đang rẽ trái");
 }
 
  else if (y <= minRange && x >= minRange && x<= maxRange)// Lui
  {
    lui(); Serial.println("Đang lùi");
  }
  
}

void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(115200);

  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  pinMode(hongngoai1, INPUT);


  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(13,OUTPUT);

  
  Blynk.begin(auth, ssid, pass);
  
}



int ultrasonic() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  long t = pulseIn(Echo, HIGH);
  long cm = t / 29.412 / 2; //time convert distance
  return cm;
}
bool checkdistance() {
  int distance = ultrasonic();
  if (distance <= 15) {
    return false;
  } else {
    return true;
  }
}

void loop() {
  tien_len_flag=checkdistance();
  digitalWrite(13,HIGH);
  delay(200);
  digitalWrite(13,LOW);

  Blynk.run();
  timer.run();
}