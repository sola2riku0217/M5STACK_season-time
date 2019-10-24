

void drawNextCost_summer(){

  //次の時刻帯のコストを表示
  M5.Lcd.setTextSize(1);
  Serial.println("summer");
  if(hh<8){
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    fontDump(20, 150, "8時から", 24,TFT_YELLOW);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_YELLOW);     
  }else if(hh<10){
    M5.Lcd.setTextColor(TFT_RED, TFT_BLACK);
    fontDump(20, 150, "10時から", 24,TFT_RED);
    M5.Lcd.drawString("42.36", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_RED);
   }else if(hh<17){
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    fontDump(20, 150, "17時から", 24,TFT_YELLOW);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_YELLOW);
   }else if(hh<22){
    M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
    fontDump(20, 150, "22時から", 24,TFT_GREEN);
    M5.Lcd.drawString("11.22", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_GREEN);
   }else{
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    fontDump(20, 150, "8時から", 24,TFT_YELLOW);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_YELLOW);     
   }
}


void drawNextCost_winter(){

  //次の時刻帯のコストを表示
  M5.Lcd.setTextSize(1);
  if(hh<8){
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    fontDump(20, 150, "8時から", 24,TFT_YELLOW);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_YELLOW);     
  }else if(hh<16){
    M5.Lcd.setTextColor(TFT_RED, TFT_BLACK);
    fontDump(20, 150, "16時から", 24,TFT_RED);
    M5.Lcd.drawString("42.36", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_RED);
   }else if(hh<18){
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    fontDump(20, 150, "18時から", 24,TFT_YELLOW);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_YELLOW);
   }else if(hh<22){
    M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
    fontDump(20, 150, "22時から", 24,TFT_GREEN);
    M5.Lcd.drawString("11.22", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_GREEN);
   }else{
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    fontDump(20, 150, "8時から", 24,TFT_YELLOW);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_YELLOW);     
   }
}



void drawNextCost_other(){

  //次の時刻帯のコストを表示
  M5.Lcd.setTextSize(1);
  if(hh<8){
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    fontDump(20, 150, "8時から", 24,TFT_YELLOW);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_YELLOW);     
  }else if(hh<10){
    M5.Lcd.setTextColor(TFT_RED, TFT_BLACK);
    fontDump(20, 150, "10時から", 24,TFT_RED);
    M5.Lcd.drawString("38.50", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_RED);
   }else if(hh<17){
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
    fontDump(20, 150, "17時から", 24,TFT_YELLOW);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_YELLOW);
   }else if(hh<22){
    M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
    fontDump(20, 150, "22時から", 24,TFT_GREEN);
    M5.Lcd.drawString("11.22", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_GREEN);
   }else{
    M5.Lcd.setTextColor(TFT_RED, TFT_BLACK);
    fontDump(20, 150, "8時から", 24,TFT_RED);
    M5.Lcd.drawString("26.24", 130, 180, 6); 
    fontDump(280, 200, "円", 24,TFT_RED);     
   }
}


void drawCost_winter(){

  //現在時刻のコストを表示
  if(hh<8 || hh>=22){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
      M5.Lcd.drawString("11", 0, 10, 6); 
      M5.Lcd.drawString(".22", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_GREEN);
      
  }else if((hh>=8 && hh<16) || (hh>=18 && hh<22)){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
      M5.Lcd.drawString("26", 0, 10, 6); 
      M5.Lcd.drawString(".24", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_YELLOW);
   }else if(hh>=16 && hh<18){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_RED, TFT_BLACK);
      M5.Lcd.drawString("42", 0, 10, 6); 
      M5.Lcd.drawString(".36", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_RED);
   }
}

void drawCost_summer(){

  //現在時刻のコストを表示
  if(hh<8 || hh>=22){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
      M5.Lcd.drawString("11", 0, 10, 6); 
      M5.Lcd.drawString(".22", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_GREEN);
      
  }else if((hh>=8 && hh<10) || (hh>=17 && hh<22)){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
      M5.Lcd.drawString("26", 0, 10, 6); 
      M5.Lcd.drawString(".24", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_YELLOW);
   }else if(hh>=10 && hh<17){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_RED, TFT_BLACK);
      M5.Lcd.drawString("42", 0, 10, 6); 
      M5.Lcd.drawString(".36", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_RED);
   }
}


void drawCost_other(){

  //現在時刻のコストを表示
  if(hh<8 || hh>=22){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
      M5.Lcd.drawString("11", 0, 10, 6); 
      M5.Lcd.drawString(".22", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_GREEN);
      
  }else if((hh>=8 && hh<10) || (hh>=17 && hh<22)){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
      M5.Lcd.drawString("26", 0, 10, 6); 
      M5.Lcd.drawString(".24", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_YELLOW);
   }else if(hh>=10 && hh<17){
      M5.Lcd.setTextSize(3);
      M5.Lcd.setTextColor(TFT_RED, TFT_BLACK);
      M5.Lcd.drawString("38", 0, 10, 6); 
      M5.Lcd.drawString(".50", 160, 60, 4);
      fontDump(280, 120, "円", 24,TFT_RED);
   }

}


