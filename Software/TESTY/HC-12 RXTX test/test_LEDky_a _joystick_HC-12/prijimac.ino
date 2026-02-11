//RX

#define LED_PIN 7

HardwareSerial HC12(2);

void setup() {
  Serial.begin(115200);

  HC12.begin(9600, SERIAL_8N1, 5, 6); 

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (HC12.available()) {
    uint8_t val = HC12.read(); 
    analogWrite(LED_PIN, val);   
    Serial.print("recv="); Serial.println(val);
  }
}
