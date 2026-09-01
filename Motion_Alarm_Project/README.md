# Motion Alarm Project

Arduino Uno + PIR Motion Sensor + Buzzer + LED

## Project Overview

Ye project ek PIR (Passive Infrared) motion sensor ka istemal karke movement detect karta hai. Jab motion detect hoti hai, PIR sensor Arduino ke digital pin 2 par HIGH signal bhejta hai. Arduino phir buzzer aur red LED ko automatically ON kar deta hai. Jab movement nahi hoti, dono OFF rehte hain. Decision logic simple if/else condition par based hai. Circuit Tinkercad par design aur simulate kiya gaya hai.

## Components Used

| # | Component | Quantity | Purpose |
|---|---|---|---|
| 1 | Arduino Uno R3 | 1 | Main microcontroller board |
| 2 | PIR Motion Sensor (HC-SR501) | 1 | Movement / human motion detect karta hai |
| 3 | Buzzer (piezo buzzer) | 1 | Warning alarm sound produce karta hai |
| 4 | LED (Red) | 1 | Visual warning indicator |
| 5 | Resistor - 220 ohm | 1 | LED ke liye current-limiting resistor |
| 6 | Breadboard | 1 | Components ko hold aur connect karne ke liye |
| 7 | Jumper wires | as needed | Components ke darmiyan connections |

## Circuit Wiring

- PIR Sensor VCC → Arduino 5V
- PIR Sensor GND → Arduino GND
- PIR Sensor OUT → Arduino Digital Pin 2
- Buzzer Positive (+) → Arduino Digital Pin 8
- Buzzer Negative (-) → Arduino GND
- LED Anode (lambi leg) → Arduino Pin 13
- LED Cathode (choti leg) → 220 ohm resistor → Arduino GND

Poora circuit diagram aur detailed build steps `Motion_Alarm_Project.pdf` file mein maujood hain.

## How It Works

1. **Motion Detection** — PIR sensor human/movement detect karta hai aur Pin 2 par HIGH signal bhejta hai.
2. **Arduino Decision** — Arduino `digitalRead(pirPin)` se sensor ki state read karta hai.
3. **Alarm ON** — Agar state HIGH ho, Arduino buzzer aur LED ko HIGH kar ke ON kar deta hai.
4. **Alarm OFF** — Agar state LOW ho, Arduino buzzer aur LED ko LOW kar ke OFF rakhta hai.
5. **Serial Monitor** — Arduino status print karta hai: "Motion Detected! Alarm ON" ya "No Motion".

## Code

Poora Arduino code `Motion_Alarm.ino` file mein hai. Ye Tinkercad ke code editor mein paste kar ke run kiya ja sakta hai.

## How to Run

1. Tinkercad.com par jayein aur naya circuit banayein
2. Components search karein: PIR Motion Sensor, Buzzer, LED, Resistor, aur Arduino Uno add karein
3. Wiring summary ke mutabiq connections banayein
4. `Motion_Alarm.ino` ka code Arduino mein paste karein
5. "Start Simulation" dabayein aur PIR sensor ke saamne mouse/cursor move kar ke motion trigger karein

## Wiring Summary

| Component Pin | Arduino Pin |
|---|---|
| PIR Sensor VCC | 5V |
| PIR Sensor GND | GND |
| PIR Sensor OUT | Digital Pin 2 |
| Buzzer Positive (+) | Digital Pin 8 |
| Buzzer Negative (-) | GND |
| LED Anode (+) | Digital Pin 13 |
| LED Cathode (-) | Via 220Ω resistor → GND |

## Files in This Folder

- `Motion_Alarm.ino` — Arduino source code
- `Motion_Alarm_Project.pdf` — Full documentation with circuit diagram
- Circuit screenshot image
