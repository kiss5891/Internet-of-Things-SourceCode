/*
  圖形

 一個從 Arduino 到電腦通訊的簡單例子:
 輸入 A0 的值發送到序列端口.  我們可以稱之為 "序列"通訊, 
 因為它連接 Arduino 和電腦的序列端口, 即使它可能實際上使用 USB. 
 字節從 Arduino 一個接一個 (連續) 被發送到電腦.

 你可以使用 serial monitor 去看 Arduino 所發送的數據, 或它可以由 Processing 被讀取, PD, Max/MSP, 或任何其他能夠從序列端口讀取字節的程序
 以下的圖為 Processing 的程式碼數據接收
 所以你可以看到類比輸入隨著時間變化的值.

 電路:
 任何類比輸入 sensor 連接到 A0.

 created 2006
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe and Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Graph
*/

void setup() {
  Serial.begin(9600);                                           // 初始化序列通訊
}

void loop() {
  Serial.println(analogRead(A0));                               // 發送 A0 的值
    delay(2);                                                   // 在上次讀取後等待兩毫秒穩定類比轉換數位
}

/* Processing code for this example

/*
  繪圖小品
  這個方案從序列端口 9600 胞率和圖表採用 ASCII 碼字串.
  它期望值的範圍在 0 到 1023, 跟著換行, 或換行並回傳
  
  Created 20 Apr 2005
  Updated 18 Jan 2008
  by Tom Igoe
  This example code is in the public domain.
* /

import processing.serial.*;

Serial myPort;                                                  // 序列端口
int xPos = 1;                                                   // 曲線圖的水平位置

void setup () {
  size(400, 300);                                               // 設置窗口大小

  println(Serial.list());                                       // 如果使用 Processing 2.1 或更高版本, 使用 Serial.printArray()

/*
  我知道我的 mac 上的序列總是在我的 Arduino 第一個端口
  所以我打開 Serial.list()[0].
  打開任何你使用的端口
* /
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');                                     // 不生成 serialEvent() 除非你得到新的一行字符
  background(0);                                                // 設至初始背景
 }
 
void draw () {
 }

void serialEvent (Serial myPort) {
  String inString = myPort.readStringUntil('\n');
  if (inString != null) {
    inString = trim(inString);                                  // 剪掉任何空白
    float inByte = float(inString);                             // 轉換 int 並 map 到螢幕高度
    inByte = map(inByte, 0, 1023, 0, height);
    stroke(127,34,255);                                         // 畫一條線
    line(xPos, height, xPos, height - inByte);
    if (xPos >= width) {
      xPos = 0;
      background(0);
    }
    else {
      xPos++;                                                   // 遞增水平位置
    }
  }
}

 */

/* Max/MSP v5 patch for this example
 ----------begin_max5_patcher----------
1591.3oc0YszbaaCD9r7uBL5RalQUAO3CvdyS5zVenWZxs5NcfHgjPCIfJIT
RTxj+6AOHkoTDooroUs0AQPR73a+1cwtK3WtZxzEpOwqlB9YveAlL4KWMYh6
Q1GLo99ISKXeJMmU451zTUQAWpmNy+NM+SZ2y+sR1l02JuU9t0hJvFlNcMPy
dOuBv.U5Rgb0LPpRpYBooM3529latArTUVvzZdFPtsXAuDrrTU.f.sBffXxL
vGE50lIHkUVJXq3fRtdaoDvjYfbgjujaFJSCzq4.tLaN.bi1tJefWpqbO0uz
1IjIABoluxrJ1guxh2JfPO2B5zRNyBCLDFcqbwNvuv9fHCb8bvevyyEU2JKT
YhkBSWPAfq2TZ6YhqmuMUo0feUn+rYpY4YtY+cFw3lUJdCMYAapZqzwUHX8S
crjAd+SIOU6UBAwIygy.Q1+HAA1KH6EveWOFQlitUK92ehfal9kFhUxJ3tWc
sgpxadigWExbt1o7Ps5dk3yttivyg20W0VcSmg1G90qtx92rAZbH4ez.ruy1
nhmaDPidE07J+5n2sg6E6oKXxUSmc20o6E3SPRDbrkXnPGUYE.i5nCNB9TxQ
jG.G0kCTZtH88f07Rt0ZMMWUw8VvbKVAaTk6GyoraPdZff7rQTejBN54lgyv
HE0Ft7AvIvvgvIwO23jBdUkYOuSvIFSiNcjFhiSsUBwsUCh1AgfNSBAeNDBZ
DIDqY.f8.YjfjV1HAn9XDTxyNFYatVTkKx3kcK9GraZpI5jv7GOx+Z37Xh82
LSKHIDmDXaESoXRngIZQDKVkpxUkMCyXCQhcCK1z.G457gi3TzMz4RFD515F
G3bIQQwcP3SOF0zlkGhiCBQ1kOHHFFlXaEBQIQnCwv9QF1LxPZ.A4jR5cyQs
vbvHMJsLll01We+rE2LazX6zYmCraRrsPFwKg1ANBZFY.IAihr8Ox.aH0oAL
hB8nQVw0FSJiZeunOykbT6t3r.NP8.iL+bnwNiXuVMNJH9H9YCm89CFXPBER
bz422p8.O4dg6kRxdyjDqRwMIHTbT3QFLskxJ8tbmQK4tm0XGeZWF7wKKtYY
aTAF.XPNFaaQBinQMJ4QLF0aNHF0JtYuHSxoUZfZY6.UU2ejJTb8lQw8Fo5k
Rv6e2PI+fOM71o2ecY1VgTYdCSxxUqLokuYq9jYJi6lxPgD2NIPePLB0mwbG
YA9Rgxdiu1k5xiLlSU6JVnx6wzg3sYHwTesB8Z5D7RiGZpXyvDNJY.DQX3.H
hvmcUN4bP1yCkhpTle2P37jtBsKrLWcMScEmltOPv22ZfAqQAdKr9HzATQwZ
q18PrUGt6Tst2XMCRUfGuhXs6ccn23YloomMqcTiC5iMGPsHsHRWhWFlaenV
XcqwgCQiGGJzptyS2ZMODBz6fGza0bzmXBj7+DA94bvpR01MffAlueO7HwcI
pWCwmzJdvi9ILgflLAFmyXB6O7ML0YbD26lenmcGxjVsZUN+A6pUK7AtTrPg
M+eRYG0qD9j4I7eEbco8Xh6WcO.or9XDC6UCiewbXHkh6xm5LiPEkzpJDRTu
mEB44Fgz4NCtJvX.SM1vo2SlTCZGAe7GZu6ahdRyzFOhYZ+mbVVSYptBw.K1
tboIkatIA7c1cTKD1u.honLYV04VkluHsXe0szv9pQCE9Ro3jaVB1o15pz2X
zYoBvO5KXCAe0LCYJybE8ZODf4fV8t9qW0zYxq.YJfTosj1bv0xc.SaC0+AV
9V9L.KKyV3SyTcRtmzi6rO.O16USvts4B5xe9EymDvebK0eMfW6+NIsNlE2m
eqRyJ0utRq13+RjmqYKN1e.4d61jjdsauXe3.2p6jgi9hsNIv97CoyJ01xzl
c3ZhUCtSHx3UZgjoEJYqNY+hYs5zZQVFW19L3JDYaTlMLqAAt1G2yXlnFg9a
53L1FJVcv.cOX0dh7mCVGCLce7GFcQwDdH5Ta3nyAS0pQbHxegr+tGIZORgM
RnMj5vGl1Fs16drnk7Tf1XOLgv1n0d2iEsCxR.eQsNOZ4FGF7whofgfI3kES
1kCeOX5L2rifbdu0A9ae2X.V33B1Z+.Bj1FrP5iFrCYCG5EUWSG.hhunHJd.
HJ5hhnng3h9HPj4lud02.1bxGw.
-----------end_max5_patcher-----------

 */
