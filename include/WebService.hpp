#include <Arduino.h>
#include <HTTPClient.h>

struct WebService final {
    HTTPClient http;

    void createPost();
    void fetchData();
    void sendDeviceData();
};