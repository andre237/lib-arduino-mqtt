#include "SensorDeLuz.h"
#include "Arduino.h"

SensorDeLuz::SensorDeLuz(int pin) {
    _pin = pin;
}

int SensorDeLuz::getValorAtual() {
    return analogRead(_pin);
}
