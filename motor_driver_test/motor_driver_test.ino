
#define enA 3
#define in1 4
#define in2 5
int value = 100;
#define COFFEE_MOVE_FORWARD 'w'
#define COFFEE_MOVE_BACK 's'

#define TEA_MOVE_FORWARD 'r'
#define TEA_MOVE_BACK 'f'

#define FULL_STOP 'e'

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //  pinMode(enB, OUTPUT);
  //  pinMode(in3, OUTPUT);
  //  pinMode(in4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  char byte = 0;

  Serial.readBytes(&byte, 1);
  if (byte == COFFEE_MOVE_FORWARD) {
    analogWrite(enA, value);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(1000);
    Serial.print("move forward \n");
    byte = 0;
  }
  if (byte == COFFEE_MOVE_BACK) {
    analogWrite(enA, value);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1000);
    Serial.print("move backward \n");
    byte = 0;
  }

  if (byte == TEA_MOVE_FORWARD) {
    analogWrite(enA, value);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(1000);
    Serial.print("move forward \n");
    byte = 0;
  }
  if (byte == TEA_MOVE_BACK) {
    analogWrite(enA, value);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(1000);
    Serial.print("move backward \n");
    byte = 0;
  }
  if (byte == FULL_STOP) {
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(1000);
    Serial.print("stop \n");
    byte = 0;
  }
}
