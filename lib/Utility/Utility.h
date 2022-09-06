#include <Arduino.h>
#include <TelnetStream.h>
#include <WiFiManager.h>
#include <FS.h>
#include <LittleFS.h>
#include <ArduinoJson.h>

#define JsonConfigFile "/config.json"
bool shouldSaveConfig = false;
char testString[50] = "Use these for API Key (String) or PIN (number)";
int testNumber = 12345;
WiFiManager wm;

void serialAndTelnetPrint(__FlashStringHelper *message)
{
    Serial.print(message);
    TelnetStream.print(message);
}
void serialAndTelnetPrint(const char *message)
{
    Serial.print(message);
    TelnetStream.print(message);
}
void serialAndTelnetPrint(int message)
{
    Serial.print(message);
    TelnetStream.print(message);
}
void serialAndTelnetPrint(IPAddress message)
{
    Serial.print(message);
    TelnetStream.print(message);
}
void serialAndTelnetPrint(String message)
{
    Serial.print(message);
    TelnetStream.print(message);
}

void serialAndTelnetPrintln(__FlashStringHelper *message)
{
    Serial.print(message);
    TelnetStream.print(message);
}
void serialAndTelnetPrintln(const char *message)
{
    Serial.println(message);
    TelnetStream.println(message);
}
void serialAndTelnetPrintln(int message)
{
    Serial.println(message);
    TelnetStream.println(message);
}
void serialAndTelnetPrintln(IPAddress message)
{
    Serial.println(message);
    TelnetStream.println(message);
}
void serialAndTelnetPrintln(String message)
{
    Serial.println(message);
    TelnetStream.println(message);
}

void saveConfigFile()
// Save configuration in JSON format
{
    serialAndTelnetPrintln(F("SaveConfigFile"));

    // Create a JSON document
    StaticJsonDocument<512> json;
    json["testString"] = testString;
    json["testNumber"] = testNumber;

    // Open config file
    File configFile = LittleFS.open(JsonConfigFile, "w");
    if (!configFile)
    {
        // Error, file did not open
        serialAndTelnetPrintln(F("Open config failed"));
    }

    // Serialize JSON data to write to file
    serializeJsonPretty(json, Serial);
    serializeJsonPretty(json, TelnetStream);
    if (serializeJson(json, configFile) == 0)
    {
        // Error writing file
        serialAndTelnetPrintln(F("Overwrite config failed"));
    }
    // Close file
    configFile.close();
    serialAndTelnetPrintln(F(""));
    serialAndTelnetPrintln(F("Config saved"));
}

bool loadConfigFile()
// Load existing configuration file
{
    // Uncomment if we need to format filesystem
    // LittleFS.format();

    // Read configuration from FS json
    serialAndTelnetPrintln(F("Mounting FS"));

    // May need to make it begin(true) first time you are using SPIFFS
    if (LittleFS.begin())
    {
        // The file exists, reading and loading
        serialAndTelnetPrintln(F("Reading config"));
        File configFile = LittleFS.open(JsonConfigFile, "r");
        if (configFile)
        {
            serialAndTelnetPrintln(F("Opened config"));
            StaticJsonDocument<512> json;
            DeserializationError error = deserializeJson(json, configFile);
            serializeJsonPretty(json, Serial);
            serializeJsonPretty(json, TelnetStream);
            if (!error)
            {
                serialAndTelnetPrintln(F(""));
                serialAndTelnetPrintln(F("Parsing"));
                strcpy(testString, json["testString"]);
                testNumber = json["testNumber"].as<int>();

                return true;
            }
            else
            {
                // Error loading JSON data
                serialAndTelnetPrintln(F("Load config failed"));
            }
        }
    }
    else
    {
        // Error mounting file system
        serialAndTelnetPrintln(F("Mount FS failed"));
    }
    return false;
}

void configModeCallback(WiFiManager *myWiFiManager)
// Called when config mode launched
{
    serialAndTelnetPrintln(F("Config Mode"));
    serialAndTelnetPrint(F("Config SSID: "));
    serialAndTelnetPrintln(myWiFiManager->getConfigPortalSSID());

    serialAndTelnetPrint(F("Config IPAdd: "));
    serialAndTelnetPrintln(WiFi.softAPIP());
}