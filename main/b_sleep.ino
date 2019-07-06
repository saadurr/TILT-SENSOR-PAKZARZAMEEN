void sleepTimer(void)
{
  time_now = millis();
  time_now = time_now - time_start;
}

void enterSleep(void)
{
  /* Copy contents and go to sleep*/
  Serial.println("***Entering Sleep****");
  delay(2000);
  ESP.deepSleep(0); /*Sleep Forever until RST pin is set LOW*/
}
