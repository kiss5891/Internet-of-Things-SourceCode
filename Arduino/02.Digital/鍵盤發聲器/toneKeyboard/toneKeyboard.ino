/*
 鍵盤發聲器

 不斷改變類比輸入來播放改變高音

 電路:
 * 3 個壓力感測器連接從 +5V 和 A0 到 A5
 * 3 個 10K 電阻連接從 A0 到 A5 和 ground
 * 8-ohm 揚聲器連接引腳 8

 created 21 Jan 2010
 modified 9 Apr 2012
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone3

*/

#include "pitches.h"

const int threshold = 10;                                        // 生成一個數為感測器的最小讀數

int notes[] = {                                                  // notes 相當於三個感測器
  NOTE_A4, NOTE_B4, NOTE_C3
};

void setup() {
}

void loop() {
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
    int sensorReading = analogRead(thisSensor);                 // 得到一個感測器的讀數
    if (sensorReading > threshold) {                            // 如果感測器讀到的值夠大
      tone(8, notes[thisSensor], 20);                           // 播放其屬的音調
    }
  }
}
