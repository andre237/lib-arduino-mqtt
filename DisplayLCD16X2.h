#ifndef ARDUINOLIBREDES_DISPLAYLCD_H
#define ARDUINOLIBREDES_DISPLAYLCD_H

#include <inttypes.h>
#include <LiquidCrystal_I2C.h>

class DisplayLCD16X2 {
public:
    DisplayLCD16X2(uint8_t endereco);
    void limpar();
    void escreverLinha1(const char* texto);
    void escreverLinha2(const char* texto);
private:
    LiquidCrystal_I2C _display;
};


#endif //ARDUINOLIBREDES_DISPLAYLCD_H
