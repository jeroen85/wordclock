//woordklok door Jeroen Jansen (Mei 2021)
//Wemos D1 Mini 1.0
//DATA_PIN D4
//Versie 2.1 (Verbeterde webinterface + async webserver + matrixfuncties verwijderd)


#include <FS.h>

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <FastLED.h>
#include <ezTime.h>
#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>

#include "webpagina.h"
#include "defines.h"

AsyncWebServer server(80);

String modus;
String c_rotate;
String showslider; 
String AB;
int Restart = 0;
String PerformEvent = "";

//LED-strip settings
#define FASTLED_ALLOW_INTERRUPTS 0
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define NUM_LEDS 114
#define DATA_PIN D4

int kleurtjes = 0;
int teller = 0;
int cycle_snelheid = 100;
static uint8_t hue = 0;
int C_optie = 0;

//Time-modus settings
int TIME_MODE = 1; //in mode 0 worden de losse minuten opgeteld bij de tijd. In mode 1 worden de minuten van de huidige tijd afgetrokken

//WIFI settings
const char* ssid = "ssid";                       // your network SSID (name)
const char* pass = "pass";                  // your network password
const char hostnamewifi[] = "Woordklok"; // hostname

Timezone myTZ;

// Define the array of leds
CRGB leds[NUM_LEDS];

//defineer lichtsensor
boolean autobright = true;        //automatische brightness aanpassing
int lichtSensorPin = A0;          //pin voor lichtsensor
int SensorValue = 0;
float lichtSensorFilter = 0.95;   //filter brightnesswaarde. 0 geen filter, 0.99 is max filter
float SensorValueFiltered;
int brightness = 96;              //initiele brightness; wordt ook gebruikt indien lichtsensor niet gebruikt wordt

// defineer klok eenheden
int uur;
int uur12;
int minuut;
int seconde;
int seconde2;


// defineer datum eenheden
int dag;
int maand;
int jaar;



//define colours
uint32_t Colour = CRGB::White;
String Colour_hex = "FFFFFF";

uint32_t Paars = CRGB::Purple;
uint32_t Rood = CRGB::Red;
uint32_t Wit = CRGB::White;


void setup () {
  delay(1000);
  Serial.begin(115200);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(brightness);
  set_max_power_in_volts_and_milliamps(5, 3000);  
  //FastLED.setDither( 0 );


  Serial.print("Connecting to ");
  Serial.print(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  setDebug(INFO);
  
  waitForSync();
  
  myTZ.setLocation(F("nl"));
  myTZ.setDefault();



  if (MDNS.begin("woordklok")) {
    Serial.println("");
    Serial.println("MDNS responder started");
  }

  ArduinoOTA.setHostname("Woordklok_ESP"); // give an name to our module
  ArduinoOTA.begin(); // OTA initialization  

  //start webserver
  startWebserver();

  Serial.println("HTTP server started");

  SPIFFS.begin();
  Serial.println("File System Initialized");  

  Serial.println("Setup completed");

  blank();
  fill_rainbow( leds, NUM_LEDS, 0, 5);
  FastLED.show();
  FastLED.delay(2000);

}

void loop () {

  ArduinoOTA.handle();  
  
  uur = hour();
  minuut = minute();
  seconde = second();
  dag = day();
  maand = month();
  jaar = year();

  //set brightness
  brightness = brightnessLED();
  FastLED.setBrightness (brightness);

  //show tijd
  tijd();

  if(seconde == 50){
    datum();
  }


  FastLED.delay(100);
  
  events(); // part of EZtime to sync on specified interval.
  checkRestart(); //check if restart is issued
  triggerEvent(); //check if events from webserver are triggered
    
}
//einde loop
