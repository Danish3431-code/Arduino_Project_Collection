// Temperature Monitor Project
// TMP Sensor (Power / Vout / GND) + LED Alert

int tempPin = A0;     // TMP sensor Vout pin
int ledPin = 13;      // LED alert pin

float temperatureC = 0;
float voltage = 0;

float threshold = 30.0;  // agar temp isse zyada ho to LED jal jaye (Celsius)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempPin);

  // Analog value ko voltage me convert karo
  voltage = sensorValue * (5.0 / 1023.0);

  // Voltage ko Celsius me convert karo
  temperatureC = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  if (temperatureC > threshold) {
    digitalWrite(ledPin, HIGH);   // Alert ON
    Serial.println("ALERT! Temperature too high");
  } else {
    digitalWrite(ledPin, LOW);    // Alert OFF
  }

  delay(1000);
}
