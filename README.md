# VU MIF ROBOTICS HOMEWORK NR. 1

## MAIN GOLD
This project demonstrates a smart temperature monitoring system built with Arduino Uno.
It continuously measures ambient temperature using a TMP sensor and displays the results in Celsius and Fahrenheit on a 16x2 LCD screen.
The system includes LED warning that activate when the temperature exceeds a defined limit, and it calculates a 10-second average temperature for more stable readings.

## FEATURES 
- Real-time temperature measurement in °C and °F.
- LCD display shows current, average, and elapsed time.
- Audible and visual alert (LED) when temperature exceeds the threshold.
- 10-second average temperature calculation using millis() for precise timing.
- Custom degree symbol (°) displayed on LCD.
- Real-time logging to Serial Monitor for debugging and data tracking.

## COMPONENTS

| Component | Quantity | Function |
|------------|-----------|-----------|
| **Arduino Uno** | 1 | Main control unit |
| **TMP36 Temperature Sensor** | 1 | Reads ambient temperature |
| **16x2 LCD Display** | 1 | Displays readings and system status |
| **Potentiometer** | 1 | Adjusts LCD contrast |
| **LED + Resistor** | 1 | Visual over-temperature alert |
| **Breadboard** | 1 | Prototyping base |

## PHOTO
<img width="762" height="672" alt="Screenshot 2025-10-05 at 20 32 13" src="https://github.com/user-attachments/assets/ac97a7d8-017f-45dd-9464-7ed1e0c63745" />

## DEMO VIDEO

[Click here to watch the demo video](https://github.com/vasarepratuzaite/Robotics.-HW1/blob/main/demo.mp4)

## SYSTEM OVERVIEW
When the device starts, the Serial Monitor welcomes the user with the title “Reaction Time Tester” and automatically retrieves the best previous score stored in EEPROM memory. To begin the test, the user presses the button once. After that, the Arduino waits for a random time interval between one and five seconds before turning the LED ON. As soon as the LED lights up, the internal timer starts counting. The user must react quickly and press the button as fast as possible. The system then stops the timer and displays the user’s reaction time in milliseconds on the Serial Monitor. If this new score beats the previously saved record, it immediately replaces the old one in EEPROM.
The experiment can be repeated continuously, allowing the user to train and improve their reflex speed over time.

## ARDUINO CODE HIGHLIGHTS 
- Uses the LiquidCrystal library for LCD control.
- Implements timing logic using millis() instead of delay() for averaging.
- Custom degree symbol created with lcd.createChar().
- Organized, commented, and easy-to-modify code.

## CIRCUIT OVERVIEW 
- TMP36 sensor connected to analog pin A0.
- LCD display connected to digital pins 8, 7, 6, 5, 4, 3.
- LED connected to digital pin 10 (with resistor).
- Potentiometer used to control LCD contrast between 5V and GND.

## FUTURE IMPROVEMENTS
- Allow temperature limit adjustment using buttons or a potentiometer.
- Add LCD backlight control based on ambient light sensor.



   



