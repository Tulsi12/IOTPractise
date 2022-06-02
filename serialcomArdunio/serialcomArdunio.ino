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
  //printing a simple text in arduino
Serial.println("Helloworld");

  //sending data to nodemcu
espSerial.println("Helloworld");
delay(1000);
}
