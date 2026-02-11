// TX
#define THR_PIN 34

HardwareSerial HC12(2);

void setup() {
  Serial.begin(115200);

  analogReadResolution(12); 
  analogSetPinAttenuation(THR_PIN, ADC_11db);

  HC12.begin(9600, SERIAL_8N1, 16, 17); 
}

void loop() {

  int raw = analogRead(THR_PIN);  
  if(raw < 150){raw = 0;}
  if(raw > 4000){raw = 4095;}
  uint8_t val = map(raw, 0, 4095, 0, 255);

  

  HC12.write(val);    

  Serial.print("raw="); Serial.print(raw);
  Serial.print("  send="); Serial.println(val);

  delay(20);
} 
// funguje to (viz foto)
