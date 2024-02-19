#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "https://esp-firebase-demo-56c74-default-rtdb.asia-southeast1.firebasedatabase.app/dhtt"                          // the project name address from firebase id
#define FIREBASE_AUTH "MJPIUkjrIdlQmJEqbrV9QTM3ZkS4lDdrDIdYKOyE"            // the secret key generated from firebase
#define WIFI_SSID "Tulasi"
#define WIFI_PASSWORD "Tulasi123"

String sensor_data, values;

void setup() {


  delay(1000);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.begin(115200);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() { 
  int sensorValue = analogRead(A0);// read the input on analog pin A0:
  float voltage = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage);
  
 
 
  
}
