# 7 Segment Serial Display Interface

## Overview

This project demonstrates how a 74HC595N shift register can be used to connect a microcontroller development board with limited I/O pins with a common-cathode 7-segment display. An ATtiny85-based Trinket 5V microcontroller board was used in this project. When the program is running, the 7-segment display cycles through all hexadecimal numerals: `0` through `F`.

Schematic, photos, and demo video are all in the repository.
## Software

Arduino IDE 2.3.6 was used to complete this project, with Trinket board support installed per [the official Adafruit Trinket setup guide](https://learn.adafruit.com/introducing-trinket/windows-setup). Other than the built-in Arduino functions, no additional libraries are used.

Each character for the 7-segment display is stored as an array of 8 integers. Only the first 7 elements are used; the 8th element is not used but would correspond to the decimal point on the display. 

All of the configuration for pin selection and the half-period of the data clock signal are hard-coded with macros instead of variables to keep the program size down.

By utilizing only built-in Arduino functions, the code remains very portable. Further optimizations such as direct register manipulation would further reduce the program size, but would also limit the support to only systems built around ATtiny25/45/85 microcontrollers.

## Hardware Used
- Adafruit Trinket 5V (contains ATtiny85 microcontroller)
- 74HC595N Shift Register
- 5161AS common-cathode 7-segment display
- 2x 330 Ω ±5% resistors
- Half-sized breadboard
- Various jumper cables cut to length


## License
- GPL-3.0 license applies to the software
- CERN OHL v2 Strongly Reciprocal for the hardware design
