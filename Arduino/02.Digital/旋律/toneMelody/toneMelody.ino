/*
  旋律

 彈一個旋律

 circuit:
 * 8-ohm 揚聲器連接到引腳 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

*/
#include "pitches.h"

int melody[] = {                                                              // 音調放在 melody
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {                                                       // 音符持續時間: 4 = 四分音符, 8 = 八分音符等等
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {                                                                // 遍歷旋律的音符
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    
  /*
    計算音符的持續時間, 用一秒去除音符的種類.
    像四分音符 = 1000 / 4, 八分音符 = 1000/8, 等等.
  */
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    
  /*
    用它們之間的最短時間來區分音符
    音符的持續時間 + 30% 似乎較好:
  */
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);                                                                // 停止播放
  }
}

void loop() {                                                                 // 不需要重複旋律
}
