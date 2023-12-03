#ifndef ARDUINOLIBREDES_SENSORDETEMPERATURA_H
#define ARDUINOLIBREDES_SENSORDETEMPERATURA_H

#include "DHT.h"

class SensorDeTemperatura {
public:
    SensorDeTemperatura(int pin);
    int getValorAtual();
private:
    DHT _dht;
};


#endif //ARDUINOLIBREDES_SENSORDETEMPERATURA_H
