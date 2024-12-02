#include "oled_screen.h"


OledScreen::OledScreen() : oled(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED) { }

void OledScreen::DisplayText(Adafruit_SSD1306 oled, int positionX, int positionY, const char* texte, int tailleTexte) {
    oled.setTextSize(tailleTexte);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(positionX, positionY);
    oled.print(texte);
    oled.display();
}