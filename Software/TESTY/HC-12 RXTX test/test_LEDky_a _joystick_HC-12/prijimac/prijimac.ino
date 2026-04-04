void setup() {
  USBSerial.begin(115200);
  delay(2000);
  USBSerial.println("Test USBSerial");
}

void loop() {
  USBSerial.println("Loop");
  delay(1000);
}