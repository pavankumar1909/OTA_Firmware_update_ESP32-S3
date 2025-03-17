# OTA_Firmware_update_ESP32-S3

This project implements **Over-the-Air (OTA) firmware updates** for ESP32 using **MQTT and HTTP**.

## Features 🚀
- 🔹 WiFi & MQTT Auto-Reconnect
- 🔹 OTA firmware updates via HTTP
- 🔹 Publishes progress updates to MQTT
- 🔹 Ensures non-blocking execution
- 🔹 Rolls back if the update fails

## Hardware Requirements 🛠️
- ESP32 Board
- WiFi Connection
- MQTT Broker (e.g., Mosquitto, HiveMQ)
- HTTP Server for `.bin` firmware updates

