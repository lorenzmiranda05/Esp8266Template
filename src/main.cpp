
#include <Secret.h>
#include <OTA.h>

void saveConfigCallback()
// Callback notifying us of the need to save configuration
{
  serialAndTelnetPrintln(F("Should save config"));
  shouldSaveConfig = true;
}

void setup()
{
  // Setup Serial monitor
  Serial.begin(921600);
  // Begin Telnet Stream
  TelnetStream.begin();
  delay(10);

  // Change to true when testing to force configuration every time we run
  bool forceConfig = false;

  bool littlefsSetup = loadConfigFile();
  if (!littlefsSetup)
  {
    serialAndTelnetPrintln(F("Forcing config mode as there is no saved config"));
    forceConfig = true;
  }

  // Explicitly set WiFi mode
  WiFi.mode(WIFI_STA);

  // WiFiManager Section
  // Suppress debug information
  // wm.setDebugOutput(false);

  // Reset settings (only for development)
  // wm.resetSettings();

  // Set config save notify callback
  wm.setSaveConfigCallback(saveConfigCallback);

  // Set callback that gets called when connecting to
  // previous WiFi fails, and enters Access Point mode
  wm.setAPCallback(configModeCallback);

  // Custom Elements
  // Text box (String) - 50 characters maximum
  WiFiManagerParameter textBox1("textBox1", "Label of Text Box 1", testString, 50);

  // Need to convert numerical input to string to display the default value.
  char convertedValue[6];
  sprintf(convertedValue, "%d", testNumber);

  // Text box (Number) - 7 characters maximum
  WiFiManagerParameter textBox2("textBox2", "Label of Text Box 2", convertedValue, 7);

  // Add all defined parameters
  wm.addParameter(&textBox1);
  wm.addParameter(&textBox2);

  if (forceConfig)
  // Run if we need a configuration
  {
    if (!wm.startConfigPortal(mcuHostName, wifiManagerPassword))
    {
      serialAndTelnetPrintln(F("Connect failed, hit timeout"));
      delay(3000);
      // reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }
  }
  else
  {
    if (!wm.autoConnect(mcuHostName, wifiManagerPassword))
    {
      serialAndTelnetPrintln(F("Connect failed, hit timeout"));
      delay(3000);
      // if we still have not connected restart and try all over again
      ESP.restart();
      delay(5000);
    }
  }

  // If we get here, we are connected to the WiFi
  serialAndTelnetPrintln(F(""));
  serialAndTelnetPrintln(F("WiFi connected"));

  // User config values
  // Copy the string value
  strncpy(testString, textBox1.getValue(), sizeof(testString));
  serialAndTelnetPrint(F("Test String: "));
  serialAndTelnetPrintln(testString);

  // Convert the number value
  testNumber = atoi(textBox2.getValue());
  serialAndTelnetPrint(F("Test Number: "));
  serialAndTelnetPrintln(testNumber);

  // Save the custom parameters to FS
  if (shouldSaveConfig)
  {
    saveConfigFile();
  }

  // Setup OTA
  setupOTA();
}

int loopCount = 0;

void loop()
{
  ArduinoOTA.handle();
  delay(5000);
}