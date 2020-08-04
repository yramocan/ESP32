#include <Arduino.h>

#include "Networking.hpp"
#include "WebService.hpp"

const long BAUD_RATE = 115200;
const char *ssid = "YOUR SSID";
const char *password = "YOUR WIFI PASSWORD";

WebService webService;

void setup() {
  Serial.begin(BAUD_RATE);
  Networking::connectToNetwork(ssid, password);
}

void loop() {
  if (Networking::wifiIsConnected()) {
    webService.sendDeviceData();
  } else {
    Serial.println("There is an issue with the WiFi connection.");
  }

  delay(5000);
}