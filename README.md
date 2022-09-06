### **ESP8266 Template**

---
<br  />

**Hardware**
1. ESP-01
    <br  />
    <br  />
    ![github](https://raw.githubusercontent.com/lorenzmiranda05/EspOtaWiFiManagerTemplate/main/Assets/Images/Esp01.jpg)

    | Microcontroller Board Details | | 
    | - | - | 
    | Development Board | esp01_1m |
    | Radio-Frequency (RF) Module | ESP-01S |
    | System-on-a-Chip (SoC) | ESP8266 |
    <br  />
1. ESP-12F
    <br  />
    <br  />
    ![github](https://raw.githubusercontent.com/lorenzmiranda05/EspOtaWiFiManagerTemplate/main/Assets/Images/ESP8266%20ESP-12E%20MCU.png)

    | Microcontroller Board Details | | 
    | - | - | 
    | Development Board | nodemcuv2 |
    | Radio-Frequency (RF) Module | ESP-12F |
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

**lib>Secret>Secret.h**
1. The text file Secret.h looks like:
    ```c++
    #pragma once
    const char *mcuHostName = "Board-Mac[3]Mac[4]Mac[5]";
    // Sample: ESP01-A5B7C1
    const char *wifiManagerPassword = "Password";
    ```

<br  />

**Add Libraries using PlatformIO>Libraries tab**
1. Add the following libraries to the project:
    * TelnetStream by Juraj Andrassy
    * WiFiManager by tzapu
    * ArduinoJson by Benoit Blanchon
1. Library dependencie(s) will be added to the platformio.ini file:
    ```
    [env:esp01_1m]
    platform = espressif8266
    board = esp01_1m
    ; [env:nodemcuv2]
    ; platform = espressif8266
    ; board = nodemcuv2
    framework = arduino
    monitor_speed = 921600
    ; upload_protocol = espota
    ; upload_port = 192.168.1.8 ; ESP-12F
    ; upload_port = 192.168.1.9 ; ESP-01
    lib_deps = 
        jandrassy/TelnetStream@1.2.2
        tzapu/WiFiManager@0.16.0
        bblanchon/ArduinoJson@6.19.4
    ```

<br  />

**File System Image Setup**
1. Add this line in the platformio.ini file
    ```
    board_build.filesystem = littlefs
    ```
    platformio.ini file:
    ```
    [env:esp01_1m]
    platform = espressif8266
    board = esp01_1m
    ; [env:nodemcuv2]
    ; platform = espressif8266
    ; board = nodemcuv2
    framework = arduino
    monitor_speed = 921600
    ; upload_protocol = espota
    ; upload_port = 192.168.1.8 ; ESP-12F
    ; upload_port = 192.168.1.9 ; ESP-01
    lib_deps = 
        jandrassy/TelnetStream@1.2.2
        tzapu/WiFiManager@0.16.0
        bblanchon/ArduinoJson@6.19.4
    board_build.filesystem = littlefs
    ```
1. Create a folder called data inside the project folder
1. Create a new file called config.json inside the data folder
1. Click the PIO icon at the left side bar
1. Under PROJECT TASKS, go to [Environment]>Platform folder
1. Click Build Filesystem Image
1. Click Upload Filesystem Image

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
|-- WiFiManager @ 0.16.0
<br  />
|&nbsp; &nbsp; &nbsp;|-- DNSServer @ 1.1.1
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|-- ESP8266WebServer @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|-- ArduinoJson @ 6.19.4
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
|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|-- Utility
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ArduinoJson @ 6.19.4
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- LittleFS @ 0.1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- TelnetStream @ 1.2.2
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- Ethernet @ 2.0.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- SPI @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- WiFiManager @ 0.16.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- DNSServer @ 1.1.1
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WebServer @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|&nbsp; &nbsp; &nbsp;|-- ESP8266WiFi @ 1.0
<br  />
|-- Secret
<br  />



<br  />


**Tasks**
* [x] Add credentials folder in .gitignore
* [x] Connect to WiFi using ESP8266WiFi.h and credentials.h libraries
* [x] Create a basic OTA template
* [x] Add TelnetStream to the OTA template
* [x] Test TelnetStream using Putty or cmd telnet
* [x] Add WifiManager to the OTA template
* [x] Use Little FS instead of SPIFFS

**References**
* [OTA Tutorial 1][OTA TelnetStream Tutorial]
* [OTA Tutorial 2][OTA Tutorial]
* [WiFi Manager Tutorial][WiFi Manager Tutorial]
    * Uses depricated SPIFFS
    * Used LITTLE FS instead
        * [Little FS Tutorial][Little FS Tutorial]

**Notes**
* The OTA Upload does not work with the an ESP-01 build that contains OTA, TelnetStream, WiFiManager and Little FS libraries due to Flash Storage Capacity
* Possible alternative ESP-01 Template **(to be developed)**:
    * Create a build without WiFiManager library
    * Changes to WiFi connectivity will be handled by WiFiMulti and Little FS libraries
    * WiFiMulti SSID and password pairs will be stored in a .json file that will be stored in the file system
    * Updates in the SSID and password will be done using Upload Filesystem Image OTA

<!-- Reusable and Invisible URL Definitions  -->
[Github]: https://github.com
[CP210X Driver]: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads
[CH340 Driver]: http://www.wch-ic.com/downloads/CH341SER_ZIP.html
[Little FS Tutorial]: https://randomnerdtutorials.com/esp8266-nodemcu-vs-code-platformio-littlefs/
[WiFi Manager Tutorial]: https://www.youtube.com/watch?v=VnfX9YJbaU8
[OTA Tutorial]: https://www.youtube.com/watch?v=lXchL3hpDO4
[OTA TelnetStream Tutorial]: https://www.youtube.com/watch?v=1pwqS_NUG7Q