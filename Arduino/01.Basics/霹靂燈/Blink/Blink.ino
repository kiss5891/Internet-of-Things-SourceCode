/*
  霹靂燈
  讓 LED 燈亮一秒再暗一秒,不斷的重複

  大多數的 Arduino 都有 on-board LED 你可以去控制它.
  在 Uno 和Leonardo,它是連接到13腳.
  如果你不確定你的 Arduino 型號的哪隻腳位連接到 on-board LED,
  查詢文件在 http://www.arduino.cc

  這個範例程式碼是在公共區域.

  在2014年5月8日
  由 Scott Fitzgerald 修改
 */


// 當按下 reset 或是 power the board 執行一次運行功能
void setup() {
  // 初始化將13腳設為輸出
  pinMode(13, OUTPUT);
}

// 這個重複迴圈會不斷運行
void loop() {
  digitalWrite(13, HIGH);   // 讓 LED 亮 (HIGH 是電壓提升)
  delay(1000);              // 延遲一秒
  digitalWrite(13, LOW);    // 通過電壓低讓 LED 暗
  delay(1000);              // 延遲一秒
}
