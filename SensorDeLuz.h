#ifndef ARDUINOLIBREDES_SENSORDELUZ_H
#define ARDUINOLIBREDES_SENSORDELUZ_H

class SensorDeLuz {
public:
    SensorDeLuz(int pin);
    int getValorAtual();
private:
    int _pin;
};


#endif //ARDUINOLIBREDES_SENSORDELUZ_H
