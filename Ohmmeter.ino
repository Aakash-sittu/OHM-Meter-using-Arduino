#include <LiquidCrystal.h>

//LiquidCrystal(rs, sc, d4, d5, d6, d7) 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int analogPin = 0;

int analogval = 0;
//int 5 = 5;
//vin is taken as 5
float buff = 0;
float vout = 0;
float R1 = 0;
float R2 = 470;

void setup() {
  lcd.begin(16, 2);
}

void loop() {

  analogval = analogRead(analogPin);
  if (analogval) {
    buff = analogval * 5;
    vout = (buff) / 1024.0;

    if (vout > 0.9) {
      buff = (5 / vout) - 1;
      R1 = R2 * buff;
      lcd.setCursor(0, 0);
      lcd.print("  -Resistance-");
      lcd.setCursor(0, 1);

      if ((R1) > 999) {
        lcd.print("   ");
        lcd.print(R1 / 1000);
        lcd.print("K ohm");
      }
      else {
        lcd.print("     ");
        lcd.print(round(R1));
        lcd.print(" ohm");
      }

      delay(1000);
      lcd.clear();

    }
    else {
      lcd.setCursor(0, 0);
      lcd.print(" ! Put Resistor");
      lcd.setCursor(0, 1);

    }
  }
}