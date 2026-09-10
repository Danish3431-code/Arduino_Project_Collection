# Distance Meter with LCD

Arduino Uno R3-based distance meter that uses an HC-SR04 ultrasonic sensor to measure distance and displays the live reading on a 16x2 LCD screen.

## Overview

This project measures distance using ultrasonic sound waves and displays the result in real time on a 16x2 character LCD, updating every 500 milliseconds. The LCD wiring in this repository has been verified against the physical module's actual pinout (GND, VCC, V0, RS, RW, E, DB0–DB7, LED, LED).

## Components Used

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno R3 | 1 | Main microcontroller board |
| HC-SR04 Ultrasonic Sensor | 1 | Measures distance using sound waves |
| 16x2 LCD Display | 1 | Shows live distance reading |
| Potentiometer (10kΩ) | 1 | Adjusts LCD contrast |
| Resistor (220Ω) | 1 | Current-limiting resistor for LCD backlight (LED+) |
| Breadboard | 1 | For connections |
| Jumper Wires | As needed | For wiring all components |

## Wiring

### HC-SR04 Ultrasonic Sensor

| Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| Trig | Pin 9 |
| Echo | Pin 10 |

### 16x2 LCD Display

| LCD Pin | Full Name | Arduino Pin / Connection |
|---|---|---|
| GND | Ground | GND |
| VCC | Logic Supply | 5V |
| V0 | Contrast Voltage | Potentiometer wiper |
| RS | Register Select | Pin 12 |
| RW | Read / Write | GND |
| E | Enable | Pin 11 |
| DB0–DB3 | Data Bus (unused) | Not connected |
| DB4 | Data Bus Line 4 | Pin 5 |
| DB5 | Data Bus Line 5 | Pin 4 |
| DB6 | Data Bus Line 6 | Pin 3 |
| DB7 | Data Bus Line 7 | Pin 2 |
| LED+ | Backlight Anode | 5V (via 220Ω resistor) |
| LED− | Backlight Cathode | GND |

> **Note:** The LiquidCrystal library runs the LCD in 4-bit mode, so only DB4–DB7 are used — DB0–DB3 are left unconnected. A 220Ω resistor is placed in series with the LED+ pin to protect the backlight from excess current.

### Potentiometer (Contrast Control)

| Pin | Connection |
|---|---|
| End 1 | 5V |
| End 2 | GND |
| Middle (Wiper) | LCD V0 |

The two end pins supply 5V and GND across the resistive track. The wiper pin taps an adjustable voltage between 0V and 5V from that track and feeds it to the LCD's V0 pin, allowing manual contrast adjustment.

## Circuit Diagram

See `Distance_Meter_LCD_Corrected.pdf` in this repository for the full wiring diagram and breadboard layout.

## How It Works

1. The HC-SR04 sends a 10-microsecond trigger pulse and measures the duration of the returning echo pulse.
2. The duration is converted to distance in centimeters using the formula `distance = duration * 0.034 / 2`.
3. The result is printed to the 16x2 LCD via the `LiquidCrystal` library.
4. `lcd.begin(16, 2)` initializes the display, `lcd.setCursor(col, row)` positions the cursor, and `lcd.print()` writes the value.
5. The RW pin is tied to GND since the LCD is only ever written to, never read from.
6. The loop repeats every 500 milliseconds, giving a near real-time distance readout.

## Getting Started

1. Wire the components according to the tables above.
2. Upload `Distance_Meter_LCD.ino` to your Arduino Uno using the Arduino IDE.
3. Power the board — the LCD should display the live distance reading
