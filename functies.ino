//LED-functies

void toon(int Woord[], CRGB Kleur) {
  for (int x = 0; x < NUM_LEDS + 1; x++) {
    if(Woord[x] == -1) {
      break;
    } 
    else {
      if(kleurtjes == 1){
        leds[Woord[x]-1] = CHSV(hue, 255, 255);
         if(teller >= cycle_snelheid){
          hue++;
          teller = 0;
         }
        teller++;  
      }
      else{  
      leds[Woord[x]-1] = Kleur;
      }
    }
  }
}

void blank() {
//clear all
for (int x = 0; x < NUM_LEDS; ++x) {
  leds[x] = CRGB::Black;
}
//  FastLED.show();

}

//end LED-functies

//overige functies
int brightnessLED(){
  int brightness_result;
  if (autobright == true){
    SensorValue = analogRead(lichtSensorPin);

    //filter sensorwaarde
    SensorValueFiltered = SensorValue * (1-lichtSensorFilter) + SensorValueFiltered * lichtSensorFilter;
    
    //remap brightness.
    brightness_result = constrain(map(SensorValueFiltered, 0, 700, 2,255),0,255);
  }
  else{
    brightness_result = brightness;
  }

  return brightness_result;
}


uint32_t StrToHex(const char* str)
{
  return (uint32_t) strtol(str, 0, 16);
}

void checkRestart() {
  if(Restart == 1){
    delay(1000);
    ESP.restart();     
  }
}

void triggerEvent(){
  if(PerformEvent == "demo"){
    PerformEvent = "";
    test();
  }
  else if(PerformEvent == "Arthur"){
    PerformEvent = "";
    Arthur();
  }
  else if(PerformEvent == "Donja"){
    PerformEvent = "";
    Donja();
  }
  else{
    PerformEvent = "";
  }

}
