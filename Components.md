# Components Required
## ESP32 Seed Sowing Robot

This document lists all hardware components required to build the WiFi-controlled Seed Sowing Robot.

---

# 1. Microcontroller

- 1 × ESP32 Development Board

Purpose  
Acts as the main controller of the robot. It creates the WiFi hotspot and hosts the browser control portal used to drive the robot and control seed sowing.

---

# 2. Motor Driver

- 1 × L298N Motor Driver Module

Purpose  
Controls the direction and speed of the DC motors that move the robot.

---

# 3. Drive Motors

- 2 × DC Gear Motors

Purpose  
Provide movement for the robot platform.

---

# 4. Robot Chassis

- 1 × Robot Car Chassis
- 2 × Wheels
- 1 × Caster Wheel

Purpose  
Provides the base structure and mobility for the robot.

---

# 5. Seed Dispensing Mechanism

- 1 × Servo Motor (SG90 or MG90S)

Purpose  
Controls the flap mechanism used to release seeds from the container.

---

# 6. Seed Container

- Small seed storage container
- Flap or sliding gate mechanism
- Servo mounting bracket

Purpose  
Stores seeds and releases them when the sowing mechanism is activated.

---

# 7. Power Supply

Option A

- 2 × 18650 Li-ion Batteries
- 1 × Battery Holder

Option B

- 7.4V Li-ion Battery Pack

Purpose  
Provides power to the motors, ESP32, and servo motor.

---

# 8. Voltage Regulation

- 1 × LM2596 Buck Converter

Purpose  
Steps down battery voltage to stable 5V for the ESP32 and electronics.

---

# 9. Indicators (Optional)

- 1 × Status LED
- 1 × Buzzer

Purpose  

LED → indicates system status  
Buzzer → optional feedback for commands

---

# 10. Structural Components

- Seed container holder
- Servo mounting bracket
- Robot frame or enclosure
- Screws and nuts
- Optional 3D printed parts

Purpose  
Supports the mechanical structure of the robot and seed mechanism.

---

# 11. Basic Electronics

- Breadboard or PCB
- Jumper wires
- Resistors (220Ω)
- Switch (power switch)

Purpose  
Used for circuit connections and system power control.

---

# Component Summary

| Category | Components |
|--------|------------|
| Controller | ESP32 |
| Motor Driver | L298N |
| Drive System | DC Gear Motors |
| Actuator | Servo Motor |
| Power | Li-ion Batteries |
| Voltage Regulation | Buck Converter |
| Structure | Chassis, wheels, seed container |

---

# Notes

Ensure that the motor driver and ESP32 share a common ground. Motors should be powered directly from the battery supply through the motor driver to prevent damage to the ESP32. 
