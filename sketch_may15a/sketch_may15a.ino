#include <LiquidCrystal.h>
LiquidCrystal LCD(9,10,5,4,3,2);

int trig = 12;
int echo = 11;
int count = 0;
//int servo = 6;
float pingTime;
float distance;
float sSpeed = 0.034; //cm/s

void setup() {
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
LCD.begin(16,2);
LCD.setCursor(0,0);
LCD.print("Target Distance:");
}

void loop() {
digitalWrite(trig, LOW);
delayMicroseconds(2000);
digitalWrite(trig, HIGH);
delayMicroseconds(15);
digitalWrite(trig, LOW);
delayMicroseconds(10);

pingTime = pulseIn(echo, HIGH);
distance = sSpeed * pingTime/2;

LCD.setCursor(0,1);//second row
LCD.print(" ");
LCD.setCursor(0,1);
LCD.print(distance);
LCD.print(" cm");
delay(250);
}
