#ifndef Config_h
#define Config_h

#ifdef BUILD_CI
#include "secret.default.h"
#else
#include "secret.h"
#endif

#define THING_UID "PG-6fb4d7b6"
#define RELAY1_TOPIC THING_UID "/relay1"
#define RELAY2_TOPIC THING_UID "/relay2"
#define RELAY3_TOPIC THING_UID "/relay3"

const char* mqtt_server = "192.168.1.57";

#define RELAY1_PIN 15
#define RELAY2_PIN 13
#define RELAY3_PIN 12

#define SWITCH_RELAY1_PIN 4
#define SWITCH_RELAY2_PIN 5
#define SWITCH_RELAY3_PIN 3

#endif