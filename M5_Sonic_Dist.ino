// https://qiita.com/sasakisan/items/9f2aa0fd7203e0999129 を参考にしました。

#include <M5Stack.h>

#define TRIG 2
#define ECHO 5

int times;
int distance;
int predist = 0;

void setup()
{
  Serial.begin(115200); // 9600bpsでシリアルポートを開く
  M5.begin();

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // 文字サイズ
  M5.Lcd.setTextSize(7);
}

void loop()
{
  // 画面を黒くする
  M5.Lcd.fillScreen(BLACK);

  // 超音波を発生させる
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // 超音波を受け取る
  times = pulseIn(ECHO, HIGH);
  distance = (int)(times * 0.017);

  if (distance > 1000)
  {
    distance = predist;
  }

  // ディスプレイに表示させる
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(distance);
  delay(500);
  Serial.println(distance);

  predist = distance;
}
