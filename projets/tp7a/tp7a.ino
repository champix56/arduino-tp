// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 5

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);


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
    // Start up the library
  sensors.begin();
  lcd.begin(16, 2);
  lcd.println("DS1307RTC");
}

void loop() {
  lcd.setCursor(0,9);
  lcd.print("      ");
  lcd.setCursor(0,9);

  sensors.requestTemperatures(); // Send the command to get temperatures
   // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    lcd.println(tempC);
  } 
  else
  {
    Serial.println("Error: Could not read temperature data");
  }
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
