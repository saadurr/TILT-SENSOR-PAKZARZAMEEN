//============
void serialReceive()
{
  adicup.listen();
  recvWithStartEndMarkers();

  //  for (int i = 0; i < 5; i++) //Take Five Values of Each Reading and then average
  //  {
  if (newData == true)
  {
    strcpy(tempChars, receivedChars);
    parseData();
    //    showParsedData();
    newData = false;
  }
//  pitch_avg = pitch + pitch_avg;
//  roll_avg = roll + roll_avg;
  //  }
  //  pitch_avg = pitch_avg / 5; // calculate average
  //  roll_avg = roll_avg / 5; //
  //  Serial.println("Average Value of Pitch: ");
  //  Serial.println(pitch_avg);
  //  Serial.println("Average Value of Roll: ");
  //  Serial.println(roll_avg);
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

  while (adicup.available() > 0 && newData == false) {
    rc = adicup.read();

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
