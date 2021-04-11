#include <M5Stack.h>
#include <Wire.h>
#include "VL53L0X.h"

//library   = https://github.com/pololu/vl53l0x-arduino

VL53L0X sensor;
int preDist = 0;


void setup() {
  M5.begin();
  Serial.begin(115200);
  //Power chipがgpio21, gpio22, I2Cにつながれたデバイスに接続される。
  //バッテリー動作の場合はこの関数を読んでください（バッテリーの電圧を調べるらしい）
  M5.Power.begin();
  Wire.begin();// I2C通信を開始する

  sensor.init();
  sensor.setTimeout(500);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setTextSize(6);

}
void loop() {
  int distance = sensor.readRangeSingleMillimeters();
  //エラーだと、distance = 8190になる。
  //グラフが触れてしまうので、エラーの場合は前値
  if (distance > 3000) {
    distance = preDist;
  }

  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(distance);
  M5.Lcd.print("         ");

  Serial.println(distance);

  if (sensor.timeoutOccurred()) {
    M5.Lcd.setCursor(0, 50);
    M5.Lcd.println("TIMEOUT");
  } else {
    M5.Lcd.setCursor(0, 50);
    M5.Lcd.println("        ");
  }


  preDist = distance;
}
