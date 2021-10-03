
#include <ESP8266WiFi.h>
#include <Arduino.h>

#ifndef Wifi_h
#define Wifi_h

#define AP_SSID_DEFAULT "ESP8266_SSID_Default_Name"
#define AP_PASS_DEFAULT ""
#define AP_CHANNEL_DEFAULT 1
#define AP_MAX_CONNECTION_DEFAULT 1
#define AP_LOCAL_IP_DEFAULT {192,168,1,1}
#define AP_GATEWAY_DEFAULT {192,168,1,1}
#define AP_SUBNET_DEFAULT {255,255,255,0}

class Wifi: public ESP8266WiFiClass {
    public:
        typedef struct {
            char ssid[32];
            char pass[64];
            uint8_t channel;
            uint8_t max_connection;
            uint8_t local_ip[4];
            uint8_t gateway[4];
            uint8_t subnet[4];
        } APConf;

        typedef struct {
            char ssid[32];
            char pass[64];
        } STAConf;

        Wifi();

        uint8_t APRun(APConf ap_conf);
        uint8_t APStop();

        uint8_t STARun(STAConf sta_conf);
        uint8_t STAStop();
        bool STAisConnected();

        // uint8_t StationNumGet();
        // uint8_t* CurrentIpGet();
        // uint8_t* MacAddressGet();
        
        // char* SsidDefaultGet();
        // char* PassDefaultGet();
        // uint8_t ChannelDefaultGet();
        // uint8_t MaxConnectionDefaultGet();

        // char* SsidGet();
        // char* PassGet();
        // uint8_t ChannelGet();
        // uint8_t MaxConnectionGet();
        // Network NetworkGet();

    private:
        uint8_t _setMode();
        bool _sta_enable;
        bool _ap_enable;

        APConf _ap_conf;
        STAConf _sta_conf;
        
    // TODO When required. Implement Station Mode configuration: 
    // The ESP can operate in both soft-AP and Station mode so it can act as a node of a mesh network.

    // TODO Register multiple Wifi Networks and connect to strongest signal
    // https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html#wifi-multi
    
};

#endif