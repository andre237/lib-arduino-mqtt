cmake_minimum_required(VERSION 3.26)
project(ArduinoLibRedesV2)

set(CMAKE_CXX_STANDARD 11)

add_library(ArduinoLibRedesV2
        DisplayLCD16X2.cpp
        DigitalGPIO.cpp
        SensorDeLuz.cpp
        SensorDeTemperatura.cpp
        MQTTClient.h
        MQTTClient.cpp)
