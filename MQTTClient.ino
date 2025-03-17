#include"headers.h"
#include"MQTTClient.h"
#include"OTAHandler.h"
#include"network_credentials.h"


WiFiClient espClient;
PubSubClient client(espClient);


bool connect_to_mqttTopic()
{
    if (client.connect(mqtt_client_id)) 
    {
       Serial.println("MQTT Connected!");
       client.subscribe(topic);  // Subscribe to test topic
       return true;
    } 
}

void reconnect() 
{
        
        if(connect_to_mqttTopic())
        {
          Serial.println("MQTT Reconnecting...");
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
    if(connect_to_mqttTopic())
    {
      Serial.println("Ok");
    }
    
}

void check_mqtt_connection() 
{
    
    if (!client.connected()) 
    {
      
      static unsigned long mqtt_reconnection_time = 0;
      if (nonblocking_timerDelay(mqtt_reconnection_time, 5000)) 
      {
        reconnect();
      }
    }
    client.loop();
}
