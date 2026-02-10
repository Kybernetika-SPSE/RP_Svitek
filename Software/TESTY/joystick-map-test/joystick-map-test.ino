#define X_PIN 34
#define Y_PIN 35
#define LED_X 13
#define LED_Y 12

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); 

void loop() {
  int x = analogRead(X_PIN);
  int y = analogRead(Y_PIN);

  int xLed = map(x, 0, 4095, 0, 255);
  int yLed = map(y, 0, 4095, 0, 255);

  analogWrite(LED_X, xLed);
  analogWrite(LED_Y, yLed);

  Serial.print("X: "); Serial.print(x);
  Serial.print("  Y: "); Serial.println(y);
  Serial.print("X: "); Serial.print(xLed);
  Serial.print("  Y: "); Serial.println(yLed);


  delay(20);
}
