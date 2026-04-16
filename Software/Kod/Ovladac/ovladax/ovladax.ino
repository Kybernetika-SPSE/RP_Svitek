// Ovladač
#define THROTTLE_PIN 34
#define PITCH_PIN 35
#define ROLL_PIN 32
#define YAW_PIN 33

HardwareSerial HC12(2);

struct Data {
  int16_t throttle;
  int16_t pitch;
  int16_t roll;
  int16_t yaw;
};

Data packet;

void setup() {
  Serial.begin(115200);
  HC12.begin(9600, SERIAL_8N1, 16, 17);
  
  pinMode(THROTTLE_PIN, INPUT);
  pinMode(PITCH_PIN, INPUT);
  pinMode(ROLL_PIN, INPUT);
  pinMode(YAW_PIN, INPUT);
  
  Serial.println("TX READY");
}

void loop() {
  packet.throttle = analogRead(THROTTLE_PIN);
  packet.pitch = analogRead(PITCH_PIN);
  packet.roll = analogRead(ROLL_PIN);
  packet.yaw = analogRead(YAW_PIN);
  
  HC12.write((uint8_t*)&packet, sizeof(packet));
  
  Serial.print("T:");
  Serial.print(packet.throttle);
  Serial.print(" P:");
  Serial.print(packet.pitch);
  Serial.print(" R:");
  Serial.print(packet.roll);
  Serial.print(" Y:");
  Serial.println(packet.yaw);
  
  delay(50);
}