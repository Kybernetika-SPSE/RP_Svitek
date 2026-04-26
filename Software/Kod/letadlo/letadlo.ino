// Letadlo
#include <ESP32Servo.h>

HardwareSerial HC12(2);

Servo esc;
Servo servoAileronL;
Servo servoAileronR;
Servo servoElevator;

#define ESC_PIN 15
#define AILERON_L_PIN 17
#define AILERON_R_PIN 12
#define ELEVATOR_PIN 13

#define SERVO_MIN 1000
#define SERVO_MAX 2000

struct Data {
  int16_t throttle;
  int16_t pitch;
  int16_t roll;
};

Data packet;
unsigned long lastPacketTime = 0;

void setup() {
  Serial.begin(115200);
  HC12.begin(9600, SERIAL_8N1, 18, 19);
  
  esc.attach(ESC_PIN, 1000, 2000);
  esc.writeMicroseconds(1000);  
  
  Serial.println("ESC init...");
  delay(3000); 
  Serial.println("ESC ready!");

  servoAileronL.attach(AILERON_L_PIN, SERVO_MIN, SERVO_MAX);
  servoAileronR.attach(AILERON_R_PIN, SERVO_MIN, SERVO_MAX);
  servoElevator.attach(ELEVATOR_PIN, SERVO_MIN, SERVO_MAX);
  
  Serial.println("RX READY");
}


void loop() {
  if (HC12.available() >= sizeof(packet)) {
    while (HC12.available() > sizeof(packet)) {
      HC12.read();
    }
    
    HC12.readBytes((uint8_t*)&packet, sizeof(packet));
    
    if (packet.throttle >= 0 && packet.throttle <= 4095 &&
        packet.pitch >= 0 && packet.pitch <= 4095 &&
        packet.roll >= 0 && packet.roll <= 4095) {
      
      int throttle_us = map(packet.throttle, 0, 4095, 1000, 2000);
      int pitch_us = map(packet.pitch, 0, 4095, SERVO_MIN, SERVO_MAX);
      int roll_us = map(packet.roll, 0, 4095, SERVO_MIN, SERVO_MAX);
      
      esc.writeMicroseconds(throttle_us);
      servoElevator.writeMicroseconds(pitch_us);
      servoAileronL.writeMicroseconds(roll_us);
      servoAileronR.writeMicroseconds(roll_us);
      
      Serial.print("T:");
      Serial.print(throttle_us);
      Serial.print(" P:");
      Serial.print(pitch_us);
      Serial.print(" R:");
      Serial.println(roll_us);
      
      lastPacketTime = millis();
    } else {
      Serial.println("INVALID DATA!");
    }
  }
  
  if (millis() - lastPacketTime > 1000) {
    esc.writeMicroseconds(1000);
    servoElevator.writeMicroseconds(1500);
    servoAileronL.writeMicroseconds(1500);
    servoAileronR.writeMicroseconds(1500);
  }
}