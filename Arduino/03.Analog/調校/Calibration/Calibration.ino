/*
  調校

 示範一種類比零件輸入的校正技術.  
 在系統開始後的5秒內調整元件的最小值和最大值

 最小或最大值, 以反向做調校.
 最初, 你設置最低高度若讀取的值比它小, 那就將最小值設為讀取值. 
 如此一來, 當將類比零件調小值時, 最小值就會慢慢更新, 直到它讀到的最小值.
 同樣, 最大值也是以類似的方式做調校.

 電路:
 * 類比零件 (可變電阻也可) 連接 A0
 * LED 連接到引腳 9 和 ground

 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Calibration

 This example code is in the public domain.

 */

const int sensorPin = A0;    // 類比零建連接到這個引腳
const int ledPin = 9;        // LED 連接到這個引腳

int sensorValue = 0;         // 類比零件的值
int sensorMin = 1023;        // 最小值
int sensorMax = 0;           // 最大值

void setup() {
  pinMode(13, OUTPUT);                                              // 將 LED 打開, 以告知開始進行調校
  digitalWrite(13, HIGH);

  while (millis() < 5000) {                                         // 在五秒內進行調校
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorMax) {                                      // 記錄最大值
      sensorMax = sensorValue;
    }
    if (sensorValue < sensorMin) {                                      // 記錄最小值
      sensorMin = sensorValue;
    }
  }
  digitalWrite(13, LOW);                                            // 調校結束
}

void loop() {
  sensorValue = analogRead(sensorPin);                              // 讀取類比零件
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);     // 調校應用到類比零件讀數上
  sensorValue = constrain(sensorValue, 0, 255);                     // 避免類比零件的值在調校範圍外
  analogWrite(ledPin, sensorValue);                                 // 以調校後的值點亮 LED
}
