### **ESP8266 ESP-01(s) OTA Template**

---
<br  />

**Hardware**
1. Microcontroller Board
    <br  />
    <br  />
    ![github](https://raw.githubusercontent.com/lorenzmiranda05/EspOtaEsp01Template/main/Assets/Images/Esp01.jpg)

    | Microcontroller Board Details | | 
    | - | - | 
    | Development Board | ESP01_1M |
    | Radio-Frequency (RF) Module | ESP01S |
    | System-on-a-Chip (SoC) | ESP8266 |
    <br  />
1. Male USB A to Male USB Micro B Data Cable

<br  />

**USB to UART Bridge Driver Setup**
1. Check the Bridge used in the Microcontroller Development Board
    <br  />
    <br  />
    ![github](https://raw.githubusercontent.com/lorenzmiranda05/EspOtaEsp01Template/main/Assets/Images/USB%20to%20UART%20Bridge.jpg)  

1. Download the USB to UART Bridge Drivers:
    * For CP210X, download [here][CP210X Driver].
    * For CH340, download [here][CH340 Driver].
1. Install the USB to UART Driver

<br  />

**lib>Credentials>Crednetials.h**
1. The text file credentials.h looks like:
    ```c++
    #pragma once
    const char* mcuHostName = "MCU Host Name";
    const char* modSsid = "Modem SSID";
    const char* modPassword = "Modem Password";
    ```

<br  />

**Add Libraries using PlatformIO>Libraries tab**
1. Search TelnetStream by Juraj Andrassy
1. Add the exact version of the library to the project
    ```
    # RECOMMENDED
    # Accept new functionality in a backwards compatible manner and patches
    jandrassy/TelnetStream @ ^1.2.2

    # Accept only backwards compatible bug fixes
    # (any version with the same major and minor versions, and an equal or greater patch version)
    jandrassy/TelnetStream @ ~1.2.2

    # The exact version
    jandrassy/TelnetStream @ 1.2.2
    ```
1. Library dependencie(s) will be added in the platformio.ini file
    ```
    [env:esp01_1m]
    platform = espressif8266
    board = esp01_1m
    framework = arduino
    monitor_speed = 921600
    upload_protocol = espota
    upload_port = 192.168.1.10
    lib_deps = jandrassy/TelnetStream@1.2.2
    ```

<br  />

**Dependency Graph**

|-- TelnetStream @ 1.2.2
<br  />
|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|-- Ethernet @ 2.0.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- SPI @ 1.0
<br  />
|-- Credentials
<br  />
|-- OTA
<br  />
|&nbsp; &nbsp; &nbsp;|-- ArduinoOTA @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266mDNS @ 1.2
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|-- ESP8266mDNS @ 1.2
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0

<br  />

**Tasks**
* [x] Add credentials folder in .gitignore
* [x] Connect to WiFi using ESP8266WiFi.h and credentials.h libraries
* [x] Create a basic OTA template
* [x] Add TelnetStream to the OTA template
* [x] Test TelnetStream using Putty or cmd
* [ ] Add WifiManager to the OTA template


<!-- Reusable and Invisible URL Definitions  -->
[Github]: https://github.com
[CP210X Driver]: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads
[CH340 Driver]: http://www.wch-ic.com/downloads/CH341SER_ZIP.html