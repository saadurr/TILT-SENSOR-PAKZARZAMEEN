void wakeInterrupt(void)
{
  /* This will bring us back from sleep. */

  /* We detach the interrupt to stop it from
     continuously firing while the interrupt pin
     is low.
  */
  Serial.println("****INTERRUPT CALLED: WAKING UP****");
  milliseconds = millis();
  detachInterrupt(0);
}

void enterSleep(void)
{

  /* Setup pin2 as an interrupt and attach handler. */
  Serial.println("***Entering Sleep****");
  delay(200);
  attachInterrupt(0, wakeInterrupt, RISING);
  delay(100);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  /* The program will continue from here. */

  /* First thing to do is disable sleep. */
  sleep_disable();
}
