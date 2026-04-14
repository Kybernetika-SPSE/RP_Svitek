#include <ESP32Servo.h>

HardwareSerial HC12(1);

Servo esc;
Servo servoAileronL;
Servo servoAileronR;
Servo servoElevator;

#define ESC_PIN 14
#define AILERON_L_PIN 10
#define AILERON_R_PIN 11
#define ELEVATOR_PIN 13

#define SERVO_MIN 500
#define SERVO_MAX 2500

struct ControlData {
  uint16_t throttle;
  uint16_t pitch;
  uint16_t roll;
};

ControlData data;
unsigned long lastPacketTime = 0;

void setup() {
  Serial.begin(115200);
  while(!Serial) delay(100);
  
  HC12.begin(9600, SERIAL_8N1, 18, 17);
  
  esc.attach(ESC_PIN, 1000, 2000);
  servoAileronL.attach(AILERON_L_PIN, SERVO_MIN, SERVO_MAX);
  servoAileronR.attach(AILERON_R_PIN, SERVO_MIN, SERVO_MAX);
  servoElevator.attach(ELEVATOR_PIN, SERVO_MIN, SERVO_MAX);
  
  esc.writeMicroseconds(1000);
  delay(2000);
  
  Serial.println("RECEIVER READY");
}

void loop() {
  if (HC12.available() >= sizeof(data)) {
    HC12.readBytes((uint8_t*)&data, sizeof(data));
    
    int throttle_us = map(data.throttle, 0, 4095, 1000, 2000);
    int pitch_us = map(data.pitch, 0, 4095, SERVO_MIN, SERVO_MAX);
    int roll_us = map(data.roll, 0, 4095, SERVO_MIN, SERVO_MAX);
    
    esc.writeMicroseconds(throttle_us);
    servoElevator.writeMicroseconds(pitch_us);
    servoAileronL.writeMicroseconds(roll_us);
    servoAileronR.writeMicroseconds(SERVO_MAX - (roll_us - SERVO_MIN) + SERVO_MIN);
    
    Serial.print("T:");
    Serial.print(throttle_us);
    Serial.print(" P:");
    Serial.print(pitch_us);
    Serial.print(" R:");
    Serial.println(roll_us);
    
    lastPacketTime = millis();
  }
  
  if (millis() - lastPacketTime > 1000) {
    esc.writeMicroseconds(1000);
    servoElevator.writeMicroseconds(1500);
    servoAileronL.writeMicroseconds(1500);
    servoAileronR.writeMicroseconds(1500);
  }
}