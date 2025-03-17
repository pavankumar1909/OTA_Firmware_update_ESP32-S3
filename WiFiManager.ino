#include"headers.h"

//static unsigned long wifi_reconnection_time = 0;

void wifi_setup()
{
    
    WiFi.begin(ssid, password);

    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    
    Serial.println("\nConnected to Wi-Fi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP()); 
}

void reconnect_wifi()
{
    WiFi.reconnect();
}

bool check_wifi_connection()
{
  // Keep checking the connection
    if (WiFi.status() != WL_CONNECTED) 
    {
        Serial.println("Wi-Fi Disconnected!");
        return 0;
    }
    else{
      return 1;}
}
