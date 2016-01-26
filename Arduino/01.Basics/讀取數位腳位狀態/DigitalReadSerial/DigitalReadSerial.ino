/*
 讀取數位腳位狀態
 讀取腳位 2 當輸入,列印結果到 serial monitor

 這個範例程式碼是在公共區域.
 */

int pushButton = 2;       // 數字腳位 2 連接到一個按鈕. 給他一個名字
void setup() {            // 當按下 reset 設置例行程式並運行一次
  Serial.begin(9600);                         // 初始化序列通訊為 9600 bps
  pinMode(pushButton, INPUT);                // 設定按鈕為輸入
}

void loop() {             // 這個循環回圈會不斷的重複
  int buttonState = digitalRead(pushButton); // 讀取輸入腳位
  Serial.println(buttonState);                // 印出按鈕狀態
  delay(1);                                  // 延遲讀取來維持穩定
}



