# Toto|Play

## Description

A cat entertainment system.

## Hardware

### Parts

#### Microcontroller

[WEMOS D1 mini](https://www.aliexpress.com/item/D1-mini-Mini-NodeMcu-4M-bytes-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266/32529101036.html?spm=2114.13010608.0.0.HZtg9v)

#### Actuator

Servo Motor:

[SG90](http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf)

### Setup

#### Wiring

- `5V <> 5V @ WEMOS D1`
- `5V <> Vcc @ SG90 (Red)`

- `GND <> G @ WEMOS D1`
- `GND <> Ground @ SG90 (Brown)`

- `D0 @ WEMOS D1 <> PWM @ SG90 (Orange)`

## Firmware

### Setup

#### Driver

On macOS High Sierra: https://blog.sengotta.net/signed-mac-os-driver-for-winchiphead-ch340-serial-bridge/

#### Configuration

Create a `./files/settings.json` configuration file with the following content:

```json
{
    "network":
    {
        "ssid": "WIFI_SSID",
        "password": "WIFI_PASSWORD"
    }
}
```

Update `Makefile-user.mk` with the correct `COM_PORT`.

#### Build

```bash
./tools/build.sh
```

#### Flash

```bash
./tools/flash.sh
```

## Copyright

(c) 2016 - 2018 Lucas Brémond

Citing Peter Andersson, author of the great [SPIFFS](https://github.com/pellepl/spiffs) library:

*For legal stuff, see LICENSE.*     
*Basically, you may do whatever you want with the source.*      
*Use, modify, sell, print it out, roll it and smoke it - as long as I won't be held responsible.*   
