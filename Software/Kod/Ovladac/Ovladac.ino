#define THR_PIN 34
#define PITCH_PIN 35
#define ROLL_PIN 32

HardwareSerial HC12(2);

struct ControlData {
  uint16_t throttle;
  uint16_t pitch;
  uint16_t roll;
};

ControlData data;

void setup() {
  Serial.begin(115200);
  HC12.begin(9600, SERIAL_8N1, 16, 17);
  
  pinMode(THR_PIN, INPUT);
  pinMode(PITCH_PIN, INPUT);
  pinMode(ROLL_PIN, INPUT);
  
  Serial.println("TRANSMITTER READY");
}

void loop() {
  data.throttle = analogRead(THR_PIN);
  data.pitch = analogRead(PITCH_PIN);
  data.roll = analogRead(ROLL_PIN);
  
  HC12.write((uint8_t*)&data, sizeof(data));
  
  Serial.print("T:");
  Serial.print(data.throttle);
  Serial.print(" P:");
  Serial.print(data.pitch);
  Serial.print(" R:");
  Serial.println(data.roll);
  
  delay(50);
}