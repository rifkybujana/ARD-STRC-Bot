#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define UNABLE_GET_DATA "Can't Get Data"
#define UNABLE_POST_DATA "Can't Post Data"

class Connection {
  public:
    Connection();

    String Get();
    String Post(String data, String key, String target);

  private:
    const char* ssid = "APIN IPAN";
    const char* pass = "5ul43m4n";
    
    String url = "http://192.168.1.5:5000/";

    ESP8266WiFiMulti WiFiMulti;
};

#endif
