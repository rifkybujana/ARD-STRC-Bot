#include "Connection.h"
#include <Arduino.h>

Connection::Connection(){
  Serial.begin(115200);

  for(uint8_t t = 4; t > 0; t--){
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, pass);
}

String Connection::Get(){
  if (WiFiMulti.run() == WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;

    Serial.print("[HTTP] begin...\n");

    if (http.begin(client, url + "Get")) {
      Serial.print("[HTTP] GET...\n");
      int httpCode = http.GET();

      if (httpCode > 0){
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
          String payload = http.getString();
          return payload;
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP] Unable to connect\n");
    }
  }

  return UNABLE_GET_DATA;
}

String Connection::Post(String data, String key, String target){
  if (WiFiMulti.run() == WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;

    Serial.print("[HTTP] begin...\n");

    if (http.begin(client, url + target)) {
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      
      Serial.print("[HTTP] POST...\n");
      int httpCode = http.POST(key + "=" + data);

      if (httpCode > 0){
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);

        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
          String payload = http.getString();
          return payload;
        }
      } else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP] Unable to connect\n");
    }
  }
  
  return UNABLE_POST_DATA;
}
