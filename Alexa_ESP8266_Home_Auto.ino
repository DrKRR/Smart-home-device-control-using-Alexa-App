#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"
#include <map>

// Enter your WiFi Credentials here

#define WIFI_SSID         "Enter your WiFi SSID here" 
#define WIFI_PASS         "Enter your WiFi Password here"

//Enter your Sinric Pro Credentials here

#define APP_KEY           "Enter your Sinric Pro APP_KEY  here" 
#define APP_SECRET        "Enter your APP_SECRET_CODE  here"

//Enter your device_IDs here

#define device_ID_1   "Enter your device_ID1_1 here"
#define device_ID_2   "Enter your device_ID1_2 here"
#define device_ID_3   "Enter your device_ID1_3 here"

//Assign DIO Pins to cathodes of LEDs

#define LED_Pin1 14   //D5
#define LED_Pin2 13   //D7
#define LED_Pin3 16   //D0 

//Assign DIO Pins to DIP Switches

#define SwitchPin1 5   //D1
#define SwitchPin2 4   //D2 
#define SwitchPin3 12  //D6

//Assign Built-in LED as WiFi indicator

#define wifiLed LED_BUILTIN   //D4

#define BAUD_RATE 9600     //select the std.baud rate
#define DEBOUNCE_TIME 250  //Debouncing time of 250ms for DIP switches

typedef struct {      // struct for the std::map below
  int ledPIN;//LED
  int flipSwitchPIN;
} deviceConfig_t;


std::map<String, deviceConfig_t> devices = {
  //{deviceId,    {LED_PIN,  flipSwitchPIN}}//LED
    {device_ID_1, {  LED_Pin1, SwitchPin1 }},
    {device_ID_2, {  LED_Pin2, SwitchPin2 }},
    {device_ID_3, {  LED_Pin3, SwitchPin3 }}     
};

typedef struct {      // struct for the std::map below
  String deviceId;
  bool lastFlipSwitchState;
  unsigned long lastFlipSwitchChange;
} flipSwitchConfig_t;

std::map<int, flipSwitchConfig_t> flipSwitches;    // this map is used to map flipSwitch PINs to deviceId and handling debounce and last flipSwitch state checks
                                                  // it will be setup in "setupFlipSwitches" function, using informations from devices map

void setupLEDs(){                      
  for (auto &device : devices){                //for each device (led,flipswitch combination)
    int ledPIN = device.second.ledPIN;         //get the led pin
    pinMode(ledPIN, OUTPUT);                   //set led pin output
    digitalWrite(ledPIN, LOW);                 //changed from HIGH to LOW
    }
  }

 void setupFlipSwitches(){
   for (auto &device : devices) {    //for each device(LED,flipSwitch combination)
    flipSwitchConfig_t flipSwitchConfig;              // create a new flipSwitch configuration

    flipSwitchConfig.deviceId = device.first;         // set the deviceId
    flipSwitchConfig.lastFlipSwitchChange = 0;        // set debounce time
    flipSwitchConfig.lastFlipSwitchState = true;     // set lastFlipSwitchState to false (LOW)--

    int flipSwitchPIN = device.second.flipSwitchPIN;  // get the flipSwitchPIN

    flipSwitches[flipSwitchPIN] = flipSwitchConfig;   // save the flipSwitch config to flipSwitches map
    pinMode(flipSwitchPIN, INPUT_PULLUP);                   // set the flipSwitch pin to INPUT
      }
     
   }

bool onPowerState(String deviceId, bool &state)
{
  Serial.printf("%s: %s\r\n", deviceId.c_str(), state ? "on" : "off");
  int ledPIN = devices[deviceId].ledPIN; // get the relay pin for corresponding device
  digitalWrite(ledPIN, !state);             // set the new relay state
  return true;
}

void handleFlipSwitches() {
  unsigned long actualMillis = millis();                                          // get actual millis
  for (auto &flipSwitch : flipSwitches) {                                         // for each flipSwitch in flipSwitches map
    unsigned long lastFlipSwitchChange = flipSwitch.second.lastFlipSwitchChange;  // get the timestamp when flipSwitch was pressed last time (used to debounce / limit events)

    if (actualMillis - lastFlipSwitchChange > DEBOUNCE_TIME) {                    // if time is > debounce time...

      int flipSwitchPIN = flipSwitch.first;                                       // get the flipSwitch pin from configuration
      bool lastFlipSwitchState = flipSwitch.second.lastFlipSwitchState;           // get the lastFlipSwitchState
      bool flipSwitchState = digitalRead(flipSwitchPIN);                          // read the current flipSwitch state
      if (flipSwitchState != lastFlipSwitchState) {                               // if the flipSwitchState has changed...
#ifdef TACTILE_BUTTON
        if (flipSwitchState) {                                                    // if the tactile button is pressed 
#endif      
          flipSwitch.second.lastFlipSwitchChange = actualMillis;                  // update lastFlipSwitchChange time
          String deviceId = flipSwitch.second.deviceId;                           // get the deviceId from config
          int ledPIN = devices[deviceId].ledPIN;                              // get the relayPIN from config
          bool newLedState = !digitalRead(ledPIN);                            // set the new relay State
          digitalWrite(ledPIN, newLedState);                                  // set the trelay to the new state

          SinricProSwitch &mySwitch = SinricPro[deviceId];                        // get Switch device from SinricPro
          mySwitch.sendPowerStateEvent(!newLedState);                            // send the event
#ifdef TACTILE_BUTTON
        }
#endif      
        flipSwitch.second.lastFlipSwitchState = flipSwitchState;                  // update lastFlipSwitchState
      }
    }
  }
}

void setupWiFi()
{
  Serial.printf("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.printf(".");
    delay(250);
  }
  digitalWrite(wifiLed, LOW);
  Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
}

void setupSinricPro()
{
  for (auto &device : devices)
  {
    const char *deviceId = device.first.c_str();
    SinricProSwitch &mySwitch = SinricPro[deviceId];
    mySwitch.onPowerState(onPowerState);
  }

  SinricPro.begin(APP_KEY, APP_SECRET);
  SinricPro.restoreDeviceStates(true);
}

void setup()
{
  Serial.begin(BAUD_RATE);

  pinMode(wifiLed, OUTPUT);
  digitalWrite(wifiLed, HIGH);

  setupLEDs();
  setupFlipSwitches();
  setupWiFi();
  setupSinricPro();
}

void loop()
{
  SinricPro.handle();
  handleFlipSwitches();
}

                                                  
