/*
  讀取類比腳位狀態
  在 A0 讀取類比輸入, 印出結果到 Serial Monitor.
  將可變電阻的中心腳連接 A0, 外部腳接到 +5V 和 ground.
　
 This example code is in the public domain.
 */

void setup() {              // 當你按下 reset 設置程序運行一次
  Serial.begin(9600);                // 初始化序列通訊為 9600bps
}

void loop() {               // 重複運行循環程序
  int sensorValue = analogRead(A0); // 讀取輸入在 A0
  Serial.println(sensorValue);       // 印出讀取的值
  delay(1);                         // 延遲讀取來維持穩定
}
