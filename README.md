💧 Smart Water Level Controller using Arduino

Project 05 | Rajan Robotics
Vision to Reality

📌 Project Overview

The Smart Water Level Controller is an Arduino-based automation project designed to monitor and control the water level in a storage tank.

An HC-SR04 ultrasonic sensor measures the distance between the sensor and the water surface. Arduino processes the measured distance and automatically controls a water pump through a relay module.

A 16×2 LCD with I²C interface displays the water level status and pump operation.

This project demonstrates the practical application of sensors, embedded systems and automation in water management.

✨ Features

- Real-time water level monitoring.
- Contactless water level measurement using an ultrasonic sensor.
- Automatic water pump ON/OFF control.
- 16×2 LCD status display.
- Adjustable minimum and maximum water level thresholds.
- Automatic pump control using a relay module.
- Low-cost and beginner-friendly Arduino project.

🔧 Components Required

S.No.| Component| Quantity
1| Arduino Uno| 1
2| HC-SR04 Ultrasonic Sensor| 1
3| 16×2 LCD with I²C module| 1
4| 5V Relay Module| 1
5| Mini DC Water Pump| 1
6| Water Tank / Container| 1
7| External DC Pump Power Supply| 1
8| Jumper Wires| As required
9| Breadboard| 1 (optional)

🔌 Pin Connections

HC-SR04 Ultrasonic Sensor

Sensor Pin| Arduino Uno
VCC| 5V
GND| GND
TRIG| D9
ECHO| D10

16×2 LCD with I²C

LCD Pin| Arduino Uno
VCC| 5V
GND| GND
SDA| A4
SCL| A5

Relay Module

Relay Pin| Arduino Uno
VCC| 5V
GND| GND
IN| D7

DC Water Pump

Connect the DC pump's external power supply through the relay contacts:

- Supply positive → Relay COM
- Relay NO → Pump positive
- Pump negative → Supply negative

The relay switches the pump's separate power circuit. Select a relay and power supply rated for the pump.

⚙️ Working Principle

1. The ultrasonic sensor is mounted at the top of the water tank.
2. It measures the distance from the sensor to the water surface.
3. Arduino calculates the water level condition.
4. When the water level falls below the configured lower threshold, the pump switches ON.
5. When the water reaches the configured upper threshold, the pump switches OFF.
6. The LCD displays the water level condition and pump status.

📊 Water Level Control Logic

Water Level Condition| Pump Status
Below minimum level| ON
Filling in progress| ON
Upper level reached| OFF
Between thresholds| Retains previous state

The two thresholds provide hysteresis and help prevent rapid relay switching.

🖥️ Software Requirements

- Arduino IDE
- LiquidCrystal_I2C library
- Wire library (included with Arduino IDE)

📁 Project Structure

Arduino-Smart-Water-Level-Controller/
│
├── Code/
│   └── Smart_Water_Level_Controller.ino
│
├── Circuit/
│   └── Smart_Water_Level_Controller_Circuit.png
│
├── Images/
│   └── Working_Prototype.jpg
│
├── Videos/
│   └── demo_video_link.txt
│
├── README.md
└── LICENSE

🚀 Applications

- Household overhead water tanks.
- Educational water management models.
- Automatic water filling systems.
- Robotics and embedded systems demonstrations.
- STEM and engineering workshops.

🔮 Future Improvements

- IoT-based water level monitoring.
- Mobile application monitoring.
- Water usage tracking.
- Tank overflow alerts.
- Multiple tank monitoring.

⚠️ Safety Precautions

- Use a low-voltage DC water pump for this educational prototype.
- Use a separate regulated supply suitable for the pump.
- Keep Arduino and electrical connections protected from water.
- Ensure the relay contact rating matches the pump's voltage and current.
- Never operate the pump dry; provide adequate water-level protection.

👨‍🏫 Developed By

Rajan Robotics
Vision to Reality

Robotics | Embedded Systems | IoT | Electronics Education

📜 License

This project is licensed under the MIT License. See the "LICENSE" file for details.