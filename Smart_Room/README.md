# Smart Room Automation

Arduino Uno + PIR Motion Sensor + LDR + TMP36 | Auto Room Light + Temperature Alert System

## Project Overview

Ye ek multi-sensor Smart Room Automation project hai jo teen sensors ko combine karta hai: PIR motion sensor, LDR (light sensor), aur TMP36 (temperature sensor). System do independent logics par kaam karta hai — pehla, motion detect hone par aur andhera hone par room light (LED) automatically ON hoti hai jiski brightness ambient light ke hisaab se adjust hoti hai (PWM). Doosra, agar temperature ek fixed threshold se zyada ho jaye, to buzzer alert bajata hai. Circuit Tinkercad par design aur simulate kiya gaya hai.

## Components Used

| # | Component | Quantity | Purpose |
|---|---|---|---|
| 1 | Arduino Uno R3 | 1 | Main microcontroller board |
| 2 | Breadboard | 1 | Components ko hold aur connect karne ke liye |
| 3 | PIR Motion Sensor | 1 | Movement / human presence detect karta hai |
| 4 | Photoresistor (LDR) | 1 | Ambient light level sense karta hai |
| 5 | TMP36 Temperature Sensor | 1 | Ambient temperature ko analog voltage mein convert karta hai |
| 6 | LED | 1 | Room light ko represent karti hai (PWM controlled brightness) |
| 7 | Buzzer | 1 | Temperature alert ke liye warning sound |
| 8 | Resistor - 220 ohm | 1 | LED ke liye current-limiting resistor |
| 9 | Resistor - 10k ohm | 1 | LDR ke saath voltage divider banata hai |
| 10 | Jumper wires | as needed | Connections ke liye |

## Circuit Wiring

**Power Rails**
- Arduino 5V → Breadboard + rail (red)
- Arduino GND → Breadboard - rail (black)

**LDR (Light Sensor) — Voltage Divider**
- LDR leg 1 → Breadboard + rail (5V) — red wire
- LDR leg 2 → 10k ohm resistor (same row)
- LDR/resistor junction → Arduino A0 — blue wire
- 10k ohm resistor other leg → GND rail — black wire

**TMP36 (Temperature Sensor)**
- Power pin (left leg) → Breadboard + rail (5V) — red wire
- Vout pin (middle leg) → Arduino A1 — blue wire
- Ground pin (right leg) → Breadboard - rail (GND) — black wire

**LED (Room Light)**
- Anode (long leg) → Arduino D9 (PWM) — orange wire
- Cathode (short leg) → 220 ohm resistor → GND rail — black wire

**PIR Sensor**
- VCC → Breadboard + rail (5V)
- GND → Breadboard - rail (GND)
- OUT → Arduino D2

**Buzzer**
- Positive (+) → Arduino D8 — green wire
- Negative (-) → Breadboard - rail (GND) — black wire

Poora circuit diagram aur detailed build steps `Smart_Room_Automation_Step_By_Step_Guide.pdf` file mein maujood hain.

## How It Works

**Room Light Logic:**
1. LDR value continuously A0 se `analogRead` hoti hai; agar value `darkThreshold (500)` se kam ho, to environment "dark" samjha jata hai.
2. Agar motion detect ho (PIR = HIGH) **aur** dark ho, to LED `analogWrite` (PWM) ke zariye ON hoti hai — brightness `map()` function se LDR value ke mutabiq automatically adjust hoti hai (kam roshni = zyada brightness).
3. Agar motion na ho ya roshni kaafi ho, LED OFF rehti hai.

**Temperature Alert Logic:**
1. TMP36 se A1 par voltage read hoti hai aur standard TMP36 formula se Celsius temperature mein convert ki jati hai.
2. Agar temperature `tempAlertC (30°C)` se zyada ho jaye, buzzer HIGH ho kar alert bajata hai.
3. Jab temperature normal ho jaye, buzzer automatically OFF ho jata hai.

**Debug Output:** Har cycle (300ms delay) par motion status, LDR value, aur temperature Serial Monitor par print hote hain.

## Code

Poora Arduino code `Smart_Room.ino` file mein hai. Ye Tinkercad ke Text code mode mein paste kar ke run kiya ja sakta hai.

## How to Run

1. Tinkercad.com par jayein aur naya circuit banayein
2. Arduino Uno R3, Breadboard, PIR Sensor, LDR, TMP36, LED, aur Buzzer add karein
3. Wiring summary ke mutabiq power rails, LDR voltage divider, TMP36, LED, PIR, aur buzzer connect karein
4. `Smart_Room.ino` ka code Arduino mein paste karein
5. "Start Simulation" dabayein
6. PIR par click kar ke motion simulate karein, LDR par click kar ke light level adjust karein, aur TMP36 par click kar ke temperature 30°C se upar le ja kar buzzer test karein

## Wiring Summary

| From | To | Wire Color |
|---|---|---|
| Arduino 5V | Breadboard + rail | Red |
| Arduino GND | Breadboard - rail | Black |
| LDR leg 1 | Breadboard + rail (5V) | Red |
| LDR/Resistor junction | Arduino A0 | Blue |
| 10k resistor | GND rail | Black |
| TMP36 Power | Breadboard + rail (5V) | Red |
| TMP36 Vout | Arduino A1 | Blue |
| TMP36 Ground | Breadboard - rail (GND) | Black |
| LED Anode | Arduino D9 (PWM) | Orange |
| LED Cathode | 220 ohm resistor → GND rail | Black |
| PIR VCC | Breadboard + rail (5V) | — |
| PIR GND | Breadboard - rail (GND) | — |
| PIR OUT | Arduino D2 | — |
| Buzzer (+) | Arduino D8 | Green |
| Buzzer (-) | Breadboard - rail (GND) | Black |

## Files in This Folder

- `Smart_Room.ino` — Arduino source code
- `Smart_Room_Automation_Step_By_Step_Guide.pdf` — Full documentation with circuit diagram
- Circuit screenshot image
