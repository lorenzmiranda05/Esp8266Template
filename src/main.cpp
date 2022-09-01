#include <Arduino.h>
#include <credentials.h>
#include <OTA.h>

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("Booting");

  setupOTA(mcuHostName, modSsid, modPassword);
}

int loopCount = 0;

void loop()
{
  ArduinoOTA.handle();
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Blink
  Serial.println("ESPOTA REEDY");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("WiFi MAC Address: ");
  Serial.println(WiFi.macAddress());
  loopCount = loopCount + 1;
  Serial.print("Loop Count: ");
  Serial.println(loopCount);
  delay(5000);
}