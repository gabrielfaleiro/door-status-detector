
#include <ESP8266WiFi.h>
#include <Arduino.h>

#ifndef Wifi_h
#define Wifi_h

#define I_SSID_DEFAULT "ESP8266_SSID_Default_Name"
#define I_PASS_DEFAULT ""
#define I_CHANNEL_DEFAULT 1
#define I_MAX_CONNECTION_DEFAULT 1
#define I_LOCAL_IP_DEFAULT {192,168,1,1}
#define I_GATEWAY_DEFAULT {192,168,1,1}
#define I_SUBNET_DEFAULT {255,255,255,0}

class Wifi: public ESP8266WiFiClass {
    public:
        typedef struct {
            char ssid[32];
            char pass[64];
            uint8_t channel;
            uint8_t max_connection;
        } WifiConf;
        typedef struct {
            uint8_t local_ip[4];
            uint8_t gateway[4];
            uint8_t subnet[4];
        } Network;

        Wifi(   bool ap_en, Wifi::WifiConf ap_wifi_conf, Wifi::Network ap_network,
                bool sta_en, Wifi::WifiConf sta_wifi_conf, Wifi::Network sta_network);
        Wifi();

        void WifiAPConfig(Network network);
        void WifiAPSetup(WifiConf wifi_conf);
        void WifiAPRun(WifiConf wifi_conf, Network network);
        void WifiAPRun();

        
        void WifiSTAConfig(Network network);
        void WifiSTASetup(WifiConf wifi_conf);
        void WifiSTARun(WifiConf wifi_conf, Network network);
        void WifiSTARun();
        bool WifiSTAConnected();

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
        // char i_ssid_default[32] = I_SSID_DEFAULT;
        // char i_pass_default[64] = I_PASS_DEFAULT;
        // uint8_t i_channel_default = I_CHANNEL_DEFAULT;
        // uint8_t i_max_connection_default = I_MAX_CONNECTION_DEFAULT;

        // char i_ssid[32] = I_SSID_DEFAULT;
        // char i_pass[64] = I_PASS_DEFAULT;
        // uint8_t i_channel = I_CHANNEL_DEFAULT;
        // uint8_t i_max_connection = I_MAX_CONNECTION_DEFAULT;

        // network i_network = {
        //     I_LOCAL_IP_DEFAULT,
        //     I_GATEWAY_DEFAULT,
        //     I_SUBNET_DEFAULT
        // }

        // void SsidSet(char ssid[32]);
        // void PassSet(char pass[64]);
        // void ChannelSet(uint8_t channel);
        // void MaxConnectionSet(uint8_t max_connection);

        // void NetworkSet(Network net);

    // TODO When required. Implement Station Mode configuration: 
    // The ESP can operate in both soft-AP and Station mode so it can act as a node of a mesh network.

    // TODO Register multiple Wifi Networks and connect to strongest signal
    // https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html#wifi-multi
    
};

#endif