//Special voor Donja
void Donja() {
  Serial.println("Start Animatie Donja ");

  for (int x = 0; x < 5; ++x) {
    blank();
    toon(woordDONJA, Paars);
    FastLED.show();
    FastLED.delay(1000); 
    blank();
    toon(hart_groot_rood_outline,Rood);
      if (x % 2) { 
        toon(hart_groot_rood_inside, Wit);
      }
      else {
        toon(hart_groot_rood_inside, Rood);
      }
    FastLED.show();
    FastLED.delay(1000); 
  }

  blank();
  toon(hart_groot_rood_outline,Rood);
  for (int j = 0; j < 10; ++j) {
    
      if (j % 2) { 
        toon(hart_groot_rood_inside, Wit);
      }
      else {
        toon(hart_groot_rood_inside, Rood);
      }
    FastLED.show();
    FastLED.delay(600); 
  }

  
//  toon(hart_groot_rood_outline,Rood);
//  for (int k = 0; k < 255*10; ++k) {
//    CHSV kleurhart = CHSV(k, 255, 255);
//    toon(hart_groot_rood_inside, kleurhart);
//    FastLED.show();
//    //FastLED.delay(200); 
//  }

  Serial.println("Stop Animatie Donja ");
  
}

//Special voor Arthur
void Arthur() {
  Serial.println("Start Animatie Arthur ");  

  blank();

  toon(L_A, Paars);
  FastLED.show();
  FastLED.delay(1000); 
  blank();

  toon(L_R, Paars);
  FastLED.show();
  FastLED.delay(1000); 
  blank();

  toon(L_T, Paars);
  FastLED.show();
  FastLED.delay(1000); 
  blank();

  toon(L_H, Paars);
  FastLED.show();
  FastLED.delay(1000); 
  blank();

  toon(L_U, Paars);
  FastLED.show();
  FastLED.delay(1000); 
  blank();

  toon(L_R, Paars);
  FastLED.show();
  FastLED.delay(1000); 
  blank();
  
  for (int x = 0; x < 5; ++x) {
    blank();

    toon(hart_groot_rood_outline,Rood);
      if (x % 2) { 
        toon(hart_groot_rood_inside, Wit);
      }
      else {
        toon(hart_groot_rood_inside, Rood);
      }
    FastLED.show();
    FastLED.delay(1000); 
  }

  Serial.println("Start Animatie Arthur ");

}


//test-animatie
void test() {

  Serial.println("Start Demo ");  
  
  blank();
  fill_rainbow( leds, NUM_LEDS, 0, 5);
  FastLED.show();
  FastLED.delay(5000);
  blank();

  toon(C_0, CHSV(0, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_1, CHSV(25, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_2, CHSV(50, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_3, CHSV(75, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_4, CHSV(100, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_5, CHSV(125, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_6, CHSV(150, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_7, CHSV(175, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_8, CHSV(200, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_9, CHSV(225, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();
  toon(C_plus, CHSV(250, 255, 255));
  FastLED.delay(1000); FastLED.show(); blank();

  
  uint32_t Colour_demo = Wit;
  toon(woordHET, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woordIS, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woord5, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woord10, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woordKWART, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woordOVER, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woordVOOR, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woordHALF, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woordOVER2, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woordVOOR2, Colour_demo);  
  FastLED.delay(100); FastLED.show();
  toon(w1, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w2, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w3, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w4, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w5, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w6, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w7, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w8, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w9, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w10, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w11, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(w12, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(woordUUR, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(wmin1, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(wmin2, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(wmin3, Colour_demo);
  FastLED.delay(100); FastLED.show();
  toon(wmin4, Colour_demo);
  FastLED.delay(100); FastLED.show();  

  Serial.println("Stop Demo "); 
}

void toon_woord(String Woord, int delaytime){
    Woord.toUpperCase();
    int hue = 255 / Woord.length();
   
      for (int x = 0; x < Woord.length(); x++) {
        blank();

        CHSV Colour = CHSV(hue*x, 255, 255);
        
        switch (Woord[x]) {
                case 'A': toon(L_A, Colour); break; 
                case 'B': toon(L_B, Colour); break; 
                case 'C': toon(L_C, Colour); break;
                case 'D': toon(L_D, Colour); break;
                case 'E': toon(L_E, Colour); break;
                case 'F': toon(L_F, Colour); break;
                case 'G': toon(L_G, Colour); break;
                case 'H': toon(L_H, Colour); break;
                case 'I': toon(L_I, Colour); break;
                case 'J': toon(L_J, Colour); break;
                case 'K': toon(L_K, Colour); break;
                case 'L': toon(L_L, Colour); break;
                case 'M': toon(L_M, Colour); break; 
                case 'N': toon(L_N, Colour); break; 
                case 'O': toon(L_O, Colour); break; 
                case 'P': toon(L_P, Colour); break; 
                case 'Q': toon(L_Q, Colour); break; 
                case 'R': toon(L_R, Colour); break; 
                case 'S': toon(L_S, Colour); break; 
                case 'T': toon(L_T, Colour); break; 
                case 'U': toon(L_U, Colour); break; 
                case 'V': toon(L_V, Colour); break; 
                case 'W': toon(L_W, Colour); break; 
                case 'X': toon(L_X, Colour); break; 
                case 'Y': toon(L_Y, Colour); break; 
                case 'Z': toon(L_Z, Colour); break;
                case '0': toon(C_0, Colour); break;
                case '1': toon(C_1, Colour); break;
                case '2': toon(C_2, Colour); break;
                case '3': toon(C_3, Colour); break;
                case '4': toon(C_4, Colour); break;
                case '5': toon(C_5, Colour); break;
                case '6': toon(C_6, Colour); break;
                case '7': toon(C_7, Colour); break;
                case '8': toon(C_8, Colour); break;
                case '9': toon(C_9, Colour); break;    
                case '+': toon(C_plus, Colour); break;
                default: break;     
              }
          FastLED.delay(delaytime);    
      }
}

//int CL_0[] = 
//int CR_0[] = 
//int CL_1[] = 
//int CR_1[] = 
//  dag = day();
//  maand = month();
//  jaar = year();


void datum(){
  blank();
  byte Datum[7];  
  Datum[6] = (year() - 2000) % 10;
  Datum[5] = (year() - 2000) / 10;
  Datum[4] = month() % 10;
  Datum[3] = month() / 10;
  Datum[2] = day() % 10;
  Datum[1] = day() / 10; 


  for (int x = 1; x <= 4; x++) { 
      if (x % 2==0) { 
        switch (Datum[x]) {
          case 0: toon(CR_0, Wit); break;
          case 1: toon(CR_1, Wit); break;
          case 2: toon(CR_2, Wit); break;
          case 3: toon(CR_3, Wit); break;
          case 4: toon(CR_4, Wit); break;
          case 5: toon(CR_5, Wit); break;
          case 6: toon(CR_6, Wit); break;
          case 7: toon(CR_7, Wit); break;
          case 8: toon(CR_8, Wit); break;
          case 9: toon(CR_9, Wit); break;    
          default: break;     
        }
        FastLED.show();
        FastLED.delay(2000); 
        blank();
      }
      else {
        switch (Datum[x]) {
          case 0: toon(CL_0, Wit); break;
          case 1: toon(CL_1, Wit); break;
          case 2: toon(CL_2, Wit); break;
          case 3: toon(CL_3, Wit); break;
          case 4: toon(CL_4, Wit); break;
          case 5: toon(CL_5, Wit); break;
          case 6: toon(CL_6, Wit); break;
          case 7: toon(CL_7, Wit); break;
          case 8: toon(CL_8, Wit); break;
          case 9: toon(CL_9, Wit); break;    
          default: break;     
        }
                
      }

  }
}
