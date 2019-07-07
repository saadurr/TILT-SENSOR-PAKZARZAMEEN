#include <ESP8266WiFi.h>
void setup() {
  Serial.begin(115200);
  Serial.println("I'm going into deep sleep mode forever");
  delay(1000);
}

void loop() {
  for (int i = 0; i < 100; i++)
    Serial.println("Hi, I am awake.\n");
  ESP.deepSleep(0);
}
