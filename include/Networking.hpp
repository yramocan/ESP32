#include <Arduino.h>
#include <WiFi.h>

struct Networking {
    struct WifiInfo {
        String networkName;
        int32_t signalStrength;
        String macAddress;
        String encryptionType;

        WifiInfo(String networkName_, int32_t signalStrength_, String macAddress_, String encryptionType_);
    };

    static void connectToNetwork(const char *ssid, const char *password);
    static void printWifiInfo(WifiInfo wifiInfo);
    static void scanNetworks();
    static String translateEncryptionType(wifi_auth_mode_t encryptionType);
    static bool wifiIsConnected();
};