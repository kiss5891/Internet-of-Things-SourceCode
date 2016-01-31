/*
 撥放 MIDI 音符

 這小品顯示如何使用序列發送引腳 (引腳 1) 發送 MIDI 音符數據.
 如果電路連接 MIDI 合成器, 它將按順序撥放音符 F#-0 (0x1E) 到 F#-5 (0x5A).


 電路:
 * 引腳 1 連接到 MIDI 接口引腳 5
 * MIDI 接口引腳 2 連接 ground
 * MIDI 接口引腳 4 通過 220-ohm 電阻連接到 +5V
 連接 MIDI 電纜到插座, 然後到 MIDI 合成器, 並撥放音樂.

 created 13 Jun 2006
 modified 13 Aug 2012
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Midi

 */

void setup() {
  Serial.begin(31250);                                        // 設置 MIDI 胞率
}

void loop() {
  for (int note = 0x1E; note < 0x5A; note ++) {               // 撥放音服從 F#-0 (0x1E) 到 F#-5 (0x5A)
    noteOn(0x90, note, 0x45);                                 // 音符通道 1 (0x90), 一些音符值 (note), 中速 (0x45)
    delay(100);
    noteOn(0x90, note, 0x00);                                 // 音符通道 1 (0x90), 一些音符值 (note), 靜音速度 (0x00)
    delay(100);
  }
}

void noteOn(int cmd, int pitch, int velocity) {               // 撥放一個 MIDI 音符. 不檢查 cmd 大於 127, 或數值小於 127
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

