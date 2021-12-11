#include "Wifi.h"

Wifi::Wifi(){
    _sta_enable = false;
    _ap_enable = false;
}

void Wifi::WifiAPRun(){
    APConf def_wifi_conf = {
        I_SSID_DEFAULT,
        I_PASS_DEFAULT,
        I_CHANNEL_DEFAULT,
        I_MAX_CONNECTION_DEFAULT
        I_LOCAL_IP_DEFAULT,
        I_GATEWAY_DEFAULT,
        I_SUBNET_DEFAULT
    };

    WifiAPRun(def_wifi_conf, def_network);
}

void Wifi::WifiAPRun(Wifi::WifiConf wifi_conf, Wifi::Network network){
    WifiAPConfig(network);
    WifiAPSetup(wifi_conf);
}

void Wifi::WifiAPConfig(Wifi::Network network){

    // NetworkSet(network)
    IPAddress aux_local_ip( network.local_ip[0],
                            network.local_ip[1],
                            network.local_ip[2],
                            network.local_ip[3]);
    IPAddress aux_gateway(  network.gateway[0],
                            network.gateway[1],
                            network.gateway[2],
                            network.gateway[3]);
    IPAddress aux_subnet(   network.subnet[0],
                            network.subnet[1],
                            network.subnet[2],
                            network.subnet[3]);

    softAPConfig(aux_local_ip, aux_gateway, aux_subnet);
}

void Wifi::WifiAPSetup(Wifi::WifiConf wifi_conf){

    // Do not hide SSID
    uint8_t aux_hidden = 0x00;

    softAP(wifi_conf.ssid, wifi_conf.pass, wifi_conf.channel, aux_hidden, wifi_conf.max_connection);
}

void Wifi::WifiSTARun(Wifi::WifiConf wifi_conf, Wifi::Network network){
    WifiAPConfig(network);
    WifiAPSetup(wifi_conf);
}

void Wifi::WifiSTAConfig(Wifi::Network network){
    // TODO
    // NetworkSet(network)
    IPAddress aux_local_ip( network.local_ip[0],
                            network.local_ip[1],
                            network.local_ip[2],
                            network.local_ip[3]);
    IPAddress aux_gateway(  network.gateway[0],
                            network.gateway[1],
                            network.gateway[2],
                            network.gateway[3]);
    IPAddress aux_subnet(   network.subnet[0],
                            network.subnet[1],
                            network.subnet[2],
                            network.subnet[3]);

    softAPConfig(aux_local_ip, aux_gateway, aux_subnet);
}

void Wifi::WifiSTASetup(Wifi::WifiConf wifi_conf){
    // TODO
    // WifiConfSet(wifi_conf);
    
    // Do not hide SSID
    uint8_t aux_hidden = 0x00;

    softAP(wifi_conf.ssid, wifi_conf.pass, wifi_conf.channel, aux_hidden, wifi_conf.max_connection);
}
