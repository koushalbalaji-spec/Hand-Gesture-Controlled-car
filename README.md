## Hand Gesture Controlled Arduino Car 

This is a wireless robotic car controlled entirely by hand gestures — no joystick, 
no buttons. Tilting your hand forward makes the car go forward, tilting it back 
reverses it, and leaning left or right steers it. The motion is picked up by an 
MPU6050 sensor on a glove, sent wirelessly via NRF24L01 radio modules, and 
interpreted by an Atmega328P chip on a custom PCB that drives four DC motors.

---
## How to use it

Wear the transmitter glove and power it on using the power bank. Power on the car. 
Tilt your hand in the direction you want the car to move — forward, backward, left, 
or right. The car responds in real time to your hand angle. No pairing step is 
needed; the NRF24L01 modules communicate automatically on the same channel.

## Why I built this
I wanted to explore wireless communication and motion sensing without relying on 
a phone app or a traditional remote. Building a gesture-controlled interface felt 
like a more intuitive and hands-on challenge. I also wanted experience designing 
my own PCB to replace the breadboard prototype, reduce noise on the NRF module, 
and shrink the overall build by swapping the Arduino Uno for a bare Atmega328P chip.

---
## Overview

This project allows a user to control a robotic car using simple hand movements(tilting).  
An MPU6050 sensor mounted on a glove detects the tilt of the hand. These motion values are 
transmitted wirelessly using NRF24L01 
modules to another Arduino mounted on the car, which then controls the motors accordingly.

This eliminates the need for remote or complicated controls.

---

## Update:
**- To reduce the use of battery, i have removed the arduino uno and replaced it with Atmega 328P chip.**
- PCB Built to house all the components and establish strong Connection.
- Steps taken To reduce noise disturbance to **NRF24L01**.
- Stronger Communication lines.
- 2 more motors added to increase **Drive power** and **Accuracy**.
- Reduced the Number of Battery Packs Needed

---
## TOP VIEW (With PCB)
<img width="1032" height="726" alt="image" src="https://github.com/user-attachments/assets/e47d4ea1-8085-430c-9c91-8858138b73a8" />

---

## BOTTOM VIEW
<img width="1070" height="732" alt="image" src="https://github.com/user-attachments/assets/d34e91e0-0bef-43ed-bfb8-f6d22320cbc2" />

---
## Car without PCB

![1000031322](https://github.com/user-attachments/assets/62e01929-ae63-4fce-bfde-7fad04b0160e)
---
![1000031337 - Copy](https://github.com/user-attachments/assets/02a6a445-61f1-483c-bd40-d33ae536b9f9)

---
**_NOTE: _****The Transmitter is just the PCB on a Glove connected to PowerSource as shown above.**

##  Features

- Hand gesture–based control  
- Wireless communication using NRF24L01  
- Forward, backward, left, and right movement  
- 360 degrees turn radius

---

##  Working Principle

1. The **MPU6050** detects hand tilt (X and Y axis).
2. The **transmitter Arduino nano** processes this data.
3. Data is sent wirelessly via **NRF24L01**.
4. The **receiver NRF24L01** receives the data.
5. The **Atmega 328p** on board chip processes and coordinates the motors.
6. The **motor driver (L298N)** controls the motors based on received gestures.

---

##  Hardware Requirements

### Transmitter (Glove Unit)
- Arduino nano 
- MPU6050 accelerometer & gyroscope  
- NRF24L01 module  
- PCB
- Power source (Recharable power bank)

## PCB

![pcbTransimitter2d](https://github.com/user-attachments/assets/225a32a9-cbb8-4f2d-ad8f-787ad41c586c)
---
![TransmitterCircuit](https://github.com/user-attachments/assets/80c9dca5-1593-464d-86fb-dc841edae475)

---
### Receiver (Car Unit)
- **ATMEGA 328P**
- **AMS1117-3.3v**(provides stable 3.3v for Nrf)
- 16mhz Crystal Oscillator
- 10k Ohm resistor
- 2 10uf Capacitor
- 2 22pf Capacitors
- **NRF24L01 PA/LNA module**  
- **motor driver**  
- **4 DC motors** with wheels  
- Chassis  
- Battery pack  (2 sets of batteries)
- **PCB** to house all the components

## PCB

![Screenshot 2026-03-03 171144](https://github.com/user-attachments/assets/099cbaec-8ab9-4400-a191-c3e82f6403a6)
---
![RecieverCircuit](https://github.com/user-attachments/assets/28670a9c-ad79-47e0-a870-61e3607a092b)

---

##  Software Requirements

- Arduino IDE  
- Libraries:
  - `Wire.h`
  - `I2Cdev`
  - `MPU6050`
  - `RF24`

## BOM

Component - Approx. Price (INR) 

 Arduino Nano - ₹250 
 Atmega328P - ₹180 
 MPU6050 - ₹160 
 NRF24L01 PA/LNA (×2) - ₹280 each 
 L298N Motor Driver - ₹120 
 DC Motors with Wheels (×4) - ₹100 each 
 AMS1117-3.3V - ₹15 
 16MHz Crystal Oscillator - ₹15 
 10kΩ Resistor - ₹2 
 10µF Capacitor (×2) - ₹5 each 
 22pF Capacitor (×2) - ₹3 each 
 Custom PCB (Receiver) - ₹200 
 Custom PCB (Transmitter) - ₹150 
 Car Chassis - ₹400 
 Rechargeable Power Bank - ₹600 
 AA Battery Pack (×2) - ₹120 each 
 PCB Transmitter and Receiver- ₹1800 (Excluding Conversion fee from $s)
##  PCB images and circuit diagram uploaded.


## Thank You
