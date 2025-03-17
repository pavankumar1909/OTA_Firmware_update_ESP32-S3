# OTA_Firmware_update_ESP32-S3

This project implements **Over-the-Air (OTA) firmware updates** for ESP32 using **MQTT and HTTP**.

## Features 🚀
- 🔹 WiFi & MQTT Auto-Reconnect
- 🔹 OTA firmware updates via HTTP
- 🔹 Publishes progress updates to MQTT
- 🔹 Ensures non-blocking execution
- 🔹 Rolls back if the update fails

## Requirements 🛠️
- ESP32 Board
- WiFi Connection
- MQTT Broker (e.g., Mosquitto, HiveMQ)
- HTTP Server for `.bin` firmware updates

## Installation 🛠️

### 1️⃣ **Clone Repository**
```sh
git clone https://github.com/YOUR_USERNAME/ESP32_OTA_MQTT.git
cd ESP32_OTA_MQTT
```

### 2️⃣ **Configure WiFi & MQTT**
Edit `OTA_Firmware_update_ESP32-S3.ino` and update:
```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "YOUR_MQTT_BROKER";
```

### 3️⃣ **Compile & Upload Code**
Use the **Arduino IDE**  to upload the code.

### 4️⃣ **Start HTTP Server**
Upload your **firmware `.bin` file** to an HTTP server.

For a simple Python server, run a HTTP server on your pc :
```sh
python3 -m http.server 8080
```
Your `.bin` file should be accessible at:
```
http://YOUR_PC_IP:8080/firmware.bin
```

### 5️⃣ **Publish MQTT Update Message**
Send the OTA update URL via MQTT:
```sh
mosquitto_pub -h YOUR_MQTT_BROKER -t "ota/update" -m "http://YOUR_PC_IP:8080/firmware.bin"
```
or 
```use sample python scripts to publish to the topics
```
## Troubleshooting 🛠️
- If WiFi disconnects, the ESP32 **automatically reconnects**.
- OTA update fails? Check:
  - MQTT broker is running.
  - HTTP server serves `.bin` files correctly.
  - ESP32 has enough memory.


