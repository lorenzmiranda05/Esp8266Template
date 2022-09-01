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

**Tasks**
* [x] Add credentials folder in .gitignore
* [x] Connect to WiFi using ESP8266WiFi.h and credentials.h libraries
* [x] Create a basic OTA template
* [ ] Add TelnetStream to the OTA template
* [ ] Test TelnetStream using Putty
* [ ] Add WifiManager to the OTA template


<!-- Reusable and Invisible URL Definitions  -->
[Github]: https://github.com
[CP210X Driver]: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads
[CH340 Driver]: http://www.wch-ic.com/downloads/CH341SER_ZIP.html