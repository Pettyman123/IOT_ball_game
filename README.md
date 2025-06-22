# 🎮 ESP32 Bouncing Ball Game

A fun and simple **bouncing ball game** built using an **ESP32**, an **analog joystick**, and a **0.96" OLED SSD1306 display**. Move the paddle using the joystick to keep the ball from falling!

---
#Tell me its not over yet! We keep going on okay! OKAY!

![image](https://github.com/user-attachments/assets/68fd4189-4c51-4f96-a987-a29b14c5e438)

## 📦 Components Used

- 🧠 **ESP32 Dev Module**
- 🎮 **Analog Joystick Module**
- 🖥️ **0.96" I2C OLED Display (SSD1306)**
- 🔌 Breadboard and jumper wires (optional)

---

## 🔧 Circuit Diagram

| Component       | ESP32 Pin  |
|----------------|------------|
| **Joystick GND** | GND        |
| **Joystick VCC** | 3.3V       |
| **Joystick VRx** | GPIO 34    |
| **OLED GND**     | GND        |
| **OLED VCC**     | 3.3V       |
| **OLED SCL**     | GPIO 22    |
| **OLED SDA**     | GPIO 21    |

---

## 🕹️ Game Features

- Move the **paddle left/right** using the **joystick**
- **Ball bounces** off the paddle and screen edges
- Speed increases with every paddle hit
- **Game over** screen when the ball falls

---

## 🧠 How It Works

- The **joystick** analog input controls horizontal paddle movement.
- A **ball object** falls down with increasing speed.
- The **OLED screen** displays the ball and paddle in real-time.
- The game **resets** after a miss.

---

## 🧰 Libraries Required

Install these libraries via Arduino Library Manager:

- [`Adafruit SSD1306`](https://github.com/adafruit/Adafruit_SSD1306)
- [`Adafruit GFX`](https://github.com/adafruit/Adafruit-GFX-Library)

> 📝 These are automatically included in [Wokwi](https://wokwi.com/), no installation needed there.

---

## 🚀 How to Run

### 🧪 On Wokwi

1. Open [Wokwi Simulator](https://wokwi.com/new).
2. Add:
   - ESP32 Dev Board
   - SSD1306 OLED Display (I2C)
   - Analog Joystick
3. Wire as per the table above.
4. Paste the game code into `main.ino`.
5. Click **"Start Simulation"**.

### 🛠️ Locally via Arduino IDE

1. Install the libraries mentioned above.
2. Select **ESP32 Dev Module** from Tools > Board.
3. Connect and upload the sketch via USB.

---

## 📸 Demo

![image](https://github.com/user-attachments/assets/7f4f4631-afc3-4c07-8f46-81d4d0970504)


---

## 💡 Future Improvements

- Add score tracking
- Add lives or levels
- Add sound using a buzzer
- Add pause/start button using joystick switch

---

## 📜 License

MIT License — feel free to use, remix, and share!

---
##MADE BY GOURAV SHARMA :) 
#Keep loving yourself
## 👨‍💻 Author

Built by [Your Name]  
Feel free to reach out or contribute!

