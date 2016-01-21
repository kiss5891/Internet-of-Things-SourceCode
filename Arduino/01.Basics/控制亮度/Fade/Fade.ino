/*
 Fade

 這個例子說明如何使用 analogWrite() 控制 LED 亮度在腳位 9

 這個範例程式碼是在公共區域.
 */

int led = 9;           // 讓 LED 接到腳位
int brightness = 0;    // LED 有多亮
int fadeAmount = 5;    // LED 如何變暗

// 當按下 reset 設置例行程式並運行一次:
void setup() {
  // 設置腳位 9 為輸出:
  pinMode(led, OUTPUT);
}

// 這個循環回圈會不斷的重複:
void loop() {
  // 設置腳位 9 的亮度:
  analogWrite(led, brightness);

  // 用循環改變下一次的亮度:
  brightness = brightness + fadeAmount;

  // 在最亮或最暗的時候改變方向:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // 延遲30毫秒來查看效果
  delay(30);
}

