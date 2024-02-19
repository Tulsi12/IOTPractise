#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8); // connect gsm modem on this pin


int buz = 9;  //buzzer connected to pin 9
int led = 4;  //led connected to pin 4

const int aqsensor = A1;  //output of mq135 connected to A1 pin of Arduino
int threshold = 50;      //Threshold level for Air Quality



void setup()
{
   pinMode (buz,OUTPUT); 
   pinMode (aqsensor,INPUT); 
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM900
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  


}

void loop()
{
  int ppm = analogRead(aqsensor); //read MQ135 analog outputs at A1 and store it in ppm
      Serial.println(ppm);            //print value of ppm in serial monitor           

      if (ppm > threshold)            // check is ppm is greater than threshold or not
      {mySerial.println("AT"); //Handshaking with SIM900
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+9779819379321\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("firee detected!"); //text content
  updateSerial();
  mySerial.write(26);}
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
