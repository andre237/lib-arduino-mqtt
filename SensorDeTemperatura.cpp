#include "SensorDeTemperatura.h"

#define DHTTYPE DHT11

SensorDeTemperatura::SensorDeTemperatura(int pin) : _dht(pin, DHTTYPE) {
    _dht.begin();
}

float SensorDeTemperatura::getValorAtual() {
    return _dht.readTemperature();
}
