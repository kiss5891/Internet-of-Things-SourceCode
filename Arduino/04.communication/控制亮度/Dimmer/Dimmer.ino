/*
  控置亮度

 從電腦發送字節數據到 Arduino 板,
 在這種情況下控制 LED 的亮度.  被發送的字節, 範圍是 0 到 255.  Arduino
 讀取這些字節並用它們來設置 LED 的亮度.

 電路:
 LED 連接引腳 9 和 ground.
 處理序列通訊, Max/MSP, 或其他序列應用程序

 created 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Tom Igoe and Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Dimmer

*/

const int ledPin = 9;                                         // LED 連接的引腳

void setup() {
  Serial.begin(9600);                                         // 初始化序列通訊
  pinMode(ledPin, OUTPUT);                                    // 初始化 ledPin 為輸出
}

void loop() {
  byte brightness;
  if (Serial.available()) {                                   // 檢查如果電腦已發送數據
    brightness = Serial.read();                               // 閱讀最新的字節 (這必須是 0 到 255)
    analogWrite(ledPin, brightness);                          // 發送亮度到 LED
  }
}

/* 
  在這個例子的程式碼
  控置亮度 - 透過序列 port 發送字節
  by David A. Mellis
  This example code is in the public domain.
* /

import processing.serial.*;
Serial port;

void setup() {
  size(256, 150);

  println("Available serial ports:");
  println(Serial.list());                                     // 如果使用 2.1 或更高版本, 使用 Serial.printArray()

/* 
  使用 list 中的第一個端口 (數字 0).  更改選擇這個端口對應到你的 Arduino 板.
  最後一個參數是通訊的速度 (即 9600) .
  Serial.begin() 可以傳對應的值到 Arduino
* /
  port = new Serial(this, Serial.list()[0], 9600);

/*
  如果你知道你用的 Arduino 板的端口名稱, 
  你可以像這樣直接指定.
  port = new Serial(this, "COM1", 9600);
* /
}

void draw() {
  for (int i = 0; i < 256; i++) {
    stroke(i);
    line(i, 0, i, 150);
  }
  port.write(mouseX);                                         // 寫單字節在 mouseX 的位置傳到序列端口
}
*/

/* Max/MSP v5 patch for this example

----------begin_max5_patcher----------
1008.3ocuXszaiaCD9r8uhA5rqAeHIa0aAMaAVf1S6hdoYQAsDiL6JQZHQ2M
YWr+2KeX4vjnjXKKkKhhiGQ9MeyCNz+X9rnMp63sQvuB+MLa1OlOalSjUvrC
ymEUytKuh05TKJWUWyk5nE9eSyuS6jesvHu4F4MxOuUzB6X57sPKWVzBLXiP
xZtGj6q2vafaaT0.BzJfjj.p8ZPukazsQvpfcpFs8mXR3plh8BoBxURIOWyK
rxspZ0YI.eTCEh5Vqp+wGtFXZMKe6CZc3yWZwTdCmYW.BBkdiby8v0r+ST.W
sD9SdUkn8FYspPbqvnBNFtZWiUyLmleJWo0vuKzeuj2vpJLaWA7YiE7wREui
FpDFDp1KcbAFcP5sJoVxp4NB5Jq40ougIDxJt1wo3GDZHiNocKhiIExx+owv
AdOEAksDs.RRrOoww1Arc.9RvN2J9tamwjkcqknvAE0l+8WnjHqreNet8whK
z6mukIK4d+Xknv3jstvJs8EirMMhxsZIusET25jXbX8xczIl5xPVxhPcTGFu
xNDu9rXtUCg37g9Q8Yc+EuofIYmg8QdkPCrOnXsaHwYs3rWx9PGsO+pqueG2
uNQBqWFh1X7qQG+3.VHcHrfO1nyR2TlqpTM9MDsLKNCQVz6KO.+Sfc5j1Ykj
jzkn2jwNDRP7LVb3d9LtoWBAOnvB92Le6yRmZ4UF7YpQhiFi7A5Ka8zXhKdA
4r9TRGG7V4COiSbAJKdXrWNhhF0hNUh7uBa4Mba0l7JUK+omjDMwkSn95Izr
TOwkdp7W.oPRmNRQsiKeu4j3CkfVgt.NYPEYqMGvvJ48vIlPiyzrIuZskWIS
xGJPcmPiWOfLodybH3wjPbMYwlbFIMNHPHFOtLBNaLSa9sGk1TxMzCX5KTa6
WIH2ocxSdngM0QPqFRxyPHFsprrhGc9Gy9xoBjz0NWdR2yW9DUa2F85jG2v9
FgTO4Q8qiC7fzzQNpmNpsY3BrYPVJBMJQ1uVmoItRhw9NrVGO3NMNzYZ+zS7
3WTvTOnUydG5kHMKLqAOjTe7fN2bGSxOZDkMrBrGQ9J1gONBEy0k4gVo8qHc
cxmfxVihWz6a3yqY9NazzUYkua9UnynadOtogW.JfsVGRVNEbWF8I+eHtcwJ
+wLXqZeSdWLo+FQF6731Tva0BISKTx.cLwmgJsUTTvkg1YsnXmxDge.CDR7x
D6YmX6fMznaF7kdczmJXwm.XSOOrdoHhNA7GMiZYLZZR.+4lconMaJP6JOZ8
ftCs1YWHZI3o.sIXezX5ihMSuXzZtk3ai1mXRSczoCS32hAydeyXNEu5SHyS
xqZqbd3ZLdera1iPqYxOm++v7SUSz
-----------end_max5_patcher-----------
 */
