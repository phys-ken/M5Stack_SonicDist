import processing.serial.*;
PFont hello;  //テキスト用の変数
Serial myPort;
String mystr = "";
int tmpVal;

void setup()
{
  size(1500,800);
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
    textSize(300);
    text("x[cm] = ", 0, height / 3);
        textSize(500);
    //text(mystr, width / 3, height * 9/ 10); cmが送られてくるときはこっち
        text(str(round(int(mystr)/10)), width / 3, height * 9/ 10); //mmが送られてくるときはこっち

}

void serialEvent(Serial myPort) { 
  mystr = myPort.readStringUntil('\n');
  mystr = trim(mystr);
  println(mystr);
  
}
