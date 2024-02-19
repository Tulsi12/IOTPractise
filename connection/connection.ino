void setup() {
// Open serial communications and wait for port to open:
Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
}
void loop() { // run over and over
  //check if data is sent from arduino
if (Serial.available()) {
  //reading the data sent from arduino
Serial.write(Serial.read());
}
}
