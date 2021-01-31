import processing.serial.*;
PFont hello;  //テキスト用の変数
Serial myPort;
String mystr = "0";

void setup()
{
  size(600,600);
  frameRate(60);
  
   //フォントを読み込む
  hello = loadFont("Serif-48.vlw"); 
  
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 115200); // COM2
  // Macでは、COM1はBluetoothになっていることが多いので、list[1]を選択する
  // シリアル通信ができているかどうかは、ターミナル上で確認すると良い。
  // 参考  https://littlewing.hatenablog.com/entry/2016/04/06/153929
  myPort.bufferUntil('\n');
}

void draw()
{
  background(0);
  
  //textFont(変数名, サイズ)
  textFont(hello, 32); 
  
  //text(表示文字列, x座標, y座標)
    textSize(100);
    text("distance = ", 0, height / 4);
    text(mystr, width / 2, height / 2);
}

void serialEvent(Serial myPort) { 
  mystr = myPort.readStringUntil('\n');
  mystr = trim(mystr);
  println(mystr);
  
}
