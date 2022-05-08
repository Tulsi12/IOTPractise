int pirPin = 8;
int led = 9;

void setup() {
// put your setup code here, to run once:
pinMode(pirPin, INPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);

}

void loop() {
// put your main code here, to run repeatedly:
if (digitalRead(pirPin)==HIGH){
digitalWrite(led, HIGH);
}
else {
digitalWrite(led, LOW);
}
delay(5);
}
