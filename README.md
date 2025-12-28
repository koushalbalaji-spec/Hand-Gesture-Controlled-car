# Hand Gesture Controlled Arduino Car

A wireless robotic car that moves according to hand gestures using an **MPU6050 accelerometer & gyroscope** and 
**NRF24L01** wireless communication modules and a **"motor driver".**


## Overview

This project allows a user to control a robotic car using simple hand movements(tilting).  
An MPU6050 sensor mounted on a glove detects the tilt of the hand. These motion values are 
transmitted wirelessly using NRF24L01 
modules to another Arduino mounted on the car, which then controls the motors accordingly.

This eliminates the need for remote or complicated controls.

---

##  Features

- Hand gesture–based control  
- Wireless communication using NRF24L01  
- Forward, backward, left, and right movement  
- 360 degrees turn radius

---

##  Working Principle

1. The **MPU6050** detects hand tilt (X and Y axis).
2. The **transmitter Arduino** processes this data.
3. Data is sent wirelessly via **NRF24L01**.
4. The **receiver Arduino** receives the data.
5. The **motor driver (L298N)** controls the motors based on received gestures.

---

##  Hardware Requirements

### Transmitter (Glove Unit)
- Arduino nano 
- MPU6050 accelerometer & gyroscope  
- NRF24L01 module  
- Jumper wires  
- Power source (Recharable power bank)

### Receiver (Car Unit)
- Arduino Uno  
- NRF24L01 PA/LNA module  
- motor driver  
- DC motors with wheels  
- Chassis  
- Battery pack  (2 sets of batteries)

---

##  Software Requirements

- Arduino IDE  
- Libraries:
  - `Wire.h`
  - `I2Cdev`
  - `MPU6050`
  - `RF24`

## Thank You
