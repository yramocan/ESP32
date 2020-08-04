#include "Networking.hpp"

typedef struct Networking::WifiInfo WifiInfo;

WifiInfo::WifiInfo(String networkName_, int32_t signalStrength_, String macAddress_, String encryptionType_) {
    networkName = networkName_;
    signalStrength = signalStrength_;
    macAddress = macAddress_;
    encryptionType = encryptionType_;
}

void Networking::connectToNetwork(const char *ssid, const char *password) {
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Establishing connection to WiFi..");
    }

    Serial.println("Connected to network");
}

void Networking::printWifiInfo(WifiInfo wifiInfo) {
    Serial.print("Network name: ");
    Serial.println(wifiInfo.networkName);

    Serial.print("Signal strength: ");
    Serial.println(wifiInfo.signalStrength);

    Serial.print("MAC address: ");
    Serial.println(wifiInfo.macAddress);

    Serial.print("Encryption type: ");
    Serial.println(wifiInfo.encryptionType);

    Serial.println("-----------------------");
}

void Networking::scanNetworks() {
    int numberOfNetworks = WiFi.scanNetworks();

    Serial.print("Number of networks found: ");
    Serial.println(numberOfNetworks);

    for (int i = 0; i < numberOfNetworks; i++) {
        WifiInfo wifiInfo(
            WiFi.SSID(i), 
            WiFi.RSSI(i), 
            WiFi.BSSIDstr(i), 
            translateEncryptionType(WiFi.encryptionType(i))
        );
        
        printWifiInfo(wifiInfo);
    }
}

String Networking::translateEncryptionType(wifi_auth_mode_t encryptionType) {
    switch (encryptionType) {
    case (WIFI_AUTH_OPEN):
        return "Open";
    case (WIFI_AUTH_WEP):
        return "WEP";
    case (WIFI_AUTH_WPA_PSK):
        return "WPA_PSK";
    case (WIFI_AUTH_WPA2_PSK):
        return "WPA2_PSK";
    case (WIFI_AUTH_WPA_WPA2_PSK):
        return "WPA_WPA2_PSK";
    case (WIFI_AUTH_WPA2_ENTERPRISE):
        return "WPA2_ENTERPRISE";
    case (WIFI_AUTH_MAX):
        return "Maximum";
    default:
        return "Unknown";
    }
}

bool Networking::wifiIsConnected() {
    return WiFi.status() == WL_CONNECTED;
}