# PWTech
Plant Watering Tech - [Website](https://hpyGithub.github.io)

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

*(last updated: 25.01)*
```mermaid
classDiagram
	class ServerRequester {
		-_apiAdress : String
		-_ssid : String
		-_password : String
		ServerRequester(string apiAdress)
		+requestServer() void
	}
	class Plant {
		+name : String
		+optmoisture : int
		+thresh : int
		+_robotBrain : RobotBrain
		+sensor : Sensor
		+pump : Pump
		Plant(RobotBrain robotBrain, String plantname, int optimalmoisture, int threshhold, int sensorPin, int pumpPin)
		-checkSensor(): bool
		-blinkLed(): void
	}
	class Pump {
		+PumpPin : int
		Pump(int pumpPin)
		+setPumpActivity(bool pumpActivity) void
		+pumpForTime(unsigned long timeMillis) void
		+startTime : long
	}
	class RobotBrain {
		RobotBrain(Pump[] pumpList, unsigned long[] durationList)
		+requestWatering(Pump pump, unsigned long duration) void
		+TEST_Pump(int pumpPin) void
		+testPump : Pump
		+TEST_Sensor(int powerPin, int sensorPin) void
		+testSensor : Sensor
	}
	class Sensor {
		Sensor(int powerP, int readP)
		+moistureSensor() int
	}
	Plant "1..*" --> "1" RobotBrain
	Plant "1" --o "1" Sensor
	Plant "1..*" --o "1" Pump
	RobotBrain "1" --> "1" Pump
	RobotBrain "1" --> "1" Sensor
```
