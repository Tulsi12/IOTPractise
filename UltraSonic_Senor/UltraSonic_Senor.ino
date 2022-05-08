int trigPin = 4;
int ecoPin = 3;
int led1 = 8;
int led2 = 9;
int pingtime;
int inches = 0;
int cm = 0;

long readUltasonicDistance(){
  pinMode(trigPin,OUTPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  pinMode(ecoPin,INPUT);
  return pulseIn(ecoPin,HIGH);
}


void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}


void loop() {
  cm = 0.01723 * readUltasonicDistance();
  inches = (cm/2.54);
  Serial.print("inches:");
  Serial.println(inches);
  Serial.print("cm:");
  Serial.println(cm);
  if(cm<=5){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
}
else{
  digitalWrite(led2,HIGH);
  digitalWrite(led1,LOW);
}
  delay(100);
}
