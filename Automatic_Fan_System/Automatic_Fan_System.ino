// Automatic Fan System using TMP36
// TMP36 -> A0 | Motor (via transistor) -> Pin 9
 
const int sensorPin = A0;
const int fanPin = 9;
const float thresholdTemp = 28.0; // Celsius - fan ON hone ka threshold
 
void setup() {
pinMode(fanPin, OUTPUT);
Serial.begin(9600);
}
 
void loop() {
int rawValue = analogRead(sensorPin);
float voltage = rawValue * (5.0 / 1023.0);
float temperatureC = (voltage - 0.5) * 100.0;
 
Serial.print("Temperature: ");
Serial.print(temperatureC);
Serial.println(" C");
 
if (temperatureC > thresholdTemp) {
digitalWrite(fanPin, HIGH); // Fan ON
Serial.println("Fan: ON");
} else {
digitalWrite(fanPin, LOW); // Fan OFF
Serial.println("Fan: OFF");
}
 
delay(1000);
}
