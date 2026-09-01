# LED Blink Circuit

Arduino Uno R3 + Tinkercad Simulation

## Project Overview

Ye ek beginner-level Arduino project hai jo ek single LED ko har second ON aur OFF blink karta hai. Ye poora blink digital pin 4 ke zariye control hota hai, aur logic sirf teen basic functions par based hai: `pinMode`, `digitalWrite`, aur `delay`. Circuit Tinkercad par design aur simulate kiya gaya hai.

## Components Used

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno R3 | 1 | Microcontroller board — blink code run karta hai |
| LED (any color) | 1 | Visual output — ON aur OFF hoti hai |
| Resistor (220Ω) | 1 | LED ko protect karne ke liye current limit karta hai |
| Jumper Wires | 2 | Pin 4 ko LED se, aur LED/resistor ko GND se connect karte hain |
| Breadboard | Optional | Direct wiring use karein to zaroori nahi |

## Circuit Wiring

- Arduino Pin 4 → LED Anode (long leg / +) — green wire
- LED Cathode (short leg / -) → 220Ω resistor — one leg
- 220Ω resistor — other leg → Arduino GND — black wire

Poora circuit diagram aur detailed build steps `LED_Blinking_Project.pdf` file mein maujood hain.

## How It Works

Ye circuit ek simple ON/OFF logic par kaam karta hai. Arduino ka Pin 4 `digitalWrite()` function se HIGH aur LOW hota rehta hai — jab pin HIGH hota hai to us se 5V current LED ki anode (positive leg) mein jata hai aur LED ON ho jati hai.

Resistor (220Ω) LED ke cathode side par lagaya gaya hai taake current ki value limit ho aur LED jal na jaye — bina resistor ke bohat zyada current flow hota hai jo LED ko damage kar sakta hai.

`delay(1000)` function 1000 milliseconds (1 second) tak wait karta hai — pehle LED ko HIGH par 1 second rehne dete hain, phir LOW kar ke 1 second OFF rakhte hain. Ye poora cycle `loop()` function ke andar hamesha repeat hota rehta hai, is liye LED continuously blink karti rehti hai.

> **Important:** LED ko seedha 5V pin se connect nahi karte, kyunke us se LED hamesha ON rahegi (constant), blink nahi karegi. Blink sirf tab hota hai jab hum ek digital pin (jaise Pin 4) use karte hain aur code se us pin ko HIGH/LOW switch karte hain.

## Code

Poora Arduino code `LED_Blinking.ino` file mein hai. Ye Tinkercad ke Text code mode mein paste kar ke run kiya ja sakta hai.

## How to Run

1. Tinkercad.com par jayein, sign in karein, aur naya circuit banayein
2. Arduino Uno R3 board ko workspace par drag karein
3. LED ko workspace par add karein, Arduino ke pass rakhein
4. Resistor add karein aur uski value 220Ω set karein
5. Pin 4 ko LED anode (long leg) se wire karein
6. LED cathode (short leg) ko resistor ki ek leg se connect karein
7. Resistor ki dusri leg ko Arduino GND se connect karein
8. `LED_Blinking.ino` ka code Arduino mein paste karein
9. "Start Simulation" dabayein — LED 1 second ON aur 1 second OFF hoti rahegi

## Wiring Summary

| From | To | Wire Color |
|---|---|---|
| Arduino Pin 4 | LED Anode (long leg / +) | Green |
| LED Cathode (short leg / -) | Resistor (220Ω) — one leg | Black |
| Resistor (220Ω) — other leg | Arduino GND | Black |

## Files in This Folder

- `LED_Blinking.ino` — Arduino source code
- `LED_Blinking_Project.pdf` — Full documentation with circuit diagram
- Circuit screenshot image
