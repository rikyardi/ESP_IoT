#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

const char* ssid = "ESP8266-AP";
const char* pass = "password";

const int pinLed = LED_BUILTIN;

ESP8266WebServer server(80);

void Home(){
  server.send(200, "text/plain", "Halaman HOME");
}

void LedOn(){
  digitalWrite(pinLed, LOW);
  server.send(200, "text/plain", "LED On");
}
void LedOff(){
  digitalWrite(pinLed, HIGH);
  server.send(200, "text/plain", "LED Off");
}
void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  WiFi.softAP(ssid, pass);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Access Point IP:");
  Serial.println(myIP);

  server.begin();
  server.on("/", Home);
  server.on("/on", LedOn);
  server.on("/off", LedOff);
}

void loop() {
  server.handleClient();
}
