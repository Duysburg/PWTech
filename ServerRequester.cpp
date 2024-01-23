
#include <ESP8266WiFi.h>

class ServerRequester {
    private:
        string _apiAdress;
        const char* _ssid    = "name of network";
        const char* _password = "password of network";

    public:
        ServerRequester(string apiAdress) {
            // initalize variables
            _apiAdress = apiAdress;
            delay(10);

            // connect to wlan
            Serial.print("Connecting to ");
            Serial.println(_ssid);

            WiFi.begin(_ssid, _password);

            while (WiFi.status() != WL_CONNECTED) {
                delay(500);
                Serial.print(".");
            }

            // sucessfully connected to wlan
            Serial.println("WiFi connected \nIP address: ");
            Serial.println(WiFi.localIP());
        }

        void requestServer() {
            while (true) {
                // check if wifi is connected
                if (WIFI.status() != WL_CONNECTED) {
                    // wifi lost connection
                    Serial.println("No connection to WIFI (trying again in 1 second)");

                    // try again after 1 second
                    delay(1000);
                    continue;
                }

                HTTPClient http;
                http.begin(_apiAdress);
                int httpSuccessCode = http.Get();

                if (httpSuccessCode <= 0)
                {
                    // web request did not work
                    Serial.println("Error on HTTP request");
                    
                    // try again after 1 second
                    delay(1000);
                    continue;
                }

                // get response data
                String responseData = http.getString();
                Serial.println("Response: ");
                Serial.println(responseData);

                // process response data
                String processedData = responseData;

                // end http connection
                http.end();
                return processedData;
            }
        }
}