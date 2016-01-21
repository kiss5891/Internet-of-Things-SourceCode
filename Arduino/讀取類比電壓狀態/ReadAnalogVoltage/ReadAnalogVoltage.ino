/*
  讀取類比電壓狀態
  在 A0 讀取類比輸入, 將它轉成電壓, 並輸出結果到 serial monitor.
  圖形表示可使用 serial plotter (Tools > Serial Plotter menu)
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
  // 讀取類比 (從 0 - 1023) 轉換成電壓 (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // 印出讀取的值:
  Serial.println(voltage);
}
