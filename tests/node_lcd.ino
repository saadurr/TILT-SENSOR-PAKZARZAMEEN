#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned int angle = 10;
void setup() {
Serial.begin(115200);
//Use predefined PINS consts
Wire.begin(D2, D1);
lcd.begin();
lcd.home();
lcd.print("Hello, NodeMCU");
}

void loop() { // do nothing here }
  lcd.setCursor(0,1);   // sets cursor at column 0 row 1
  lcd.print("Angle: ");      // prints temperature in degree Celsius
  lcd.print(angle);
  lcd.print((char)223);
  angle++;
}
