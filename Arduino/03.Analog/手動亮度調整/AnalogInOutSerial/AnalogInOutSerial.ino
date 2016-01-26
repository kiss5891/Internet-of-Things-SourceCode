/*
  類比輸入, 類比輸出, 序列輸出

 讀取類比輸入引腳, maps 結果範圍從 0 到 255
 並使用這個結果設置輸出引腳的脈衝寬度調變 (PWM).
 同時印出結果到 serial monitor.

 電路:
 * 可變電阻中心引腳連接到 A0.
   外部引腳連接到 +5V 和 ground
 * LED 連接引腳 9 和 ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

const int analogInPin = A0;   // 可變電阻連接類比輸出引腳
const int analogOutPin = 9;   // LED 連接類比輸出引腳

int sensorValue = 0;          // 從 pot 讀取的值
int outputValue = 0;          // 從 PWM 輸出的值 (類比輸出)

void setup() {
  Serial.begin(9600);                                  // 初始化序列通訊為 9600 bps
}

void loop() {
  sensorValue = analogRead(analogInPin);              // 讀取類比的值
  outputValue = map(sensorValue, 0, 1023, 0, 255);    // map 類比輸出的範圍
  analogWrite(analogOutPin, outputValue);             // 改變類比輸出的值
  
  Serial.print("sensor = ");                           // 列印結果到 serial monitor
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

/*
  在下一個迴圈之前等待 2 毫秒
  用於在上次讀取之後類比數字轉換的安定
*/
  delay(2);
}
