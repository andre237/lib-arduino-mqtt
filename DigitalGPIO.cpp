#include "DigitalGPIO.h"
#include "Arduino.h"

DigitalGPIO::DigitalGPIO(int pin) {
    _pin = pin;
    pinMode(_pin, OUTPUT);
}

void DigitalGPIO::liga() {
    digitalWrite(_pin, HIGH);
}

void DigitalGPIO::desliga() {
    digitalWrite(_pin, LOW);
}
