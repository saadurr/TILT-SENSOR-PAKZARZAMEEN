/*
 * Developer Name: Saad Ur Rehman
 * Project Name: Development of a Low-Cost Tilt Sensing System for Construction Health Monitoring
 * Project by: Pak Zar Zameen
 * Supervisor: Dr. Waqar Shahid Qureshi
 * Research Funded by: AIT Solutions
 */
 
#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
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

unsigned long time_now = 0;
unsigned long time_start = 0;
unsigned const int OFF_TIME = 30000; //30 seconds

//===================Serial Communication Functions========================
void recvWithStartEndMarkers();
void parseData();
void showParsedData();
void serialReceive();
//======================================================================


 //==================INTERRUPT========================
void sleepTimer(void); //calculate time to sleep
void enterSleep(void); //ESP deep sleep mode
 //=================================================



//==============WiFi ESP8266=======================
void upload();
//==============================================
