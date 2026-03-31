
 
## FireBot — Autonomous Fire Detection System

> Mobile fire detection robot with real-time IoT monitoring, alerting, and autonomous observation.
---

## Overview

FireBot is an autonomous fire-detection system designed to identify fire presence and notify users in real time via an IoT dashboard.

Unlike traditional systems, FireBot introduces **mobility + continuous monitoring**, enabling detection in dynamic environments.
```
The system focuses on:
- early detection  
- real-time alerts  
- reduced human dependency  
```
---

## Key Features
```
-  Flame-based fire detection  
-  Real-time IoT dashboard (Blynk)  
-  Instant alert triggering  
-  Mobile robotic platform  
-  Continuous monitoring loop  
```
---

## System Architecture



```
      ┌──────────────┐
      │ Flame Sensor │
      └──────┬───────┘
             │
             ▼
      ┌──────────────┐
      │  ESP8266 MCU │
      │ (Processing) │
      └──────┬───────┘
             │
    ┌────────┴────────┐
    ▼                 ▼


┌──────────────┐   ┌──────────────┐
│ Motor Driver │   │ Blynk Cloud  │
│  (Mobility)  │   │  Dashboard   │
└──────────────┘   └──────┬───────┘
▼
┌──────────────┐
│   User Alert │
└──────────────┘

```

---

## System Flow

```

Sensor → Detection → Processing → Alert → Monitoring Loop

```

### Working Logic
```
- Flame sensor continuously scans environment  
- ESP8266 processes sensor input in real time  
```
```
**On fire detection:**
- System enters alert state  
- Blynk dashboard is updated instantly  
- User receives notification  
- Monitoring continues without interruption  
```
---

## Hardware Used
```
- NodeMCU (ESP8266)  
- Flame sensor  
- Motor driver (L298N)  
- Robotic chassis  
- Power module  
```
---

## Software Stack
```
- Arduino framework  
- Blynk IoT platform  
```
---

## Design Decisions

### Why ESP8266
```
- Built-in WiFi → direct cloud connectivity  
- Lightweight and efficient for real-time systems  
```
### Why Blynk
```
- Fast IoT dashboard setup  
- Real-time visualization and alerts  
```
### Why Mobile Platform
```
- Covers larger area than fixed systems  
- Enables dynamic monitoring  
```
---

## Real-World Use Cases
```
- Industrial safety monitoring  
- Warehouses and storage units  
- Laboratories  
- Remote or unmanned environments  
```
---

## Limitations & Challenges
```
- False triggers from bright light sources  
- Limited detection range  

```
---

## Key Learnings
```
- Sensor calibration directly affects reliability  
- IoT integration simplifies monitoring systems  
- Continuous systems must handle noise and false positives  
- Automation significantly reduces response time  
```
---


The system follows:

```

Observe → Detect → Decide → Alert → Continue Monitoring

```

This ensures fast response without human dependency.

---
```

---
