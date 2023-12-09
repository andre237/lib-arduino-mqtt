#ifndef ARDUINOLIBREDES_SENSORDELUZ_H
#define ARDUINOLIBREDES_SENSORDELUZ_H

class SensorDeLuz {
public:
    SensorDeLuz(int pin);
    SensorDeLuz(int pin, int maxSamples);
    void loop();
    int getValorAtual();
private:
    int _pin;
    int _accumulator = 0;
    int _samples = 0;
    int _maxSamples = 10;
    int _lastCalculatedValue = 0;
};


#endif //ARDUINOLIBREDES_SENSORDELUZ_H
