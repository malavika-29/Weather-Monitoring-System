# 🌦️ Weather Monitoring System (ESP8266 + Blynk)

An IoT-based system that measures **temperature**, **humidity**, and **rain detection** using **DHT11**, **rain sensor**, and **LCD (I2C)**.  
Data is displayed locally and sent to the **Blynk IoT app** for real-time monitoring.



## ⚙️ Features
- 🌡️ Temperature and humidity monitoring (DHT11)  
- 🌧️ Rain detection with LED indication  
- 🖥️ LCD display via I2C  
- 📱 Remote monitoring through Blynk app  
- ⏱️ Non-blocking timer operation using `BlynkTimer`



## 🧩 Components

| Component | Description |
|:--|:--|
| ESP8266 (NodeMCU) | WiFi-enabled microcontroller |
| DHT11 Sensor | Temperature & humidity sensor |
| Rain Sensor | Digital rain detection |
| LCD 16x2 + I2C | Real-time display |
| Breadboard & Jumpers | Circuit connections |



## 🔌 Connections

| ESP8266 Pin | Connected To | Function |
|:--|:--|:--|
| D4 | DHT11 Data | Sensor input |
| D6 | Rain Sensor S | Rain detection |
| D1 | LCD SCL | I2C Clock |
| D2 | LCD SDA | I2C Data |
| 3V3 / 5V | VCC | Power |
| GND | GND | Common ground |

---

## 📱 Blynk Setup

- **Template Name:** Weather Monitoring System  
- **Datastreams:**
  - `V0` → Temperature (°C)
  - `V1` → Humidity (%)
  - `V2` → Rain Status (Text)
- Copy your **BLYNK_TEMPLATE_ID**, **BLYNK_TEMPLATE_NAME**, and **AUTH TOKEN** into the code.

---

## 🧠 Working

1. DHT11 reads temperature & humidity.  
2. Rain sensor detects water on its surface.  
3. ESP8266 updates readings every 2 seconds using `timer.run()`.  
4. Data is displayed on LCD and sent to the Blynk app.  

---

## 🧰 Required Libraries

Make sure these are installed in Arduino IDE:  
- `ESP8266WiFi.h`  
- `BlynkSimpleEsp8266.h`  
- `Wire.h`  
- `LiquidCrystal_I2C.h`  
- `DHT.h`

You can install them using **Library Manager → Search → Install**.



## 🪄 How to Upload & Run

1. **Install Arduino IDE** (latest version).  
2. **Add ESP8266 Board Manager URL:**
   - Go to **File → Preferences → Additional Board URLs**
   - Add:  
     ```
     https://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
3. **Install ESP8266 Board** via **Tools → Board → Boards Manager**.  
4. **Select Board:** `NodeMCU 1.0 (ESP-12E Module)`.  
5. **Select Port:** the COM port of your ESP8266.  
6. **Open this project code** in Arduino IDE.  

**Enter your WiFi credentials** and **Blynk Auth Token** in the code.  
8. **Upload the code** to your ESP8266.  
9. Open **Serial Monitor** at 9600 baud to see live data.  
10. Open the **Blynk app** to monitor temperature, humidity, and rain status remotely.



## 📷 Diagram
 ![weather_crcut](https://github.com/user-attachments/assets/9e7ed743-3848-44fb-af86-5cd6a80be719)




## 📽️ Working Video
https://github.com/user-attachments/assets/ab4d615d-0acc-4f46-ab65-5ce9ae2c154d

## 📄Report
[Weather_Monitoring_System_Report - Copy.pdf](https://github.com/user-attachments/files/22996289/Weather_Monitoring_System_Report.-.Copy.pdf)
