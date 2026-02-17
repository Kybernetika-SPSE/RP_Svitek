#include <ESP32Servo.h>

#define THR_PIN 35
#define AIL_PIN 15
#define ELE_PIN 4

#define SER1 22
#define SER2 21
#define ESC 19

Servo servo1, servo2, esc;

int mapCenter(int raw, int minVal, int maxVal, int center) {
  // Mrtvá zóna ±30
  if (raw > center - 30 && raw < center + 30) {
    return 1500;
  }
  
  if (raw >= center) {
    return map(raw, center, maxVal, 1500, 2000);
  } else {
    return map(raw, minVal, center, 1000, 1500);
  }
}

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(AIL_PIN, ADC_11db);
  analogSetPinAttenuation(ELE_PIN, ADC_11db);

  servo1.attach(SER1);
  servo2.attach(SER2);
  esc.attach(ESC);
  servo1.writeMicroseconds(1000);
  esc.writeMicroseconds(1000);
  servo2.writeMicroseconds(1500);
  delay(3000); 
}

void loop() {
  int thrRaw = analogRead(THR_PIN);
  int ailRaw = analogRead(AIL_PIN);
  int eleRaw = analogRead(ELE_PIN);

  int thrPWM = map(thrRaw,0 ,4095, 1000 ,2000);
  int ailPWM = mapCenter(ailRaw, 0, 4095, 2048);
  int elePWM = mapCenter(eleRaw, 0, 4095, 2048);

  esc.writeMicroseconds(thrPWM);
  servo1.writeMicroseconds(ailPWM);
  servo2.writeMicroseconds(elePWM);

  Serial.print(" A:");
  Serial.print(ailPWM);
  Serial.print(" E:");
  Serial.println(elePWM);
  Serial.print(" T:");
  Serial.println(thrPWM);

  delay(20);
}
