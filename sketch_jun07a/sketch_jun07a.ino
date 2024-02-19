
//Library for serial communication
#include <SoftwareSerial.h>

//rx and tx pin connecting arduino and nodemcu
SoftwareSerial espSerial(5, 6);

void setup(){
Serial.begin(115200);
//begin serial for nodemcu
espSerial.begin(115200);
delay(2000);
}
void loop()
{
int sensorValue = analogRead(A0);// read the input on analog pin A0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print out the value you read:
  delay(500);

  //sending data to nodemcu
espSerial.println(voltage);
delay(1000);
}




//#include <SoftwareSerial.h>
//
////rx and tx pin connecting arduino and nodemcu
//SoftwareSerial espSerial(5, 6);
//
//void setup(){
//Serial.begin(115200);
////begin serial for nodemcu
//espSerial.begin(115200);
//delay(2000);
//}
//void loop()
//{
//  int sensorValue = analogRead(A0);// read the input on analog pin A0:
//  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
//  Serial.println(voltage); // print out the value you read:
//  delay(500);
// 
//  //sending data to nodemcu
//espSerial.println("voltage");
//delay(1000);
//}
