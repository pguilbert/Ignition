A smart power strip that use an RTC module or MQTT messages to switch power outlets.

![Image of the first prototype: three relays with three switch on a breadboard.](docs/images/proto1.jpg?raw=true "Prototype")

This project can be integrated with home-assistant with the following configuration:
```yaml
switch:
  - platform: mqtt
    name: Relay 1
    state_topic: "PG-6fb4d7b6/relay1"
    command_topic: "PG-6fb4d7b6/relay1/set"
    retain: true
  - platform: mqtt
    name: Relay 2
    state_topic: "PG-6fb4d7b6/relay2"
    command_topic: "PG-6fb4d7b6/relay2/set"
    retain: true
  - platform: mqtt
    name: Relay 3
    state_topic: "PG-6fb4d7b6/relay3"
    command_topic: "PG-6fb4d7b6/relay3/set"
    retain: true
```

Result:

![Home-assistant user interface.](docs/images/haui.PNG?raw=true "Home-assistant user interface")