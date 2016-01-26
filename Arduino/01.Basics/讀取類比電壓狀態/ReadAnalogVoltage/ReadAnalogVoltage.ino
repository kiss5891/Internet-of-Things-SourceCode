/*
  讀取類比電壓狀態
  在 A0 讀取類比輸入, 將它轉成電壓, 並輸出結果到 serial monitor.
  圖形表示可使用 serial plotter (Tools > Serial Plotter menu)
  將可變電阻的中心腳連接 A0, 外部腳接到 +5V 和 ground.

  這個例子的程式碼在公共領域.
*/

void setup() {                                        // 當你按下 reset 設置程序運行一次
  Serial.begin(9600);                                 // 初始化序列通訊為 9600bps
}

void loop() {                                         // 重複運行循環程序
  int sensorValue = analogRead(A0);                   // 讀取輸入在 A0:
  float voltage = sensorValue * (5.0 / 1023.0);       // 讀取類比 (從 0 - 1023) 轉換成電壓 (0 - 5V)
  Serial.println(voltage);                            // 印出讀取的值
}
