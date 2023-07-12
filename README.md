 
# Traffic Signal Optimization System

## Problem
### The prevalent problem addressed by the project is the significant amount of time wasted in traffic congestion.



<div align="center">
  <img src="https://github.com/TXWISSRX/Smart_Traffic_NRW/assets/119014917/ef6f4ea9-9860-4251-abf2-6cdd056bc739" alt="Robot Image">
</div>

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [System Architecture](#system-architecture)
- [Installation](#installation)
- [Acknowledgements](#acknowledgements)

## Introduction


<div align="center">
  <img src="https://github.com/TXWISSRX/Smart_Traffic_NRW/assets/119014917/f9233844-6638-4fb0-b6b0-d5384ccf3805" alt="Robot Image"  height="180">
</div>
<br>

The Traffic Signal Optimization System is a project aimed at tackling the issue of time waste in traffic by implementing an intelligent system that optimizes traffic signal timings. By increasing the duration of green lights on busy roads, we can minimize congestion and enhance the flow of vehicles, ultimately reducing the time commuters spend waiting at red lights. This project aims to provide a smoother traffic experience, improved efficiency, and time savings for individuals and the community as a whole.

## Features
- Intelligent traffic signal timing optimization.
- Dynamic adjustment of green light durations based on real-time traffic conditions.
- Support for multiple intersections and road networks.
- Data-driven approach using traffic data and machine learning algorithms.
- User-friendly interface for configuration and monitoring.

## Technologies Used
The Traffic Signal Optimization System utilizes the following technologies:

### Software


<div align="center">
  <img src="https://github.com/TXWISSRX/Smart_Traffic_NRW/assets/119014917/4bb66328-cdee-490a-84ba-e611507cd757" alt="Robot Image"  width="600" height="120">
</div>

- **Solidworks**: Used for designing and modeling the physical structure and layout of traffic signal systems.

- **YOLOv7**: An object detection algorithm used for real-time traffic analysis and vehicle detection.

- **Arduino**: An open-source electronics platform used for controlling and interfacing with the traffic signal hardware.

- **Firebase**: A real-time database and backend-as-a-service platform used for storing and retrieving traffic data and configurations.

- **React**: A JavaScript library used for building user interfaces, providing a user-friendly interface for system configuration and monitoring.

- **OpenCV**: An open-source computer vision library used for image processing, allowing for traffic analysis and vehicle detection.
### Hardware

<div align="center">
  <img src="https://github.com/TXWISSRX/Smart_Traffic_NRW/assets/119014917/0e446807-b53f-40e9-8862-88d6bce0a30c" alt="Robot Image">
</div>

- **ESP32**: A powerful microcontroller board with built-in Wi-Fi and Bluetooth capabilities, used for controlling the traffic signal lights and communicating with other components of the system.

- **Raspberry Pi 4**: A single-board computer used for running the software components of the Traffic Signal Optimization System, including the object detection algorithm, database communication, and user interface.

- **LEDs**: Light-emitting diodes are used as the actual traffic signal lights. They are connected to the ESP32 board and controlled based on the system's optimization algorithms and traffic conditions.

## System Architecture


<br>

The Traffic Signal Optimization System follows a client-server architecture. The Raspberry Pi 4 serves as the central server, running the main software components and coordinating the operation of the system. The ESP32 boards are used as clients, responsible for controlling the traffic signal lights at each intersection.

The Raspberry Pi 4 communicates with the ESP32 boards over a wireless connection. It receives real-time traffic data from the ESP32 boards and uses the YOLOv7 object detection algorithm and OpenCV for analyzing the data and detecting vehicles. The optimized traffic signal timings and patterns are then calculated based on the analysis.

The ESP32 boards receive the updated signal timings and patterns from the Raspberry Pi 4 and control the LEDs accordingly. They also send the current traffic data to the Raspberry Pi 4 for further analysis and optimization.

The Firebase real-time database is used to store and retrieve traffic data and configurations. The React-based user interface provides a user-friendly way to configure and monitor the system. It communicates with the Raspberry Pi 4 through the Firebase API, allowing users to view real-time traffic conditions, change system configurations, and monitor the overall performance of the Traffic Signal Optimization System.


## Installation
### Prerequisites
- Python 3.x
- Arduino IDE
- Solidworks (optional)
- Anaconda 


## Acknowledgements

We would like to thank the following individuals and organizations for their contributions and support:

- Solidworks: For providing a powerful tool for designing the physical structure and layout of traffic signal systems.
- YOLOv7: For the object detection algorithm used for real-time traffic analysis and vehicle detection.
- Arduino: For the open-source electronics platform used for controlling and interfacing with the traffic signal hardware.
- Firebase: For the real-time database and backend-as-a-service platform used for storing and retrieving traffic data and configurations.
- React: For the JavaScript library used for building user interfaces, providing a user-friendly interface for system configuration and monitoring.
- OpenCV: For the open-source computer vision library used for image processing, allowing for traffic analysis and vehicle detection.

