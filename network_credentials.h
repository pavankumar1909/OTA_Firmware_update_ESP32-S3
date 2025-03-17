#ifndef __NETWORK_CREDENTIALS_H__
#define __NETWORK_CREDENTIALS_H__

//wifi credentials
const char* ssid =  "PAVAN";        //replace with your wifi username
const char* password = "pavan0109";  //replace with your wifi password      

//mqtt credentials
const char* mqtt_server = "test.mosquitto.org";      //  MQTT brokerIP
const char* topic = "pavantest/topic";               // subscribing topic
const char* progress_topic = "pavandevice/progress"; // publishing topic
const char* mqtt_client_id = "ESP32_PAVAN_KUMAR";    // mqtt client name(ESP32-S3)

//http link

//const char* firmware_url = "http://192.168.100.5:8080/BasicOTA.ino.esp32.bin";

#endif //__NETWORK_CREDENTIALS_H__
