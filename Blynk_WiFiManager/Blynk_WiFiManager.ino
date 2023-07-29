#define BLYNK_PRINT Serial

#include <FS.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

#include <WiFiManager.h>

WiFiManager wm;
char blynk_token[34] = "YOUR_BLYNK_TOKEN";
//flag for saving data
bool shouldSaveConfig = false;

#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int pinLampu = 14;
int pinBuzz = 12;

BlynkTimer timer;
void sensor(){
  float suhu = dht.readTemperature();
  float klmb = dht.readHumidity();

  Blynk.virtualWrite(V0, klmb);
  Blynk.virtualWrite(V1, suhu);
  
}

void setup()
{
  Serial.begin(9600);
  initialize();
  pinMode(pinLampu, OUTPUT);
  pinMode(pinBuzz, OUTPUT);
  Blynk.begin(blynk_token, WiFi.SSID().c_str(), WiFi.psk().c_str());
  dht.begin();
  timer.setInterval(1000L, sensor);
}

BLYNK_WRITE(V2) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(pinLampu,HIGH);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(pinLampu,LOW);  // Set digital pin 2 LOW    
  }
}

BLYNK_WRITE(V3) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(pinBuzz,HIGH);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(pinBuzz,LOW);  // Set digital pin 2 LOW    
  }
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V2);  // will cause BLYNK_WRITE(V0) to be executed
}

void loop()
{
  Blynk.run();
  timer.run();
}
