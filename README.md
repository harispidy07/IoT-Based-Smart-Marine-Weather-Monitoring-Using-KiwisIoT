# IoT-Based Smart Marine Weather Monitoring Using KiwisIoT

## Project Overview

This project monitors weather conditions in marine environments using IoT technology. An ESP8266 NodeMCU collects environmental data through connected sensors and sends the readings to the KiwisIoT platform for remote monitoring. It helps track weather conditions and supports safer marine operations.

## Hardware Components

- ESP8266 NodeMCU
- Environmental Sensors
- Jumper Wires
- Power Supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library

## Circuit Connections

Sensor connections depend on the hardware configuration used in the project.

## Working Principle

The connected sensors collect environmental readings from the marine surroundings. The ESP8266 processes the sensor data and transmits it to the KiwisIoT platform, allowing users to monitor marine weather conditions remotely through an IoT dashboard.

## KiwisIoT Dashboard

The dashboard displays collected weather parameters for remote monitoring.

| Data               | Description                         |
| ------------------ | ----------------------------------- |
| Weather Parameters | Environmental sensor readings       |
| Monitoring Status  | Live monitoring information         |
| Remote Access      | Weather monitoring through KiwisIoT |

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor marine weather conditions through the KiwisIoT dashboard.

## Applications

- Marine weather monitoring
- Coastal weather observation
- Smart port management
- Marine environmental monitoring
- Weather condition tracking

## Project Reference

**Hackster.io Project:**  
[https://www.hackster.io/harispidy07/iot-based-smart-marine-weather-monitoring-using-kiwisiot-5b3513](https://www.hackster.io/harispidy07/iot-based-smart-marine-weather-monitoring-using-kiwisiot-5b3513)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Built using ESP8266 and KiwisIoT for smart marine weather monitoring._
