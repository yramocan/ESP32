#include "WebService.hpp"

/* 
    struct WebService final {
        HTTPClient http;

        void createPost();
        void fetchData();
    };
*/

void WebService::createPost() {
    Serial.println("\n\n* * * * * * * * * * * * * * * * * * *\n");
    Serial.print("Creating post... ");

    http.begin("http://jsonplaceholder.typicode.com/posts");
    http.addHeader("Content-Type", "text/plain");

    int httpResponseCode = http.POST("POSTING from ESP32");
 
    if (httpResponseCode > 0) {
        String response = http.getString();
        Serial.println(httpResponseCode);
        Serial.println();
        Serial.println(response);
    } else {
        String response = http.getString();
        Serial.println(httpResponseCode);
        Serial.println();
        Serial.println("Error on sending POST: ");
        Serial.println(response);
    }
 
    http.end();

    Serial.println("\n* * * * * * * * * * * * * * * * * * *\n\n");
}

void WebService::fetchData() {
    Serial.println("\n\n* * * * * * * * * * * * * * * * * * *\n");
    Serial.println("Fetching data...\n");

    http.begin("http://jsonplaceholder.typicode.com/comments?id=10");

    int httpCode = http.GET();
 
    if (httpCode > 0) {
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
    } else {
        Serial.println("Error on HTTP request");
    }
 
    http.end();

    Serial.println("\n* * * * * * * * * * * * * * * * * * *\n\n");
}

void WebService::sendDeviceData() {
    Serial.println("\n\n* * * * * * * * * * * * * * * * * * *\n");
    Serial.print("Sending data... ");

    http.begin("http://192.168.200.218:3000/devices/69");
    http.addHeader("Content-Type", "text/plain");

    int httpResponseCode = http.POST("Hello from ESP32");

    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println();
 
    if (httpResponseCode < 0) {
        Serial.println("Error on sending POST: ");
    }

    Serial.println(response);
 
    http.end();

    Serial.println("\n* * * * * * * * * * * * * * * * * * *\n\n");
}