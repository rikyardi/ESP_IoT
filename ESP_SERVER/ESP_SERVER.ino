#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>

const char* ssid = "Amran";
const char* pass = "rumahamran";

const int pinLED = LED_BUILTIN;

ESP8266WebServer server(80);

void HomePage(){
  server.send(200, "text/plain", "Hello World~");
}
void About(){
  server.send(200, "text/plain", "Ini Halaman About!");
}
void LedOn(){
  digitalWrite(pinLED, LOW);
  server.send(200, "text/plain", "LED ON");
} 
void LedOff(){
  digitalWrite(pinLED, HIGH);
  server.send(200, "text/plain", "LED Off");
} 
void setup() {
  pinMode(pinLED, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.println("");

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  server.on("/", HomePage);
  server.on("/about", About);
  server.on("/on", LedOn);
  server.on("/off", LedOff);
  server.begin();
}

void loop() {
  server.handleClient();
}
