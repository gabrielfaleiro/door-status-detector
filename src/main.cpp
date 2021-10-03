#include <Arduino.h>
#include "Wifi.h"

Wifi wifi = Wifi();

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Wifi::WifiConf wifi_ap_conf = {
    "my_ap_name",
    "",
    I_CHANNEL_DEFAULT,
    I_MAX_CONNECTION_DEFAULT
  };

  Wifi::Network wifi_ap_net = {
    {192,168,6,1},
    {192,168,6,1},
    {255,255,255,0}
  };

  wifi.WifiAPRun(wifi_ap_conf, wifi_ap_net);

}

// ============== Main loop ====================================================
void loop() {
  
}