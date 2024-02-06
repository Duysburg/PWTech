# PWTech
Plant Watering Tech - [Website](https://hpyGithub.github.io)

### Moisture Measurements
| Zustand | Messwert | 
| --- | --- |
| trocken | 485 |
| nass | 204 |
| trocken | 465 |
| trocken | 440 |
| nass (direkt beim Gießen) | 205 |
| nass | 220 |
| übergossen | 191 |

***
### class diagram of the code base

*(last updated: 03.02)*
```mermaid
classDiagram
	class Pump {
		+PumpPin : int
		+setPumpActivity(int pumpActivity) void
		+pumpForTime(unsigned long pumpTimeMillis) void
		Pump(int pumpPin)
	}
	class Plant {
		-plantName : String
		-optimalMoisture : int
		-moistureThreshhold : int
		-wateringDuration : int
		-robotBrain : *RobotBrain
		-sensor : *Sensor
		-checkSensor() bool
		-blinkLed(int durationInMillis) void
		+currentlyBeingWatered : bool
		+updatePlant() void
		Plant(RobotBrain* robotBrain, String plantName, int wateringDuration, int optimalMoisture, int threshhold, int sensorPin)
	}
	class Sensor {
		-readingPin : int
		+measureMoisture() int
		Sensor(int readingPin)
	}
	class RobotBrain {
		+pump : *Pump
		+currentlyWatering : bool
		RobotBrain(int pumpPin)
		+requestWatering(unsigned long duration) void
	}
	Plant "1..*" --> "1" RobotBrain
	Plant "1" --o "1" Sensor
	RobotBrain "1" --o "1..*" Pump
```
