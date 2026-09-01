# Automatic Street Light (ON/OFF)

Arduino Uno + LDR (Light Sensor) + LED — Tinkercad Simulation Project

## Project Overview

Ye project ek LDR (photoresistor / light sensor) ka istemal karke ambient darkness detect karta hai, aur andhera hone par ek LED (jo street light ko represent karti hai) ko automatically ON kar deta hai. Roshni hone par LED wapas OFF ho jati hai. LED sirf full ON ya full OFF hoti hai (koi dimming nahi) — decision Arduino code mein ek simple if/else condition se hota hai. Circuit Tinkercad par design aur simulate kiya gaya hai.

## Components Used

| # | Component | Quantity | Purpose |
|---|---|---|---|
| 1 | Arduino Uno R3 | 1 | Main microcontroller board |
| 2 | Breadboard (small) | 1 | Components ko hold aur connect karne ke liye |
| 3 | Photoresistor (LDR) | 1 | Ambient light level sense karta hai |
| 4 | Resistor - 10k ohm | 1 | LDR ke saath voltage divider banata hai (A0 reading ke liye) |
| 5 | LED | 1 | Street light ko represent karti hai |
| 6 | Resistor - 220 ohm | 1 | LED ke liye current-limiting resistor |
| 7 | Jumper wires | as needed | Connections ke liye |

## Circuit Wiring

- Arduino 5V → LDR leg 1 (red wire)
- LDR leg 2 → 10k ohm resistor leg 1 (breadboard row)
- LDR/Resistor junction → Arduino A0 (green wire)
- 10k ohm resistor leg 2 → GND rail (black wire)
- Arduino Pin 5 → LED anode (long leg) (orange wire)
- LED cathode (short leg) → 220 ohm resistor → GND rail (black wire)
- Breadboard GND rail → Arduino GND (black wire)

Poora circuit diagram aur detailed build steps `Automatic_Street_light_Project.pdf` file mein maujood hain.

## How It Works

LDR aur 10k ohm resistor mil kar ek voltage divider banate hain, jiski beech wali value Arduino ke A0 pin par `analogRead` se padhi jati hai. Jab roshni kam hoti hai (andhera), LDR ki resistance badh jati hai aur A0 par value kam ho jati hai. Code is value ko threshold (500) se compare karta hai:

- Agar value threshold se **kam** ho → Pin 5 HIGH → LED ON (andhera hai, street light chalu)
- Agar value threshold se **zyada** ho → Pin 5 LOW → LED OFF (roshni hai, street light band)

Ye check har 10 milliseconds mein dobara hota hai, isliye light apne aap adjust hoti rehti hai.

> **Note:** Agar simulation mein LED ka behavior ulta lage (roshni mein ON, andhera mein OFF), to code ki `if (LightSensor < threshold)` line mein `<` ko `>` se replace kar dein.

## Code

Poora Arduino code `Automatic_Street_light.ino` file mein hai. Ye Tinkercad ke Text code mode mein paste kar ke run kiya ja sakta hai.

## How to Run

1. Tinkercad.com par jayein aur naya circuit banayein
2. Components add karein: Arduino Uno R3, Breadboard (small), Photoresistor (LDR), 2x Resistors (10k ohm aur 220 ohm), aur LED
3. Wiring summary ke mutabiq connections banayein — LDR voltage divider (A0) aur LED (Pin 5)
4. `Automatic_Street_light.ino` ka code Arduino mein paste karein
5. "Start Simulation" dabayein, LDR par click kar ke light-level slider ghumayein, aur LED ka response dekhein
6. Serial Monitor kholein aur LDR values check karein — agar din/raat ki values threshold (500) se match na ho, to code mein threshold value adjust kar lein

## Wiring Summary

| From | To | Wire Color |
|---|---|---|
| Arduino 5V | LDR leg 1 | Red |
| LDR leg 2 | 10k resistor leg 1 | Direct breadboard row |
| LDR / Resistor junction | Arduino A0 | Green |
| 10k resistor leg 2 | GND rail | Black |
| Arduino Pin 5 | LED anode (long leg) | Orange |
| LED cathode (short leg) | 220 ohm resistor leg 1 | Direct breadboard row |
| 220 ohm resistor leg 2 | GND rail | Black |
| Breadboard GND rail | Arduino GND | Black |

## Files in This Folder

- `Automatic_Street_light.ino` — Arduino source code
- `Automatic_Street_light_Project.pdf` — Full documentation with circuit diagram
- Circuit screenshot image
