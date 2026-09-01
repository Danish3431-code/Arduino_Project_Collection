# Traffic Signal Project

Arduino Uno + Tinkercad — Red / Yellow / Green LED Sequencer jo real traffic light ki tarah kaam karta hai.

## Project Overview

Ye simple Arduino based project hai jisme teen LEDs (Red, Yellow, Green) ek traffic signal ki tarah cycle mein on/off hote hain. Circuit Tinkercad par design aur simulate kiya gaya hai.

## Components Used

| Component | Quantity |
|---|---|
| Arduino Uno R3 | 1 |
| LED - Red | 1 |
| LED - Yellow | 1 |
| LED - Green | 1 |
| Resistor - 220 ohm | 3 |
| Breadboard | 1 |
| Jumper wires | as needed |

## Circuit Wiring

- Red LED anode → Arduino pin 11 (orange wire)
- Yellow LED anode → Arduino pin 12 (yellow wire)
- Green LED anode → Arduino pin 13 (green wire)
- Har LED ka cathode apne 220 ohm resistor se hote huay breadboard ki GND rail se juda hai
- Breadboard GND rail → Arduino GND pin (black wire)

Poora circuit diagram aur detailed build steps `Traffic_Signal_Project.pdf` file mein maujood hain.

## How It Works

Code teeno LEDs ko is sequence mein cycle karta hai:

- Red ON — 5 seconds
- Yellow ON — 4 seconds
- Green ON — 3 seconds
- Phir dobara Red se repeat

## Code

Poora Arduino code `Traffic_Signal.ino` file mein hai. Ye Tinkercad ke "Text" code mode mein paste kar ke run kiya ja sakta hai.

## How to Run

1. Tinkercad.com par jayein aur naya circuit banayein
2. Arduino Uno R3, breadboard, 3 LEDs, aur 3 resistors add karein
3. Diagram ke mutabiq wiring karein
4. `Traffic_Signal.ino` ka code Arduino mein paste karein
5. "Start Simulation" dabayein aur LEDs ka sequence dekhein

## Files in This Folder

- `Traffic_Signal.ino` — Arduino source code
- `Traffic_Signal_Project.pdf` — Full documentation with circuit diagram
- Circuit screenshot image
