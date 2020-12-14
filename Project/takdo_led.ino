#include <stdio.h>

int ledPin_Red = 11;
int ledPin_Orange = 12;
int ledPin_Green = 13;
int sensor_in = 2;

String cmd = "temp";
String input = "";
String color - "";

void setup() {
Serial.begin(9600);
pinMode(ledPin_Red, OUTPUT);
pinMode(ledPin_Orange, OUTPUT);
pinMode(ledPin_Green, OUTPUT);
pinMode(sensor_in, INPUT);
}
void loop() {
int sensorValue = analogRead(A0);
float voltage = sensorValue * (5.0 / 1024.0);

if(voltage<3.5) {
digitalWrite(ledPin_Red, HIGH);
digitalWrite(ledPin_Orange, LOW);
digitalWrite(ledPin_Green, LOW);
color = "red";
}
else if(voltage>=3.5 && voltage<4) {
digitalWrite(ledPin_Red, LOW);
digitalWrite(ledPin_Orange, HIGH);
digitalWrite(ledPin_Green, LOW);
color = "orange";
}
else {
digitalWrite(ledPin_Red, LOW);
digitalWrite(ledPin_Orange, LOW);
digitalWrite(ledPin_Green, HIGH);
color = "green";
}

Serial.println(voltage + " - " + color);

if(Serial.available()) {
input = Serial.readStringUntil('\n');
}
if(Serial.available() == 0 && input == cmd) {
Serial.print(voltage + " - " + color);
Serial.println();
input = "";
color = "";
}
delay(500);
}
