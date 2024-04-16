# Speed Control with IR Remote

This C++ code implements a speed control system using an IR remote with an Arduino board and a liquid crystal display (LCD). The system allows users to adjust the speed of DC motor connected to the Arduino's PWM pin based on the received IR remote signals.

## Components Used
- Arduino board
- IR receiver module
- IR remote
- Liquid crystal display (LCD)
- Bulb connected to PWM pin

## Libraries Required
- `LiquidCrystal.h`: A library for controlling LCDs.
- `IRremote.h`: A library for receiving and decoding IR signals.

## Pin Configuration
- `receiver`: Pin 10 (connected to IR receiver module)
- `buld`: Pin 9 (connected to the bulb)
- LCD Pins: (12, 11, 5, 4, 3, 2)

## Functionality
1. The system initializes the LCD, sets up IR remote reception, and displays a startup message.
2. The loop continuously checks for IR signals. Upon receiving signals:
   - If the received signal corresponds to `code1`, the counter increments, adjusting the brightness level up.
   - If the received signal corresponds to `code2`, the counter decrements, adjusting the brightness level down.
3. The counter value is bounded within the range [1, 5].
4. Based on the counter value, the PWM value for the bulb is adjusted accordingly, and the corresponding status message is displayed on the LCD.

## Counter States
- 1: Dimmer Off
- 2: Dimmer On, Speed 1
- 3: Dimmer On, Speed 2
- 4: Dimmer On, Speed 3
- 5: Dimmer Max

## Notes
- The PWM value is adjusted to control the brightness level of the bulb.
- IR remote signals `code1` and `code2` are used for increasing and decreasing the brightness levels, respectively.


