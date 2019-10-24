#include <M5Stack.h>
#include <WiFi.h>
#include <sdfonts.h>
#include "time.h"
#define SD_PN 4


//const char* ssid       = "IODATA-dc3118-2G";  
//const char* password   = "5484916349711";
const char* ssid       = "SPWN_H37_FE1982";  
const char* password   = "jh3nfee9dyj344m";

const char* ntpServer =  "ntp.jst.mfeed.ad.jp";
const long  gmtOffset_sec = 9 * 3600;
const int   daylightOffset_sec = 0;
static uint8_t conv2d(const char* p); // Forward declaration needed for IDE 1.6.x
uint16_t YY , MM , dd ,hh, mm , ss;
byte xcolon = 0, xsecs = 0;
int statusflg = 0;
char cost_yen[14] = "";
char cost_sen[14] = "";

// フォントデータの表示
// buf(in) : フォント格納アドレス
// ビットパターン表示
// d: 8ビットパターンデータ
void fontDisp(uint16_t x, uint16_t y, uint8_t* buf, uint32_t color) {
  uint32_t txt_color = color;
  uint32_t bg_color = TFT_BLACK;

  uint8_t bn = SDfonts.getRowLength();               // 1行当たりのバイト数取得

  for (uint8_t i = 0; i < SDfonts.getLength(); i += bn ) {
    for (uint8_t j = 0; j < bn; j++) {
      for (uint8_t k = 0; k < 8; k++) {
        if (buf[i + j] & 0x80 >> k) {
          M5.Lcd.drawPixel(x + 8 * j + k , y + i / bn, txt_color);
        } else {
          M5.Lcd.drawPixel(x + 8 * j + k , y + i / bn, bg_color);
        }
      }
    }
  }
}


// 指定した文字列を指定したサイズで表示する
// pUTF8(in) UTF8文字列
// sz(in)    フォントサイズ(8,10,12,14,16,20,24)
void fontDump(uint16_t x, uint16_t y, char* pUTF8, uint8_t sz, uint32_t color) {
  //uint8_t buf[MAXFONTLEN]; // フォントデータ格納アドレス(最大24x24/8 = 72バイト)
  uint8_t buf[144];
  SDfonts.open();                                   // フォントのオープン
  SDfonts.setFontSize(sz);                          // フォントサイズの設定
  SDfonts.setFontSizeAsIndex(EXFONT24);
  uint16_t mojisu = 0;
  while ( pUTF8 = SDfonts.getFontData(buf, pUTF8) ) { // フォントの取得
    fontDisp(x + mojisu * sz, y, buf,color);                 // フォントパターンの表示
    ++mojisu;
  }

  SDfonts.close();                                  // フォントのクローズ
}


//
///*
//// よりそう＋シーズンタイムから現時刻の電気料金単価を算出する
//*/
//  
void checkCost(){
  Serial.println(MM);
  if(MM==12 || MM==1 || MM==2){
    drawCost_winter();
    drawNextCost_winter();
  }else if(MM==7 || MM==8 || MM==9){
    
    drawCost_summer();
    drawNextCost_summer();
  }else{
    drawCost_other();
    drawNextCost_other();
  }
}


void setup() {
  Serial.begin(115200);

  M5.begin();

  M5.Lcd.setBrightness(100);
  M5.Lcd.fillScreen(TFT_BLACK);

  SDfonts.init(SD_PN);
  Serial.println(F("sdfonts liblary"));
  
  
  //connect to WiFi
  M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
  M5.Lcd.drawString("Connecting...", 0, 0, 4); 
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  M5.Lcd.clear();
  Serial.println("CONNECTED");
  
  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println("checkcost");
  YY = timeinfo.tm_year + 1900; MM = timeinfo.tm_mon+1;
  dd = timeinfo.tm_mday;        hh = timeinfo.tm_hour;
  mm = timeinfo.tm_min;         ss = timeinfo.tm_sec;
  checkCost();

  //disconnect WiFi as it's no longer needed
//  WiFi.disconnect(true);
//  WiFi.mode(WIFI_OFF);  

}

void loop() {
  
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  
  /*
  // 年（YY）月（MM）日（dd）時間（hh）分（mm）秒（ss）
  // 各値をセットする
  */
  
  YY = timeinfo.tm_year + 1900; MM = timeinfo.tm_mon+1;
  dd = timeinfo.tm_mday;        hh = timeinfo.tm_hour;
  mm = timeinfo.tm_min;         ss = timeinfo.tm_sec;

  /*
  // M5Stackに時間・金額を描画する
  */

  if(mm==0 && ss == 0){
    M5.Lcd.clear();
    delay(1000);
    checkCost();
  }
  
}


// Function to extract numbers from compile time string
static uint8_t conv2d(const char* p) {
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}
//-------------------------------------------------------



