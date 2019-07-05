#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <avr/sleep.h>
//#include <avr/power.h>
#include <String.h>
SoftwareSerial adicup(D7, D8); //software serial


const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

// variables to hold the parsed data
float pitch = 0.0000;
float roll = 0.0000;

float pitch_avg = 0.00, roll_avg = 0.00;
boolean newData = false;

char auth[] = "5d5833999f9a46498be4281101f58dc8";
char ssid[] = "nodemcu";
char pass[] = "12345678";
BlynkTimer timer;


unsigned int interruptPin = D0;
//===================Serial Communication Functions========================

void recvWithStartEndMarkers();
void parseData();
void showParsedData();
void serialReceive();


//======================================================================


 //==================INTERRUPT========================
 void wakeInterrupt(void); //interrupt ISR
 void enterSleep(void); //Arduino Sleep
 //=================================================



//==============WiFi ESP8266=======================
void upload();
//==============================================
