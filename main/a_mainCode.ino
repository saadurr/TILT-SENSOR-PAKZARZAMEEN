//Saad Ur Rehman
//Development of Tilt Sensor
//Pak Zar Zameen
#include "main.h"


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  mySerial.begin(115200);
  Serial.println();
  timer.setInterval(1000L, upload);
  pinMode(interruptPin, INPUT); //pin for interrupt
}

void loop() {
  serialReceive();
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
