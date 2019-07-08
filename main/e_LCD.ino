void displayLCD()
{
  lcd.setCursor(0, 1);  // sets cursor at column 0 row 1
  lcd.print("Angle: ");      // prints temperature in degree Celsius
  lcd.print(pitch, 5);
  lcd.print((char)223);
}
