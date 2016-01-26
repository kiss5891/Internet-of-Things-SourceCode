/*
 控制亮度
 
 這個例子說明如何使用 analogWrite() 控制 LED 亮度在腳位 9
 
 This example code is in the public domain.
*/

int led = 9;                                     // 讓 LED 接到腳位
int brightness = 0;                              // LED 有多亮
int fadeAmount = 5;                              // LED 如何變暗

void setup() {                                   // 當按下 reset 設置例行程式並運行一次 
  pinMode(led, OUTPUT);                          // 設置腳位 9 為輸出
}

void loop() {                                    // 這個循環回圈會不斷的重複
  analogWrite(led, brightness);                  // 設置腳位 9 的亮度 
  brightness = brightness + fadeAmount;          // 用循環改變下一次的亮度
  if (brightness == 0 || brightness == 255) {    // 在最亮或最暗的時候改變方向
    fadeAmount = -fadeAmount ;
  }
  delay(30);                                     // 延遲30毫秒來查看效果
}

