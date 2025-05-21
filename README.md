# Smart-motion-based-Security-alert-system

This Arduino project uses an **ultrasonic sensor**, **buzzer**, and **LED** to measure the distance to an object and provide both visual and auditory alerts when the object is within a defined range.

## 🚀 Features

- Measures distance using an HC-SR04 ultrasonic sensor
- Activates a buzzer and LED when an object is detected within 100 cm
- Beep frequency increases as the object gets closer
- Displays distance readings in the Serial Monitor

## 🧰 Components Required

- Arduino Uno (or compatible)
- HC-SR04 Ultrasonic Sensor
- Buzzer
- LED
- 220Ω resistor (for LED)
- Breadboard and jumper wires

## 🔌 Pin Configuration

| Component      | Arduino Pin |
|----------------|-------------|
| HC-SR04 Trig   | D10         |
| HC-SR04 Echo   | D11         |
| Buzzer         | D9          |
| LED            | D8          |

## ⚙️ How It Works

1. The ultrasonic sensor emits a pulse and listens for its echo.
2. The time taken for the echo is converted into distance (in cm).
3. If an object is **≤ 100 cm** away:
   - The buzzer and LED are triggered.
   - Beep frequency increases as the distance decreases.
4. If an object is **> 100 cm** away:
   - The buzzer is turned off.
   - The LED remains off.

## 🧾 Code Overview

### `calculateDistance()`

- Sends a trigger pulse via the ultrasonic sensor
- Measures return echo duration
- Converts time to distance in cm

### `buzzAccordingToDistance(int d)`

- Maps distance to buzzer delay interval
- Triggers buzzer and LED with frequency based on proximity

## 🖥️ Serial Monitor Output Example
Distance: 92cm
Distance: 65cm
Distance: 30cm

## ✅ How to Use

1. Connect the components as described above.
2. Upload the code to your Arduino board using the Arduino IDE.
3. Open the Serial Monitor (baud rate: `9600`) to view real-time distance data.

## 📝 Notes

- The code assumes an **active-low buzzer** (turned ON when pin is set to `LOW`).
- Adjust the mapped delay values in `buzzAccordingToDistance()` if needed for different beep patterns.

