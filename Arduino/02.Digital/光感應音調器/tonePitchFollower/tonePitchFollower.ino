/*
 光感應音調器

 根據改變的類比輸入撥放音調的改變
 
 電路:
 * 8-ohm 撥放器連接引腳 9
 * 光敏電阻連接 A0 和 5V
 * 4.7K 電阻連接 A0 和 ground

 created 21 Jan 2010
 modified 31 May 2012
 by Tom Igoe, with suggestion from Michael Flynn

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone2

*/


void setup() {
  Serial.begin(9600);                     // 初始化序列通訊 (調試用)
}

void loop() {
  int sensorReading = analogRead(A0);     // 讀取 A0
  Serial.println(sensorReading);          // 印出讀取的數讓你知道它的範圍
  
/*
  map 類比輸入範圍 (在此情況下, 光敏電阻從 400 - 1000)
  以輸出音調範圍 (120 - 1500Hz)
  改變最小和最大的輸入數, sensor 取決於這個範圍:
*/
  int thisPitch = map(sensorReading, 400, 1000, 120, 1500);
  tone(9, thisPitch, 10);                 // 撥放音調
  delay(1);                               // 延遲讀取以維持穩定
}






