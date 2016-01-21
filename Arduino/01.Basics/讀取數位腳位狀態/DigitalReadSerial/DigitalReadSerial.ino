/*
  讀取數位腳位狀態
 讀取腳位 2 當輸入,列印結果到 serial monitor

 這個範例程式碼是在公共區域.
 */

// 數字腳位 2 連接到一個按鈕. 給他一個名字:
int pushButton = 2;

// 當按下 reset 設置例行程式並運行一次:
void setup() {
  // 初始化序列通訊為 9600 bps:
  Serial.begin(9600);
  // 設定按鈕為輸入:
  pinMode(pushButton, INPUT);
}

// 這個循環回圈會不斷的重複:
void loop() {
  // 讀取輸入腳位:
  int buttonState = digitalRead(pushButton);
  // 印出按鈕狀態:
  Serial.println(buttonState);
  delay(1);        // 延遲讀取來維持穩定
}



