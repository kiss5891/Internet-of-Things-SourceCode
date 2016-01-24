/*

  平滑

  讀取多次類比輸入, 計算平均並印在電腦上.  
  10 個讀數將它們不斷地平均.

  電路:
    * 類比零件 (可變電阻也可) 連接 A0

  Created 22 April 2007
  By David A. Mellis  <dam@mellis.org>
  modified 9 Apr 2012
  by Tom Igoe
  http://www.arduino.cc/en/Tutorial/Smoothing

  This example code is in the public domain.


*/


// 定義樣本數量來記錄.  數字越高, 讀數將越被平滑處理, 
// 但輸出回應輸入較慢.  使用常數而不是一個正常的變數
// 使用這個值來確定讀數組數.
const int numReadings = 10;

int readings[numReadings];      // 從類比輸入讀取
int readIndex = 0;              // 當前讀數的指標
int total = 0;                  // 所有讀數的和
int average = 0;                // 平均

int inputPin = A0;

void setup() {
  // 初始化序列通訊:
  Serial.begin(9600);
  // 所有數設為 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // 減掉上一次讀取的值:
  total = total - readings[readIndex];
  // 讀取感應的值:
  readings[readIndex] = analogRead(inputPin);
  // 增加到總合:
  total = total + readings[readIndex];
  // 前進到陣列中的下一個位置:
  readIndex = readIndex + 1;

  // 如果我們在數組的最後...
  if (readIndex >= numReadings) {
    // ...環繞到一開始:
    readIndex = 0;
  }

  // 計算平均:
  average = total / numReadings;
  // 以 ASCII 碼送到電腦
  Serial.println(average);
  delay(1);        // 延遲讀取來維持穩定
}


