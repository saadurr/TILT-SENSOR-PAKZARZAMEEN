void displayLCD()
{
  lcd.setCursor(0, 1);  // sets cursor at column 0 row 1
  lcd.print("Angle: ");      // prints temperature in degree Celsius
  lcd.print(pitch, 5);
  lcd.print((char)223);
}

void removeOffset()
{
  if (pitch > 0) //positive
  {
    pitch = abs(pitch - offset);
  }
  else if (pitch < 0)
  {
    pitch = abs(pitch + offset);
  }
}
