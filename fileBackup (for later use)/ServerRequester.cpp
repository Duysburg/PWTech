
#include <ESP8266WiFi.h>

/**
 * @brief Class for handling server requests
 * -
 * This class handles requests to a server. It connects to the Wi-Fi network, 
 * and makes requests to the server repeatedly.
 */
class ServerRequester {
    private:
        String _apiAdress;
        String _ssid    = "name of network";
        String _password = "password of network";

    public:
        /**
         * @brief initializes the server requester
         * 
         * @param apiAdress the address of the api
         */
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

        /**
         * @brief Function for handling server requests
         * -
         * This function handles requests to a server. It connects to the Wi-Fi network, 
         * and makes requests to the server repeatedly.
         * 
         * @param apiAdress the address of the api
         * @return the processed response data from the server
         */
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