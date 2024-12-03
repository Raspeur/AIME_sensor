#ifndef MY_OLED_SCREEN_H
#define MY_OLED_SCREEN_H

#include <Arduino.h> 
#include <Adafruit_SSD1306.h>


class OledScreen {
private:
    int nombreDePixelsEnLargeur=128;         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
    int nombreDePixelsEnHauteur=64;          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
    int brocheResetOLED=-1;          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
public:
    int adresseI2CecranOLED=0x3C;        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)
    Adafruit_SSD1306 oled;
    OledScreen();
    void initScreen();
    template <typename TypeText>
    void DisplayText(int positionX, int positionY, TypeText texte, int tailleTexte) {
        oled.setTextSize(tailleTexte);
        oled.setTextColor(SSD1306_WHITE);
        oled.setCursor(positionX, positionY);
        oled.print(texte);
        oled.display();
    }
};

#endif