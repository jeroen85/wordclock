void tijd(){
//maak led-array leeg
blank();

//standaard HET IS tonen
toon(woordHET, Colour);
toon(woordIS, Colour);

//zet uur om naar 12h format
    if (uur == 1 || uur == 13) uur12 = 1;
    if (uur == 2 || uur == 14) uur12 = 2;
    if (uur == 3 || uur == 15) uur12 = 3;
    if (uur == 4 || uur == 16) uur12 = 4;
    if (uur == 5 || uur == 17) uur12 = 5;
    if (uur == 6 || uur == 18) uur12 = 6;
    if (uur == 7 || uur == 19) uur12 = 7;
    if (uur == 8 || uur == 20) uur12 = 8;
    if (uur == 9 || uur == 21) uur12 = 9;
    if (uur == 10 || uur == 22) uur12 = 10;
    if (uur == 11 || uur == 23) uur12 = 11;
    if (uur == 12 || uur == 00) uur12 = 12;

//bepaal welk uur opgelicht moet worden  
    if ((TIME_MODE == 1 && minuut <= 15) || (TIME_MODE == 0 && minuut <= 19)){
      switch (uur12) {
        case 1: toon(w1, Colour); break; 
        case 2: toon(w2, Colour); break; 
        case 3: toon(w3, Colour); break;
        case 4: toon(w4, Colour); break;
        case 5: toon(w5, Colour); break;
        case 6: toon(w6, Colour); break;
        case 7: toon(w7, Colour); break;
        case 8: toon(w8, Colour); break;
        case 9: toon(w9, Colour); break;
        case 10: toon(w10, Colour); break;
        case 11: toon(w11, Colour); break;
        case 12: toon(w12, Colour); break;        
      }
    }
    else{
      switch (uur12) {
        case 1: toon(w2, Colour); break; 
        case 2: toon(w3, Colour); break; 
        case 3: toon(w4, Colour); break;
        case 4: toon(w5, Colour); break;
        case 5: toon(w6, Colour); break;
        case 6: toon(w7, Colour); break;
        case 7: toon(w8, Colour); break;
        case 8: toon(w9, Colour); break;
        case 9: toon(w10, Colour); break;
        case 10: toon(w11, Colour); break;
        case 11: toon(w12, Colour); break;
        case 12: toon(w1, Colour); break;        
      }      
    }

//behandel minuten
  if(TIME_MODE == 1){
    if(minuut >= 56 || minuut ==0) {
      toon(woordUUR, Colour);
    }
    else if(minuut >= 1 && minuut <=5) {
      toon(woord5, Colour);
      toon(woordOVER, Colour); 
    }
    else if(minuut >= 6 && minuut <=10) {
      toon(woord10, Colour);
      toon(woordOVER, Colour);  
    }
    else if(minuut >= 11 && minuut <=15) {
      toon(woordKWART, Colour);
      toon(woordOVER2, Colour);  
    }
    else if(minuut >= 16 && minuut <=20) {
      toon(woord10, Colour);
      toon(woordVOOR, Colour);
      toon(woordHALF, Colour);
    }
    else if(minuut >= 21 && minuut <=25) {
      toon(woord5, Colour);
      toon(woordVOOR, Colour);
      toon(woordHALF, Colour);
    }
    else if(minuut >= 26 && minuut <=30) {
      toon(woordHALF, Colour);
    } 
    else if(minuut >= 31 && minuut <=35) {
      toon(woord5, Colour);
      toon(woordOVER, Colour);
      toon(woordHALF, Colour);
    }
    else if(minuut >= 36 && minuut <=40) {
      toon(woord10, Colour);
      toon(woordOVER, Colour);
      toon(woordHALF, Colour);
    }
    else if(minuut >= 41 && minuut <=45) {
      toon(woordKWART, Colour);
      toon(woordVOOR2, Colour);
    }
    else if(minuut >= 46 && minuut <=50) {
      toon(woord10, Colour);
      toon(woordVOOR, Colour);
    }
    else if(minuut >= 51 && minuut <=55) {
      toon(woord5, Colour);
      toon(woordVOOR, Colour);
    }   
  
    if(minuut%5 == 1) {
    toon(wmin1, Colour);
    toon(wmin2, Colour);
    toon(wmin3, Colour);
    toon(wmin4, Colour);    
    }
    else if(minuut%5 == 2) {
    toon(wmin2, Colour);
    toon(wmin3, Colour);
    toon(wmin4, Colour);     
    }
    else if(minuut%5 == 3) {
    toon(wmin3, Colour);
    toon(wmin4, Colour);     
    }
    else if(minuut%5 == 4) {
    toon(wmin4, Colour);      
    } 
  }
  else if(TIME_MODE == 0){
    if(minuut == 00 || minuut <=4) {
      toon(woordUUR, Colour);
    }
    else if(minuut >= 5 && minuut <=9) {
      toon(woord5, Colour);
      toon(woordOVER, Colour); 
    }
    else if(minuut >= 10 && minuut <=14) {
      toon(woord10, Colour);
      toon(woordOVER, Colour);  
    }
    else if(minuut >= 15 && minuut <=19) {
      toon(woordKWART, Colour);
      toon(woordOVER2, Colour);  
    }
    else if(minuut >= 20 && minuut <=24) {
      toon(woord10, Colour);
      toon(woordVOOR, Colour);
      toon(woordHALF, Colour);
    }
    else if(minuut >= 25 && minuut <=29) {
      toon(woord5, Colour);
      toon(woordVOOR, Colour);
      toon(woordHALF, Colour);
    }
    else if(minuut >= 30 && minuut <=34) {
      toon(woordHALF, Colour);
    } 
    else if(minuut >= 35 && minuut <=39) {
      toon(woord5, Colour);
      toon(woordOVER, Colour);
      toon(woordHALF, Colour);
    }
    else if(minuut >= 40 && minuut <=44) {
      toon(woord10, Colour);
      toon(woordOVER, Colour);
      toon(woordHALF, Colour);
    }
    else if(minuut >= 45 && minuut <=49) {
      toon(woordKWART, Colour);
      toon(woordVOOR2, Colour);
    }
    else if(minuut >= 50 && minuut <=54) {
      toon(woord10, Colour);
      toon(woordVOOR, Colour);
    }
    else if(minuut >= 55 && minuut <=59) {
      toon(woord5, Colour);
      toon(woordVOOR, Colour);
    }   
  
    if(minuut%5 == 1) {
    toon(wmin1, Colour);
    }
    else if(minuut%5 == 2) {
    toon(wmin1, Colour);
    toon(wmin2, Colour);  
    }
    else if(minuut%5 == 3) {
    toon(wmin1, Colour);
    toon(wmin2, Colour);
    toon(wmin3, Colour);     
    }
    else if(minuut%5 == 4) {
    toon(wmin1, Colour);
    toon(wmin2, Colour);
    toon(wmin3, Colour);
    toon(wmin4, Colour);      
    }           
  }

//laad led-array
  FastLED.show();
  
}
//einde tijd()
