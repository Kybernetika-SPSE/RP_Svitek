#include <ESP32Servo.h>
#define THR_PIN 4
HardwareSerial HC12(2);

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); 
  analogSetPinAttenuation(THR_PIN, ADC_11db);
  HC12.begin(9600, SERIAL_8N1, 16, 17); 
}
void loop() {

  uint16_t thrRaw = analogRead(THR_PIN);
  uint16_t thrPMW = map(thrRaw, 0, 4095, 2000, 1000);

  HC12.write((uint8_t*)&thrPMW, sizeof(thrPMW)); 
  Serial.print("T: ");
  Serial.println(thrPMW);
  delay(20);
}
