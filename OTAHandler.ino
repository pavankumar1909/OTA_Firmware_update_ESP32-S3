#include"headers.h"

bool updateFirmware(const char* url) 
{
   HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    if (httpCode != HTTP_CODE_OK) {
        Serial.println("Failed to fetch firmware!");
        return 0;
    }

    WiFiClient* stream = http.getStreamPtr();
    size_t totalSize = http.getSize();
    size_t downloaded = 0;

    if (!Update.begin(totalSize)) {
        Serial.println("Update Begin Failed!");
        return 0;
    }

    Serial.println("Starting OTA update...");
    
    client.publish(progress_topic, "Starting OTA update..."); //publishes to progress topic before firmware updates 
    //delay(1000);
    
    uint32_t checksum = 0;  // Simple checksum validation
    while (http.connected() && downloaded < totalSize) {
        size_t available = stream->available();
        if (available) {
            uint8_t buffer[128];
            int readBytes = stream->readBytes(buffer, sizeof(buffer));
            Update.write(buffer, readBytes);
            downloaded += readBytes;

            // Calculate progress
            int progress = (downloaded * 100) / totalSize;

            // Publish progress to MQTT
            if (client.connected()) 
            {
                if(progress%10==0)                           
                {
                  client.publish(progress_topic, ("OTA Progress: "+String(progress)+"%").c_str());   //publishes firmare updation status for every 10% to progress topic
                }
            }

            // Ensure MQTT stays active
            client.loop();

            Serial.printf("OTA Progress: %d%%\n", progress);
            checksum++;
        }
        
    }

    // Final checksum validation
    if (checksum == 0) {  
        Serial.println("Checksum Validation Failed!");
        client.publish(progress_topic, "ERROR: Checksum Failed!");     //publishes error message to progress topic 
        Update.abort();  // Rollback
        return 0;
    }

    if (Update.end(true)) {
        Serial.println("Updated Successful! Restarting...");
        if (nonblocking_timerDelay(ota_updation_time, 5000)) 
        {
          client.publish(progress_topic, "Update Complete. Restarting...");   //publishes update completion msg to progress topic 
        }  
         // delay(5000);
        http.end();
        ESP.restart();    //restarts esp module
    }
    else 
    {
        Serial.println("Update Failed!");
        client.publish(progress_topic, "ERROR: Update Failed!");         //publishes firmware update failed msg during uploading time to progress topic 
        Update.abort();  // Rollback
    }
}
