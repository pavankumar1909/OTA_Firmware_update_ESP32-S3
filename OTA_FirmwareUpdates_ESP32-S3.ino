#include "headers.h"                // contains all header files
#include "network_credentials.h"    // wifi,mqtt usernameand passwords
#include "WiFiManager.h"            // prototypes of WIFIManager  
#include "MQTTClient.h"             // prototypes of MQTTClient

void setup() 
{
    Serial.begin(115200);
    wifi_setup();    //initialising wifi
    mqtt_setup();    //initialising mqtt
}

void loop() 
{
  
  if (nonblocking_timerDelay(wifi_reconnection_time, 1000)) 
  {
    if(!check_wifi_connection())       // reconnects to wifi in case if dis-connected
    {
      reconnect_wifi();
    }
  }
  if (nonblocking_timerDelay(mqtt_reconnection_time, 3000)) 
  {
    if(!check_mqtt_connection())      // reconnects to mqtt function to listen to the topic&broker
    {
      reconnect_mqtt();
    }
  }
}
