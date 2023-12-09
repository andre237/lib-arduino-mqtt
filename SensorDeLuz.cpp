#include "SensorDeLuz.h"
#include "Arduino.h"

SensorDeLuz::SensorDeLuz(int pin) : _pin(pin) {}

SensorDeLuz::SensorDeLuz(int pin, int maxSamples) : _pin(pin), _maxSamples(maxSamples) {}

void SensorDeLuz::loop() {
    int cur = analogRead(_pin);
    if (_lastCalculatedValue == 0) {
        _lastCalculatedValue = cur;
    }

    _accumulator += cur;
    _samples += 1;

    if (_samples >= _maxSamples) {
        _lastCalculatedValue = _accumulator / _samples;
        _accumulator = 0;
        _samples = 0;
    }
}

int SensorDeLuz::getValorAtual() {
    return _lastCalculatedValue;
}
