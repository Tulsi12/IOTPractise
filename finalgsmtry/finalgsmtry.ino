#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8); // connect gsm modem on this pin

String msg;
int flame_sensor_pin = 4;  //led connected to pin 4
const int aqsensor = A1;  //output of mq135 connected to A1 pin of 
int buz = 9;  //buzzer connected to pin 9
int threshold = 50;      //Threshold level for Air Quality

void setup() {
      Serial.begin(9600);
      mySerial.begin(9600);
      Serial.println("System is Initializing..");
      pinMode (buz,OUTPUT);     // buzzer is connected as Output from Arduino
      pinMode (aqsensor,INPUT); // MQ135 is connected as INPUT to arduino
      pinMode(flame_sensor_pin, INPUT);
      digitalWrite(buz, LOW);
      delay(5000); // wait for 5 seconds
}

void loop() {
      int ppm = analogRead(aqsensor); //read MQ135 analog outputs at A1 and store it in ppm
      Serial.println(ppm);            //print value of ppm in serial monitor      
     

      if (ppm > threshold)            // check is ppm is greater than threshold or not
      {
      msg =  "\n smoke Detected..!";
      sendSMS(msg); 
      Serial.println(msg);    
      digitalWrite(buz,HIGH);     //Turn ON Buzzer
          //Turn ON LED
      delay(5000);
     Serial.println("Hangup Call");

    }
     if (digitalRead(flame_sensor_pin) == 1) {
      mySerial.println("ATD+9779819379321;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
      updateSerial();
      Serial.println("Calling  ");
      delay(50000); // wait for 50 seconds...
      mySerial.println("ATH"); //hang up
      updateSerial();
      Serial.println("Hangup Call");
  
  } 
    
     else
    {
        
      digitalWrite(buz,LOW);   //Turn off Buzzer
      Serial.println("No Fire detected");
    }  
  delay (500);
}

void sendSMS(String message)
{
  mySerial.print("AT+CMGF=1\r");                     // AT command to send SMS message
  updateSerial();
  delay(1000);
  
  mySerial.println("AT + CMGS = \"+9779819379321\"");  // recipient's mobile number, in international format
  updateSerial();
  delay(1000);
  
  mySerial.println(message);                         // message to send
  updateSerial();
  delay(1000);
  
  mySerial.println((char)26);                        // End AT command with a ^Z, ASCII code 26
  updateSerial();
  delay(1000); 
  
  mySerial.println();
  delay(100);                                     // give module time to send SMS
 
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
