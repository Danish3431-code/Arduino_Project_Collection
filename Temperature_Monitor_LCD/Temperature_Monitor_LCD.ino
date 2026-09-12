// Temperature Monitor with LCD Display
// TMP36 -> A0 | Alert LED -> Pin 7 | LCD -> RS12,E11,D4-D7:5,4,3,2
#include <LiquidCrystal.h>
const int sensorPin = A0;
const int ledPin = 7;
const float thresholdTemp = 30.0; // Celsius
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
pinMode(ledPin, OUTPUT);
lcd.begin(16, 2);
lcd.print("Temp Monitor...");
delay(1500);
lcd.clear();
}
void loop() {
int rawValue = analogRead(sensorPin);
float voltage = rawValue * (5.0 / 1023.0);
float temperatureC = (voltage - 0.5) * 100.0;
lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temperatureC);
lcd.print((char)223); // degree symbol
lcd.print("C ");
lcd.setCursor(0, 1);
if (temperatureC > thresholdTemp) {
lcd.print("Status: HIGH! ");
digitalWrite(ledPin, HIGH);
} else {
lcd.print("Status: NORMAL ");
digitalWrite(ledPin, LOW);
}
delay(1000);
}
