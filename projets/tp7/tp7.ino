//librairie i2C
#include <Wire.h>
//structure de gestion de temps
#include <TimeLib.h>
//librairie d'accès au RTC
#include <DS1307RTC.h>


// initialisation de la librairie LCD
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.println("DS1307RTC Read Test");
}

void loop() {
  tmElements_t tm;
  lcd.setCursor(1,0);
  lcd.print("                ");
  lcd.setCursor(1,0);
  if (RTC.read(tm)) {
    Serial.print("Ok, Time");
    print2digits(tm.Hour);
    lcd.print(':');
    print2digits(tm.Minute);
    lcd.print(':');
    print2digits(tm.Second);
    lcd.print(", Date (D/M/Y) = ");
    lcd.print(tm.Day);
    lcd.print('/');
    lcd.print(tm.Month);
    Serial.write('/');
    lcd.print(tmYearToCalendar(tm.Year));
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      lcd.print("erreur date");
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      lcd.print("erreur lecture");
    }
  }
  delay(1000);
}

void print2digits(int number) {
    
  if (number >= 0 && number < 10) {
    lcd.print("0");
  }
  
  lcd.print(number);
}