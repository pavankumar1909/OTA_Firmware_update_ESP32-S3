#ifndef __MQTTCLIENT_H__
#define __MQTTCLIENT_H__

void mqtt_setup();                             // makes an mqtt setup and intial connection
void callback(char *,byte*, unsigned int);     // function receives the mqtt payload
void reconnect();                              // Tries to reconnect to mqtt server&topic if disconnects 
bool connect_to_mqttTopic();                   // connects to client and its topic
void check_mqtt_connection();                  // checks mqtt connection status
 
#endif //__MQTTCLIENT_H__
