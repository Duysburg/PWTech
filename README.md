# PWTech
Plant Watering Tech - [Website](hpyGithub.github.io)

### Roadmap
| file/component name | file type |
|------|-----------|
| Pumping Unit | Header |
| Sensor Unit | Header |
| Plant Header | Header |
| Robot Brain | Arduino-Datei |
| Main Server | Header |

***
### class diagram of the code base

*(last updated: 23.01)*
```mermaid
classDiagram
class Sensor{
    int powerpin
    int actual_moisture
    Sensor(int pumpPin)
    void setMoistureSensor()
}
class Plant{
    String name
    int optmoisture
    int thresh
    Sensor sensor
    Pump pump
}
class Pump{
    int pumpPin
    Pump(int pumpPin)
}
Plant <|-- _Sensor
Plant *-- Pump

class ServerRequester {
    private:
        string _apiAdress
        const char* _ssid
        const char* _password
    public:
        ServerRequester(string apiAdress)
        void requestServer()
}
```