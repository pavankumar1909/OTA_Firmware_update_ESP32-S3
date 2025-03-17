#include"headers.h"
#include"MQTTClient.h"
#include"OTAHandler.h"
#include"network_credentials.h"


WiFiClient espClient;
PubSubClient client(espClient);

void reconnect_mqtt() 
{
        Serial.print("Connecting to MQTT...");
        if (client.connect(mqtt_client_id)) {
            Serial.println("Connected!");
            client.subscribe(topic);  // Subscribe to topic
        } 
        else 
        {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying...");
        }
}

void callback(char* topic, byte* message, unsigned int length) {
    
    Serial.print("Message received is : ");
    String firmwareUrl = "";
    for (int i = 0; i < length; i++) {
        firmwareUrl += (char)message[i];
    }
    
    Serial.println(firmwareUrl);
    Serial.println("Starting OTA update...");
    
    if (updateFirmware(firmwareUrl.c_str())) {
        Serial.println("Update successful! Restarting...");
        ESP.restart();
    } else {
        Serial.println("Update failed!");
    }
}

void mqtt_setup() 
{
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
    if (client.connect(mqtt_client_id)) 
    {
       Serial.println("MQTT Connected!");
       client.subscribe(topic);  // Subscribe to topic
    } 
    
}

bool check_mqtt_connection() 
{
    
    if (!client.connected()) 
    {
      return 0;
      //reconnect();
    }
    else{
      client.loop();
      return 1;}
    
}
