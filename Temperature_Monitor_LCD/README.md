# Temperature Monitor (with LCD Display)

Arduino Uno + Tinkercad Simulation Project

## Project Overview

Yeh project TMP36 temperature sensor ka istemal karke ambient temperature ko continuously measure karta hai, aur usse ek 16x2 LCD display par digitally show karta hai. Jab temperature ek fixed threshold (30°C) se upar chala jata hai, ek alert LED automatically ON ho jati hai aur LCD par status "HIGH!" show hota hai.

## Components Used

| # | Component | Quantity | Purpose |
|---|---|---|---|
| 1 | Arduino Uno R3 | 1 | Main microcontroller board |
| 2 | Breadboard (small) | 1 | To hold and connect components |
| 3 | Temperature Sensor (TMP36) | 1 | Senses ambient temperature |
| 4 | 16x2 LCD (HD44780) | 1 | Displays live temperature and status |
| 5 | Potentiometer - 10k ohm | 1 | Controls LCD contrast |
| 6 | LED | 1 | Alert indicator for high temperature |
| 7 | Resistor - 220 ohm | 1 | Current-limiting resistor for the LED |
| 8 | Jumper wires | as needed | Connections between components |

## Wiring Summary

| From | To | Wire Color (suggested) |
|---|---|---|
| TMP36 Power | Arduino 5V | Red |
| TMP36 GND | Arduino GND | Black |
| TMP36 Vout | Arduino A0 | Green |
| LED anode (long leg) | Arduino Pin 7 | Blue |
| LED cathode (short leg) | 220 ohm resistor - leg 1 | Direct breadboard row |
| 220 ohm resistor - leg 2 | GND rail | Black |
| LCD GND | Arduino GND | Black |
| LCD VCC | Arduino 5V | Red |
| LCD RS | Arduino Pin 12 | Gray |
| LCD RW | Arduino GND | Black |
| LCD E (Enable) | Arduino Pin 11 | Orange |
| LCD DB0 / DB1 / DB2 / DB3 | Not connected (4-bit mode) | - |
| LCD DB4 / DB5 / DB6 / DB7 | Arduino Pins 5 / 4 / 3 / 2 | Blue / Purple / Orange / Teal |
| LCD LED (+) | Arduino 5V | Red |
| LCD LED (-) | Arduino GND | Black |
| Potentiometer wiper | LCD V0 | Green |
| Breadboard GND rail | Arduino GND | Black |

## Kaise Kaam Karta Hai

TMP36 sensor ambient temperature ko analog voltage mein convert karta hai. Arduino ka A0 pin ye voltage read karta hai, aur code usse Celsius mein convert karta hai formula `(voltage - 0.5) x 100` se, kyunki TMP36 0.5V par 0°C represent karta hai aur har 10 mV rise 1°C ke barabar hota hai.

LiquidCrystal library Arduino ke digital pins ko LCD ke control aur data pins se link karti hai. Har loop cycle mein LCD ki pehli line current temperature ke saath update hoti hai, aur doosri line "NORMAL" ya "HIGH!" status dikhati hai depending on threshold (30°C). Jab temperature threshold se upar jata hai, Pin 7 HIGH ho jata hai aur alert LED ON ho jati hai.

**Note:** Agar LCD par text blank ya bohat dark nazar aaye to potentiometer ki contrast value adjust karo. Agar LED behavior ulta lage, to code mein threshold comparison (`temperatureC > thresholdTemp`) ko check karo.
