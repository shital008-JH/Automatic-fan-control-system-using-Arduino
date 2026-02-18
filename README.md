# 🌡️ Automatic Fan Control System using Arduino

An **Automatic Fan Control System** built using **Arduino Uno**, **DHT11 Temperature Sensor**, and **L293D Motor Driver Module**.  
This project automatically turns the fan ON/OFF and adjusts its speed based on real-time temperature readings.

---

## 🚀 Project Overview

In modern embedded and automation systems, temperature-based control is widely used for improving comfort, safety, and energy efficiency.  
This project monitors ambient temperature using a **DHT11 sensor** and automatically controls a **DC fan** through the **L293D motor driver**.

The fan:

- Turns ON when temperature exceeds a threshold  
- Turns OFF when temperature falls below the threshold  
- Increases speed automatically using PWM control

  ![Pic5](https://github.com/user-attachments/assets/8abf9b4e-ea8d-4dc8-95ea-14ec6f239126)



---

## 🔧 Components Used

- **Arduino Uno**
- **DHT11 Temperature & Humidity Sensor**
- **L293D Motor Driver Module**
- **DC Fan / DC Motor**
- Breadboard & Jumper Wires
- External Power Supply (optional)

---

## ⚙️ Working Principle

1. The DHT11 sensor continuously measures room temperature.
2. Arduino reads the digital temperature data.
3. If temperature rises above the set threshold (e.g., 30°C):
   - Fan turns ON
   - Fan speed increases with temperature using PWM
4. If temperature drops below threshold:
   - Fan turns OFF automatically

---

## 🔌 Circuit Connections

| Component | Arduino Pin |
|----------|------------|
| DHT11 DATA | D2 |
| L293D IN1  | D9 |
| L293D IN2  | D8 |
| L293D ENA (PWM) | D10 |
| VCC | 5V |
| GND | GND |

Fan is connected to **OUT1/OUT2** of L293D.

---

## 📌 Features

✅ Automatic Fan ON/OFF  
✅ Real-time Temperature Monitoring  
✅ PWM-based Speed Control  
✅ Serial Monitor Output  
✅ Expandable for IoT Applications  


### Note:
This project was developed as a group collaboration, with responsibilities shared among team members.
---


