void upload()
{
  Blynk.virtualWrite(V1, pitch); //change v1 on app
//  Blynk.virtualWrite(V2, roll); //change v2 on app
}

void webDash()
{
  if (time_now >= 15000)
  {
    if (client.connect(server, 80))   
    {
      String postStr = apiKey;
      postStr += "&field1=";
      postStr += String(pitch);
      postStr += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);
    }
    client.stop();
  }
}
