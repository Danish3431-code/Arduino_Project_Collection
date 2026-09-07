DISTANCE METER (BASIC) - ARDUINO + HC-SR04
============================================

Overview
--------
This project uses an Arduino Uno R3 and an HC-SR04 ultrasonic sensor to
measure distance to the nearest object. The result is printed to the
Serial Monitor in centimeters, updated every 500 milliseconds.

Simulated in Tinkercad. Works on real hardware too.


Components Used
----------------
- Arduino Uno R3            x1
- HC-SR04 Ultrasonic Sensor x1
- Breadboard                x1
- Jumper Wires               as needed
- USB Cable                 x1


Wiring
------
HC-SR04 VCC   -> Arduino 5V
HC-SR04 GND   -> Arduino GND
HC-SR04 Trig  -> Arduino Pin 9
HC-SR04 Echo  -> Arduino Pin 10

See circuit-diagram.png for the full wiring diagram (white background,
color-coded wires: red = 5V, black = GND, blue = Trig, purple = Echo).


How to Build (Tinkercad)
-------------------------
1. Open Tinkercad Circuits and create a new circuit.
2. Add an Arduino Uno R3 and a Breadboard.
3. Add an HC-SR04 Ultrasonic Sensor onto the breadboard.
4. Wire the components as shown above.
5. Open the code editor and paste in Distance_Meter_Basic.ino.
6. Click Start Simulation, then open the Serial Monitor to see
   live distance readings in cm.


How to Build (Real Hardware)
------------------------------
1. Wire the HC-SR04 sensor to the Arduino as shown above.
2. Open Distance_Meter_Basic.ino in the Arduino IDE.
3. Select Board: Arduino Uno, and the correct Port.
4. Click Upload.
5. Open the Serial Monitor (baud rate 9600) to see live readings.


Full Arduino Code
------------------
#define trigPin 9
#define echoPin 10

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}

(Full sketch also included separately as Distance_Meter_Basic.ino)


How It Works
------------
1. Arduino sends a 10 microsecond HIGH pulse on the Trig pin, which
   makes the HC-SR04 emit an ultrasonic (40kHz) sound wave.
2. The sound wave hits the nearest object and bounces back.
3. The sensor holds its Echo pin HIGH for as long as it takes the
   sound wave to make the round trip.
4. Arduino's pulseIn() function measures how long the Echo pin
   stayed HIGH (in microseconds) - this is the "duration".
5. Distance is calculated as:
       distance = duration * 0.034 / 2
   (0.034 cm/microsecond is the speed of sound; divide by 2 because
   the wave travels there and back.)
6. This repeats every 500 milliseconds, printing a new reading to
   the Serial Monitor each time.


Files in This Project
-----------------------
Distance_Meter_Basic.ino  - standalone Arduino sketch
README.txt                - this file
circuit-diagram.png       - wiring diagram (white background)


License
-------
Free to use, modify, and share for personal or educational projects.


Built with Arduino Uno R3 + Tinkercad
