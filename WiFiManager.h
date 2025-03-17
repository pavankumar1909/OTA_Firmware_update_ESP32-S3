#ifndef __WIFIMANAGER_H__
#define __WIFIMANAGER_H__

void wifi_setup();            // makes an wifi setup and intial connection
void reconnect_to_wifi();     // Tries to reconnect to wifi if disconnected
bool check_wifi_connection(); // checks wifi connection status and reconnects if disconnected

#endif //__WIFIMANAGER_H__
