#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "WiFi_SSID";
const char* password = "WiFi_Password";

WiFiServer g_Server(80);

void stop()
{
  analogWrite(D0, 0);
  analogWrite(D5, 0);
  analogWrite(D6, 0);
  analogWrite(D7, 0);
}

void setup() 
{
  pinMode(D0, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  // Set PWM frequence (in Hz)
  analogWriteFreq(1000);

  stop();

  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi network
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  g_Server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

String getParam(String s, int index)
{
  int end_pos = -1;
  
  for (int i = 0; i < index; i++)
  {
    s = s.substring(end_pos + 1);
    end_pos = s.indexOf(',');
    if (end_pos == -1)
      return s;
  }

  return s.substring(0, end_pos);
}

void parseData(String s)
{
  switch (s[0])
  {
  case 'S':
    {
      s = s.substring(2);

      // PWMRANGE = 1023 (max pwm)

      stop();

      int pwm1 = getParam(s, 1).toInt();
      int pwm2 = getParam(s, 2).toInt();
      
      Serial.println(pwm1);
      Serial.println(pwm2);

      if (pwm1 > 0) analogWrite(D0,  pwm1);
      if (pwm1 < 0) analogWrite(D5, -pwm1);

      if (pwm2 > 0) analogWrite(D6,  pwm2);
      if (pwm2 < 0) analogWrite(D7, -pwm2);
    }
    break;
  }
}

void loop() 
{
  WiFiClient client = g_Server.available();
  if (!client)
    return;

  Serial.println("Client connected");
  client.setTimeout(5000);
   
  while (client.connected()) 
  {
    if (client.available())
    {
      String input = client.readStringUntil('\r');
      Serial.print("Received: ");
      Serial.println(input);
      
      parseData(input);

      client.print("ACK\r");
    }
  }

  Serial.println("Disconnected");
}
