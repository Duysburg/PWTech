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
    -powerPin: int
    -readingPin: int
    +actual_moisture: int
    +Sensor(int pumpPin)
    +moistureSensor(): int
}
class Plant{
    +name: String
    +optmoisture: int
    +thresh: int
    +sensor: Sensor 
    +pump: Pump 
}
class Pump{
    +pumpPin: int 
    +Pump(int pumpPin)
    +setPumpActivity(bool pumpActivity): void
    +pumpForTime(unsigned long timeMillis): void
}
class RobotBrain{
    -mainPump: Pump
}
class ServerRequester{
    -_apiAdress: string 
    -_ssid: char* 
    -_password: char* 
    +ServerRequester(string apiAdress)
    +void requestServer()
}

Plant "1" --o "1" Sensor
Plant "1" --o "1" Pump

RobotBrain "1" --> "1..*" Pump
```
