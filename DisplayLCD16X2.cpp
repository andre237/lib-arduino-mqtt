#include "DisplayLCD16X2.h"

DisplayLCD16X2::DisplayLCD16X2(uint8_t endereco) : _display(endereco, 16, 2) {
    _display.init(); // inicializa o LCD
    _display.backlight(); // liga o backlight do LCD
    _display.clear();
    _display.setCursor(0, 0);
}

void DisplayLCD16X2::limpar() {
    _display.clear();
}

void DisplayLCD16X2::escreverLinha1(const char* texto) {
    _display.setCursor(0, 0);
    _display.print(texto);
}

void DisplayLCD16X2::escreverLinha2(const char* texto) {
    _display.setCursor(0, 1);
    _display.print(texto);
}