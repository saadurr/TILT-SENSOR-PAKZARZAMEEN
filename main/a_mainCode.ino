/*
 * Developer Name: Saad Ur Rehman
 * Project Name: Development of a Low-Cost Tilt Sensing System for Construction Health Monitoring
 * Project by: Pak Zar Zameen
 * Supervisor: Dr. Waqar Shahid Qureshi
 * Research Funded by: AIT Solutions
 */

#include "main.h"


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  adicup.begin(115200);
  Serial.println();
  timer.setInterval(1000L, upload);
  time_start = millis();
}

void loop() {
  serialReceive();
  
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  
  sleepTimer(); //calculate time
  if (time_now >= OFF_TIME)
    enterSleep();
}
