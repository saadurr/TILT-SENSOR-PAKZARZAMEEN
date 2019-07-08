/*
   Developer Name: Saad Ur Rehman
   Project Name: Development of a Low-Cost Tilt Sensing System for Construction Health Monitoring
   Project by: Pak Zar Zameen
   Supervisor: Dr. Waqar Shahid Qureshi
   Research Funded by: AIT Solutions
*/

#include "main.h"


void setup() {
  Serial.begin(9600);
  
  Blynk.begin(auth, ssid, pass);
  adicup.begin(115200);
  Serial.println();
  timer.setInterval(300L, upload); //runs every second (previous value was 500L)
  
  Wire.begin(D2, D1);
  lcd.begin();
  lcd.home();
  lcd.print("Tilt Sensor");
  
  time_start = millis();
}

void loop() {
  serialReceive();
  
  displayLCD(); //
  
  Blynk.run(); // Initiates BlynkTimer

  sleepTimer(); //calculate time
  //  if (time_now >= OFF_TIME)
  //    enterSleep();
  webDash();
  
  timer.run();
}
