/*Nodemcu ESP8266 WIFI control car with the New Blynk app.
   This code created by the SriTu Hobby team.
   Home Page
*/

// Include the library files
#define BLYNK_TEMPLATE_ID "TMPL6srJFu3fO"
#define BLYNK_TEMPLATE_NAME "Dinh Tan Loc"
#define BLYNK_AUTH_TOKEN "cyivQ4OhTl262-oZw9W719_Wk-t7rlil"
#define BLYNK_PRINT Serial
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


// Define the motor pins
#define ENA 12
#define IN1 5
#define IN2 4
#define IN3 10
#define IN4 9
#define ENB 8

// Variables for the Blynk widget values
// int x = 50;
// int y = 50;
int Speed;
int a;
int b;

char auth[] = BLYNK_AUTH_TOKEN; //Enter your Blynk auth token
char ssid[] = "Van Nam_5G"; //Enter your WIFI name
char pass[] = "bemuc123"; //Enter your WIFI passowrd


void setup() {
  Serial.begin(9600);
  //Set the motor pins as output pins
  // pinMode(ENA, OUTPUT);
  // pinMode(IN1, OUTPUT);
  // pinMode(IN2, OUTPUT);
  // pinMode(IN3, OUTPUT);
  // pinMode(IN4, OUTPUT);
  // pinMode(ENB, OUTPUT);

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass);
}

// Get the joystick values
BLYNK_WRITE(V0) {
  int x = param[0].asInt();
  a=x;
}
// Get the joystick values
BLYNK_WRITE(V1) {
  int y = param[0].asInt();
  b=y;
}
//Get the slider values
BLYNK_WRITE(V2) {
  Speed = param.asInt();
}

// Check these values using the IF condition

/**************Motor movement functions*****************/
void carForward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carBackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void smartcar() {

  // if (y > 70) {
  //   carForward();
  //   Serial.println("carForward");
  // } else if (y < 30) {
  //   carBackward();
  //   Serial.println("carBackward");
  // } else if (x < 30) {
  //   carLeft();
  //   Serial.println("carLeft");
  // } else if (x > 70) {
  //   carRight();
  //   Serial.println("carRight");
  // } else if (x < 70 && x > 30 && y < 70 && y > 30) {
  //   carStop();
  //   Serial.println("carstop");
  // }
}
void loop() {
  Blynk.run();// Run the blynk function
  Serial.print("x:");Serial.println(a);
  Serial.print("y:");Serial.println(b);
  if (b > 70) {
    carForward();
    Serial.println("carForward");
  } else if (b < 30) {
    carBackward();
    Serial.println("carBackward");
  } else if (a< 30) {
    carLeft();
    Serial.println("carLeft");
  } else if (a > 70) {
    carRight();
    Serial.println("carRight");
  } else if (a < 70 && a > 30 && b < 70 && b > 30) {
    carStop();
    Serial.println("carstop");}
}