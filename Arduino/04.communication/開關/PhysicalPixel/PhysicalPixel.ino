/*
  Physical Pixel

 這是一個使用 Arduino 接收電腦資訊的例子.  
 在這個情況下, 當收到 'H' Arduino 打開 LED 燈,
 當收到 'L' 關閉 LED


 這個數據可以從 Arduino serial monitor 被發送, 或其他程序像 Processing (看下列的程式碼), 
 Flash (通過 serial-net 代理), PD, 或 Max/MSP.

 電路:
 * LED 連接從引腳 13 到 ground

 created 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Tom Igoe and Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/PhysicalPixel
 */

const int ledPin = 13;                              // LED 連接的引腳
int incomingByte;                                   // 放讀取的資料

void setup() {
  Serial.begin(9600);                               // 序列通訊 9600 bps
  pinMode(ledPin, OUTPUT);                          // 引腳 13 為輸出
}

void loop() {
  if (Serial.available() > 0) {                     // 如果有收到資料
    incomingByte = Serial.read();                   // 讀近來的資料放在 incomingByte
    if (incomingByte == 'H') {                      // 如果讀進來的資料是 H
      digitalWrite(ledPin, HIGH);                   // LED 亮
    }
    if (incomingByte == 'L') {                      // 如果讀進來的資料是 L
      digitalWrite(ledPin, LOW);                    // LED 暗
    }
  }
}
