#ifndef Config_h
#define Config_h

/**
 * Secret need to define the following:
 * #define WIFI_SSID ****;
 * #define WIFI_PASSWORD ****;
 * */
#include "secret.h"

#define THING_UID ESP8266-PG-6fb4d7b6
const char* mqtt_server = "192.168.1.57";

#define RELAY1_PIN 15
#define RELAY2_PIN 13
#define RELAY3_PIN 12

#define SWITCH_RELAY1_PIN 4
#define SWITCH_RELAY2_PIN 5
#define SWITCH_RELAY3_PIN 3

#endif