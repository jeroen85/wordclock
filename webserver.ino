//webserver
void startWebserver(){
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  
    if (request->hasParam("c")) {
        Colour_hex = request->getParam("c")->value();
        Colour = StrToHex(Colour_hex.c_str());
        Serial.print("Color changed to: ");
        Serial.println(Colour_hex);
    }
  
    request->send_P(200, "text/html", webpagina, processor);
    
  });
  
  server.on("/color", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("c")) {
        Colour_hex = request->getParam("c")->value();
        Colour = StrToHex(Colour_hex.c_str());
        Serial.print("Color changed to: ");
        Serial.println(Colour_hex);
    }  
    request->send ( 200, "text/plain",  "OK");
  
  });
  
  server.on("/restart", HTTP_GET, [](AsyncWebServerRequest *request){
    //request->send ( 200, "text/plain",  "OK; restart");
    request->send(200, "text/html", F("<!DOCTYPE html><html><head><meta http-equiv=\"refresh\" content=\"5; url=/\"></head><body>Restarting...</body></html>"));
    Restart = 1;
  });
  
  server.on("/brightness", HTTP_GET, [](AsyncWebServerRequest *request){
  
    if (request->hasParam("B") && autobright == false) {
        brightness = request->getParam("B")->value().toInt();
        Serial.print("Brightness changed to: ");
        Serial.println(brightness);
      }
    
    request->send ( 200, "text/plain",  "OK");
  
  }); 

  server.on("/readBrightness", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send ( 200, "text/plain",  String(brightness));
  });  

  server.on("/timemodus", HTTP_GET, [](AsyncWebServerRequest *request){
    String r_timemodus;
    if(TIME_MODE == 1){
      TIME_MODE = 0;
      r_timemodus = "0: Tijd + losse minuten";
    }
    else if(TIME_MODE == 0){
      TIME_MODE = 1;
      r_timemodus = "1: Tijd - losse minuten";
    }
    request->send ( 200, "text/plain",  String(r_timemodus));
  });  

  server.on("/colormodus", HTTP_GET, [](AsyncWebServerRequest *request){
    String r_colormodus;

   if(kleurtjes == 1){
      kleurtjes = 0;
      r_colormodus = "Vaste kleur";
    }
    else if(kleurtjes == 0){
      kleurtjes = 1;
      r_colormodus = "Color cycle";
    }    
    request->send ( 200, "text/plain",  String(r_colormodus));
  });    

  server.on("/AB", HTTP_GET, [](AsyncWebServerRequest *request){
    String r_AB;
    if(autobright == true){
      autobright = false;
      r_AB = "Uit";
    }
    else if(autobright == false){
      autobright = true;
      r_AB = "Aan";
    }    
    request->send ( 200, "text/plain",  String(r_AB));
  });   

  server.on("/iro.min.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/iro.min.js", "application/javascript");
  }); 


  server.on("/demo", HTTP_GET, [](AsyncWebServerRequest *request){
    PerformEvent = "demo";
    request->send ( 200, "text/plain",  "OK");
  });
   
  server.on("/donja", HTTP_GET, [](AsyncWebServerRequest *request){
    PerformEvent = "Donja";
    request->send ( 200, "text/plain",  "OK");
  });
    
  server.on("/arthur", HTTP_GET, [](AsyncWebServerRequest *request){
    PerformEvent = "Arthur";
    request->send ( 200, "text/plain",  "OK");
  });
    
  server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404, "text/plain", "Error 404: Not found");
  });  
  
  server.begin();
  
}

String processor(const String& var)
{
    if(autobright == false){
      AB = "uit";
      showslider = "inline";
    }
    else if(autobright == true){
      AB = "aan"; 
      showslider = "none";
    }
  
    modus = "0: Tijd + losse minuten";
    if(TIME_MODE == 1){
      modus = "1: Tijd - losse minuten";
    }  
  
    c_rotate = "Vaste kleur";
    if(kleurtjes == 1){
      c_rotate = "Color cycle";
    } 
 
  if(var == "tijd"){
    char tijdnotatie[8];
    sprintf (tijdnotatie, "%02d:%02d:%02d", uur, minuut % 60, seconde % 60);
    return String(tijdnotatie);
  }

  if(var == "datum"){
    char datumnotatie[10];
    sprintf (datumnotatie, "%02d/%02d/%04d", dag, maand, jaar);
    return String(datumnotatie);
  }

  else if(var == "modus"){
    return String(modus);
  } 
    
  else if(var == "kleurrotatie"){
    return String(c_rotate);
  } 
    
  else if(var == "brightness"){
    return String(brightness);
  } 
    
  else if(var == "showslider"){
    return String(showslider);
  } 
      
  else if(var == "autobrightness"){
    return String(AB);
  } 
      
  else if(var == "kleur_hex"){
    return String(Colour_hex.c_str());
  } 
  
  return String();
}


//void handleWoord() {
//  int delaytime = 1000;
//  
//  if(server.arg("W") != "" ){
//    String Woord = server.arg("W");
//
//    if(server.arg("d") != "" ){
//      delaytime = server.arg("d").toInt();
//    } 
//    
//    toon_woord(Woord, delaytime);
//    
//
//    //process woord
//  }
//  
//  server.send ( 200, "text/plain",  "OK");
//
//}
