# Automatic Fan System

Arduino Uno + Tinkercad Simulation Project

## Project Overview

Yeh project TMP36 temperature sensor ka istemal karke ambient temperature ko continuously measure karta hai. Jab temperature ek fixed threshold (28°C) se upar chala jata hai, ek DC motor (fan) automatically ON ho jata hai taake cooling ho sake. Temperature thandi hone par fan wapas OFF ho jata hai. Motor ko directly Arduino pin se nahi chalaya jata - ek NPN transistor (2N2222) ise switch ki tarah control karta hai, aur ek flyback diode motor ke reverse voltage spikes se transistor ko protect karta hai.

## Components Used

| # | Component | Quantity | Purpose |
|---|---|---|---|
| 1 | Arduino Uno R3 | 1 | Main microcontroller board |
| 2 | Breadboard | 1 | To hold and connect components |
| 3 | Temperature Sensor (TMP36) | 1 | Senses ambient temperature |
| 4 | DC Motor (fan) | 1 | Cooling fan actuator |
| 5 | NPN Transistor (2N2222) | 1 | Switches motor ON/OFF (Arduino pin can't supply motor current directly) |
| 6 | Diode (1N4007) | 1 | Flyback protection against motor's reverse voltage spike |
| 7 | Resistor - 1k ohm | 1 | Base resistor - limits transistor base current |
| 8 | Jumper wires | as needed | Connections between components |

**Note:** Motor ko Arduino pin se direct nahi chalaya ja sakta kyunki motor zyada current kheenchta hai jo Arduino pin (max ~40mA) handle nahi kar sakta. Transistor ek switch ki tarah kaam karta hai - Arduino sirf base ko control karta hai, transistor motor ka bada current path switch karta hai.

## Wiring Information

| From | To | Wire Color (suggested) |
|---|---|---|
| TMP36 Power | Arduino 5V | Red |
| TMP36 GND | Arduino GND | Black |
| TMP36 Vout | Arduino A0 | Green |
| Arduino Pin 9 | 1k resistor - leg 1 | Orange |
| 1k resistor - leg 2 | Transistor Base (B) | Direct breadboard row |
| Transistor Emitter (E) | Arduino GND | Black |
| Transistor Collector (C) | Motor negative terminal | Direct breadboard row |
| Motor positive terminal | Arduino 5V | Red |
| Diode cathode (banded end) | Motor positive terminal / 5V | Direct breadboard row |
| Diode anode | Motor negative terminal / Collector | Direct breadboard row |

**Diode direction is important:** diode ka banded (cathode) end 5V/motor-positive ki taraf hona chahiye, aur anode collector/motor-negative ki taraf - reverse lagane se protection kaam nahi karegi.

## Kaise Kaam Karta Hai

TMP36 ambient temperature ko analog voltage mein convert karta hai, jo Arduino A0 par read hota hai aur formula `(voltage - 0.5) x 100` se Celsius mein convert hota hai.

Jab temperature threshold (28°C) se upar jata hai, Arduino Pin 9 ko HIGH karta hai. Ye signal 1k resistor ke through transistor ke Base tak pohanchta hai, jisse transistor ON ho jata hai aur Collector-Emitter ke through motor ka circuit complete ho jata hai - fan chalne lagta hai. Jab temperature threshold se neeche aata hai, Pin 9 LOW ho jata hai, transistor OFF ho jata hai, aur fan ruk jata hai.

Diode motor ke coil mein stored energy ko safely discharge karta hai jab motor achanak OFF hota hai - iske bagair ye reverse voltage spike transistor ko damage kar sakta hai.

**Note:** Agar fan simulation mein turant ON/OFF flicker kare, threshold value ko thoda adjust karo. Agar fan bilkul na chale, transistor ke B/C/E pin orientation aur diode ki direction dobara check karo.
