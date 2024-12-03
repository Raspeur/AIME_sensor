#include "oled_screen.h"

OledScreen::OledScreen() : oled(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED) {}

void OledScreen::initScreen() {
    if(!oled.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED)) { // Initialisation de l'écran OLED
        Serial.println(F("Erreur de communication avec le chipset SSD1306… arrêt du programme."));
        while(1);                                             // Arrêt du programme (boucle infinie)
    }
    oled.clearDisplay();  // Effaçage de l'intégralité du buffer
}
