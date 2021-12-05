/*
  Fonctionne avec tous les LCD compatible contrôleur Hitachi HD44780.
  Le circuit:
   LCD RS pin -> digital pin 12
   LCD Enable pin -> digital pin 11
   LCD D4 pin -> digital pin 5
   LCD D5 pin -> digital pin 4
   LCD D6 pin -> digital pin 3
   LCD D7 pin -> digital pin 2
   LCD R/W pin -> ground
   LCD VSS pin -> ground
   LCD VCC pin -> 5V
   220 résistance : pour la led d’allumage du lcd
   10K potentiomètre : pour le contraste du lcd
   +5V -> pot ->  gnd
    |
   LCD VO pin (pin 3)
*/

#include <LiquidCrystal.h>
#define CANPIN A0
// initialisation de la librairie
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte OHM[8] = {
        B00000,
        B01110,
        B10001,
        B10001,
        B01010,
        B11011,
        B00000,
        B00000
};

float R1 = 7800.0F;
float VIN = 5.0F;

void setup()
{
    //set up du caractère personnalisé
    lcd.createChar(0, OHM);
    // set up du lcd avec dimensions
    lcd.begin(16, 2);
    // Ecrire un message
    lcd.print("arduino");
    // positionner le curseur d'écriture
    lcd.setCursor(7, 1);
    lcd.print("ohm mètre");
    delay(2500);
    // vider l'écran
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ohm mètre");
    lcd.setCursor(0, 1);
    lcd.print("Res : ");
}

void loop()
{
    // récupérer la tensions aux bornes de R2
    int canValue = analogRead(CANPIN);
    // tension en A3
    float vOut = canValue * (VIN / 1024);
    // calcul:
    // vOut=(R1/(R1+R2)) * VIN
    // r2=R1 * ( VIN / vOut) -R1
    float r2 = R1 * (VIN / vOut) - R1;
    lcd.setCursor(6, 1);
    lcd.print(r2);
    lcd.write(0);
}
