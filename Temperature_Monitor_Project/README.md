# Temperature Monitor Project

Arduino Uno + TMP Sensor (Power / Vout / GND) + LED Alert System

## Project Overview

Ye Arduino based temperature monitoring project hai jisme ek TMP sensor ambient temperature ko continuously read karta hai. Jab temperature ek fixed threshold se zyada ho jata hai, to ek amber LED alert ke tor par jal uthti hai. Poora temperature data Serial Monitor par bhi real-time dikhaya jata hai. Circuit Tinkercad par design aur simulate kiya gaya hai.

## Components Used

| Component | Purpose |
|---|---|
| Arduino Uno R3 | Brain of the circuit; sensor data read karta hai aur LED ko control karta hai |
| TMP Temperature Sensor | Ambient temperature ko analog voltage (Vout) mein convert karta hai |
| LED (Amber) | Jab temperature threshold se cross ho, visual alert ke tor par jalti hai |
| Resistor (220 ohm) | LED tak current limit karta hai taake wo burn na ho |
| Jumper wires | Red = 5V, Black = GND, Orange = A0 (Vout), Green = Pin 13 (LED) |

## TMP Sensor Pinout (Tinkercad Labels)

| Pin | Connection |
|---|---|
| Pin 1 (Power) | Arduino 5V |
| Pin 2 (Vout) | Arduino A0 |
| Pin 3 (GND) | Arduino GND |

## Circuit Wiring

- TMP sensor Power → Arduino 5V (red wire)
- TMP sensor GND → Arduino GND (black wire)
- TMP sensor Vout → Arduino A0 (orange wire)
- LED anode → Arduino Pin 13 (green wire)
- LED cathode → 220 ohm resistor → Arduino GND

Poora circuit diagram aur detailed build steps `Temperature_Monitor_Project.pdf` file mein maujood hain.

## How It Works

1. TMP sensor ambient temperature ko analog voltage (Vout) ki shakal mein Arduino ke A0 pin par bhejta hai.
2. Arduino us analog value ko voltage mein convert karta hai, phir voltage ko Celsius temperature mein convert karta hai.
3. Ye temperature Serial Monitor par har second print hota hai.
4. Agar temperature **30°C** (threshold) se zyada ho jaye, to Pin 13 wali amber LED ON ho jati hai aur "ALERT! Temperature too high" message Serial Monitor par show hota hai.
5. Jab temperature dobara threshold se neeche aa jaye, LED automatically OFF ho jati hai.

## Code

Poora Arduino code `Temperature_Monitor.ino` file mein hai. Ye Tinkercad ke code editor mein paste kar ke run kiya ja sakta hai.

## How to Run

1. Tinkercad.com par jayein aur naya circuit banayein
2. Arduino Uno R3, TMP Sensor, LED, aur ek 220 ohm resistor add karein
3. Diagram aur wiring summary ke mutabiq connections banayein
4. `Temperature_Monitor.ino` ka code Arduino mein paste karein
5. "Start Simulation" dabayein, TMP sensor par click kar ke temperature change karein, aur LED + Serial Monitor ka response dekhein

## Wiring Summary

| From | To | Wire Color |
|---|---|---|
| TMP Power | Arduino 5V | Red |
| TMP GND | Arduino GND | Black |
| TMP Vout | Arduino A0 | Orange |
| LED Anode | Arduino Pin 13 | Green |
| LED Cathode | 220 ohm resistor → Arduino GND | Black |

## Files in This Folder

- `Temperature_Monitor.ino` — Arduino source code
- `Temperature_Monitor_Project.pdf` — Full documentation with circuit diagram
- Circuit screenshot image
