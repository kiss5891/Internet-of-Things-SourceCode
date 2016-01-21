/*
  讀取類比腳位狀態
  在 A0 讀取類比輸入, 印出結果到 Serial Monitor.
  將可變電阻的中心腳連接 A0, 外部腳接到 +5V 和 ground.
　
 這個例子的程式碼在公共領域.
 */

// 當你按下 reset 設置程序運行一次:
void setup() {
  // 初始化序列通訊為 9600bps:
  Serial.begin(9600);
}

// 重複運行循環程序:
void loop() {
  // 讀取輸入在 A0:
  int sensorValue = analogRead(A0);
  // 印出讀取的值:
  Serial.println(sensorValue);
  delay(1);        // 延遲讀取來維持穩定
}
