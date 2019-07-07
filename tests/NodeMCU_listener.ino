#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
SoftwareSerial mySerial(D7, D8); //software serial /// replace by serial3 for mega2560

const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

// variables to hold the parsed data
float pitch = 0.0000;
float roll = 0.0000;

float pitch_avg = 0.00, roll_avg = 0.00;

boolean newData = false;


//============

void setup() {
  Serial.begin(9600);
  mySerial.begin(115200);
  Serial.println();
}

//============

void loop()
{
  recvWithStartEndMarkers();
  
  for (int i = 0; i < 5; i++) //Take Five Values of Each Reading and then average
  {
    if (newData == true)
    {
      strcpy(tempChars, receivedChars);
      parseData();
      //    showParsedData();
      newData = false;
    }
    pitch_avg = pitch + pitch_avg;
    roll_avg = roll + roll_avg;
  }
  pitch_avg = pitch_avg / 5; // calculate average
  roll_avg = roll_avg / 5; //
  Serial.println("Average Value of Pitch: ");
  Serial.println(pitch_avg);
    Serial.println("Average Value of Roll: ");
  Serial.println(roll_avg);
//  pitch = pitch_avg;
//  roll = roll_avg;
  showParsedData();
}

//============

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (mySerial.available() > 0 && newData == false) {
    rc = mySerial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

//============

void parseData() {

  char * strtokIndx;

  strtokIndx = strtok(tempChars, ",");
  pitch = atof(strtokIndx);

  strtokIndx = strtok(NULL, ",");
  roll = atof(strtokIndx);     // convert this part to a float

}

//============

void showParsedData() {
  Serial.print("Pitch: ");
  Serial.println(pitch, 10);
  Serial.print("Roll: ");
  Serial.println(roll, 10);
}
