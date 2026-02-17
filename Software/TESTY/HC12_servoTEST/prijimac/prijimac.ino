#include <ESP32Servo.h>

#define SER 14 

Servo servo1;

HardwareSerial HC12(2);

void setup() {
  Serial.begin(115200);

  servo1.attach(SER);

  HC12.begin(9600, SERIAL_8N1, 1,2); 

  servo1.writeMicroseconds(1500);
  delay(3000); 
}

void loop() {
  if(HC12.available()){
    uint16_t thrPMW;
    HC12.readBytes((uint8_t*)&thrPMW, sizeof(thrPMW)); // přečti 2 bajty
    servo1.writeMicroseconds(thrPMW);
    Serial.print("T přijato : ");
    Serial.println(thrPMW);
    delay(20);
  }

  


}

// Motor se vskutku točí. Akorát sem špatně připájel kabely motoru na ESC takže se točí opačně....
