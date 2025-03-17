#ifndef __MQTTCLIENT_H__
#define __MQTTCLIENT_H__

void mqtt_setup();                             // makes an mqtt setup and intial connection
void callback(char *,byte*, unsigned int);     // function receives the mqtt payload
void reconnect_mqtt();                              // Tries to reconnect to mqtt server&topic if disconnects 
bool check_mqtt_connection();                  // checks mqtt connection status
 
#endif //__MQTTCLIENT_H__
