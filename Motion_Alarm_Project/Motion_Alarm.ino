// Motion Alarm Project
// Parallax PIR Sensor + Buzzer + LED

int pirPin = 2;      // PIR sensor output pin
int buzzerPin = 8;    // Buzzer pin
int ledPin = 13;      // LED pin

int motionState = LOW;   // current motion status

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  motionState = digitalRead(pirPin);

  if (motionState == HIGH) {
    // Motion detected -> alarm on
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion Detected! Alarm ON");
  } else {
    // No motion -> alarm off
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    Serial.println("No Motion");
  }

  delay(500); // thora sa delay taake readings stable rahen
}
