#ifndef ARDUINOLIBREDES_DIGITALGPIO_H
#define ARDUINOLIBREDES_DIGITALGPIO_H

class DigitalGPIO {
public:
    DigitalGPIO(int pin);
    void liga();
    void desliga();
private:
    int _pin;
};


#endif //ARDUINOLIBREDES_DIGITALGPIO_H
