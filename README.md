//FireBot//
//Automatic Fire Detection with Blynk Alerts//

//Overview:

-->An autonomous fire-detection robot designed to identify fire presence and notify users in real time using IoT dashboards.

-->The focus is on early detection and monitoring, not manual intervention.

//Features:

-->Fire detection using flame sensor

-->Real-time status updates on Blynk

-->Immediate alert when fire is detected

-->Modular robot design

//Hardware Used:

-->Nodemcu Esp8266

-->Flame sensor

-->Motor driver & chassis

-->Power module

//Software Stack

-->Arduino framework

-->Blynk IoT platform

//System Architecture

-->Flame sensor continuously monitors surroundings

-->ESP32 processes sensor data

//On fire detection:

-->Updates Blynk dashboard

-->Triggers alert state

-->System remains active for continuous monitoring

//Why This Project Matters

//Fire detection systems often:

-->rely on fixed infrastructure

-->lack mobility

-->This robot introduces mobility + real-time cloud monitoring, useful for warehouses, labs, and industrial safety.

//Limitations & Challenges

-->False triggers from light sources

-->Detection range limited by sensor quality

-->No extinguishing mechanism (monitoring only)

//Key Learnings

-->Sensor calibration is crucial

-->IoT dashboards simplify real-time monitoring

-->Automation reduces response time significantly

//Future Improvements

Multi-sensor fusion (smoke + heat)
