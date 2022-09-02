#include <Arduino.h>
#include <Credentials.h>
#include <OTA.h>
#include <TelnetStream.h>

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("Booting");

  setupOTA(mcuHostName, modSsid, modPassword);
  TelnetStream.begin();
}

int loopCount = 0;

void loop()
{
  ArduinoOTA.handle();
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Blink
  TelnetStream.println("ESPOTA READY");
  TelnetStream.print("IP address: ");
  TelnetStream.println(WiFi.localIP());
  TelnetStream.println("WiFi MAC Address: ");
  TelnetStream.println(WiFi.macAddress());
  loopCount = loopCount + 1;
  TelnetStream.print("Loop Count: ");
  TelnetStream.println(loopCount);
  delay(5000);
}