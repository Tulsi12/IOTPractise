int flame_sensor_pin= D5; //pin for flame sensor
int buzzer= D6;  //pin fot buuzzer
void setup(){
  Serial.begin(9600);
  pinMode(flame_sensor_pin, INPUT);
//  digitalWrite(flame_sensor_pin, HIGH);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,LOW);
  noTone(buzzer);
}
void loop(){
if (digitalRead(flame_sensor_pin)==LOW){
  Serial.println(digitalRead(flame_sensor_pin));
  Serial.println("Flame lDetected");
  digitalWrite(buzzer, HIGH);
  Serial.println("start");
  delay(3000);
  Serial.println("ATD+9779818189205");
  delay(2000);
//
  Serial.println("ATH");
  delay(1000);
 }
else {
  Serial.println(digitalRead(flame_sensor_pin));
  digitalWrite(buzzer, LOW);  
  noTone(buzzer);
}
}
