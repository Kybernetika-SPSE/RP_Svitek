#include <ESP32Servo.h>

#define THR_PIN 4 
#define ESC_PIN 19   

Servo esc;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(THR_PIN, ADC_11db);

  esc.attach(ESC_PIN);

  esc.writeMicroseconds(1000);
  delay(3000); 
}

void loop() {
  int raw = analogRead(THR_PIN);      
  int pwm = map(raw, 0, 4095, 500, 2500); 

  pwm = constrain(pwm, 500, 2500);

  esc.writeMicroseconds(pwm);

  Serial.print("PWM: ");
  Serial.println(pwm);
  delay(20);
}

// Motor se vskutku točí. Akorát sem špatně připájel kabely motoru na ESC takže se točí ve špatném směru....
