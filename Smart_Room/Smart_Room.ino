// ===== Smart Room Automation =====
// PIR (motion) + LDR (light level) + TMP36 (temperature)
// -> auto room light (LED, PWM) + temperature alert (buzzer)
const int pirPin    = 2;   // PIR OUT (digital)
const int buzzerPin = 8;   // Buzzer +
const int ledPin    = 9;   // LED anode (PWM)
const int ldrPin    = A0;  // LDR voltage divider midpoint
const int tempPin   = A1;  // TMP36 signal
const int darkThreshold = 500;   // below this = "dark" (0-1023 scale)
const float tempAlertC  = 30.0;  // buzzer triggers above this temp
void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int motion = digitalRead(pirPin);
  int ldrValue = analogRead(ldrPin);
  int tempReading = analogRead(tempPin);
  float voltage = tempReading * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;  // TMP36 formula
  // --- Room light logic --
  bool isDark = ldrValue < darkThreshold;
  if (motion == HIGH && isDark) {
    int brightness = map(ldrValue, 0, darkThreshold, 255, 80);
    analogWrite(ledPin, brightness);
  } else {
    analogWrite(ledPin, 0);
  }
  // --- Temperature alert logic --
  if (temperatureC > tempAlertC) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  // --- Debug output --
  Serial.print("Motion: "); Serial.print(motion);
  Serial.print(" | LDR: "); Serial.print(ldrValue);
  Serial.print(" | Temp: "); Serial.print(temperatureC);
  Serial.println(" C");
  delay(300);
}
