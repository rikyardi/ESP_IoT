#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

#include "index.h"

const char* ssid = "ESP8266_AP";
const char* pass = "password";
ESP8266WebServer server(80);

void Home(){
  String page = FPSTR(Main_Page);
  server.send(200, "text/html", page);
}

void handleForm() {
  String inputValue = server.arg("inputField");
  // Lakukan sesuatu dengan nilai string yang diterima
  Serial.println("Nilai input: " + inputValue);
  server.send(200, "text/html", "Form berhasil dikirim!");
}

void setup() {
  Serial.begin(9600);
  WiFi.softAP(ssid, pass);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Access Point IP:");
  Serial.println(myIP);
  server.on("/form", HTTP_POST, handleForm);
  server.on("/", Home);
  server.begin();
}

void loop() {
  server.handleClient();
}
