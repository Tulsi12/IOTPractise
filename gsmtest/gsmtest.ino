#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8); // connect gsm modem on this pin

char msg;
char call;

int buz = 9;  //buzzer connected to pin 9
 
const int aqsensor = A1;  //output of mq135 connected to A1 pin of Arduino
int threshold = 50;  


int flamePin = 5;

void setup() {
   pinMode (buz,OUTPUT); 
   pinMode (aqsensor,INPUT); 
   pinMode(flamePin, INPUT);
      mySerial.begin(9600);
       
      Serial.println("System is Initializing..");
      digitalWrite(buz, LOW);
     
//      digitalWrite(led, LOW); 
      delay(200); // wait for 2 seconds
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ppm = analogRead(aqsensor); //read MQ135 analog outputs at A1 and store it in ppm
      Serial.println(ppm);            //print value of ppm in serial monitor           

      if (ppm > threshold)            // check is ppm is greater than threshold or not
      {
     mySerial.print("AT+CMGF=1");                     // AT command to send SMS message
     digitalWrite(flamePin, HIGH);
 
      delay(1000);
      
      mySerial.println("AT+CMGS=\"+9779819379321\"\r");  // recipient's mobile number, in international format
    
      delay(1000);
      
      mySerial.println("Warning! smoke detected");                         // message to send
      
      delay(100);
      
      mySerial.println((char)26);                        // End AT command with a ^Z, ASCII code 26
    
      delay(1000); 
  
                     
    }
     else
    {
      //digitalWrite(led,LOW);   //jump here if ppm is not greater than threshold and turn off LED
      digitalWrite(buz,LOW);   //Turn off Buzzer
      Serial.println("No Fire detected");
    }  
  delay (500);

}

void ReceiveMessage(){
  mySerial.println("AT+CNMT=2,2,0,0,0");
  delay(1000);
  if (mySerial.available()>0)
  {
    msg= mySerial.read();
  Serial.print(msg);
  
  }
}

  void MakeCall()
  {
    mySerial.println("ATD+9779819379321;");
    Serial.println("calling");
    delay(1000);
    
  }

  void HangupCall(){
    mySerial.println("ATH");
    Serial.println("Hangup call");
    delay(1000);
  }

    void ReceiveCall(){
      mySerial.println("ATA");
      delay(1000);
      {
        call = mySerial.read();
        Serial.print(call);
        }
    }
    
