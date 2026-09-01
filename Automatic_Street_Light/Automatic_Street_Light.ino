// C++ code
int LightSensor = 0;
int threshold = 500;   // is value se neeche = raat/andhera samjho
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}
void loop()
{
  LightSensor = analogRead(A0);
  Serial.println(LightSensor);
  if (LightSensor < threshold) {
    // andhera hai (raat) -> light ON
    digitalWrite(5, HIGH);
  } else {
    // roshni hai (din) -> light OFF
    digitalWrite(5, LOW);
  }
  delay(10);
}
