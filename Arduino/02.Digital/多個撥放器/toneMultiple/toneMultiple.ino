/*
 多個撥放器

 播放多種音調在不同的揚聲器

 circuit:
 * 3 8-ohm 揚聲器連接引腳 6, 7, 和 8

 created 8 March 2010
 by Tom Igoe
 based on a snippet from Greg Borenstein

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone4

 */

void setup() {
}

void loop() {
  noTone(8);              // 關閉引腳 8 的旋律
  tone(6, 440, 200);      // 播放引腳 6 的一個旋律 200 毫秒
  delay(200);
  
  noTone(6);              // 關閉引腳 6 的旋律
  tone(7, 494, 500);      // 播放引腳 7 的一個旋律 500 毫秒
  delay(500);

  noTone(7);              // 關閉引腳 7 的旋律
  tone(8, 523, 300);      // 播放引腳 8 的一個旋律 500 毫秒
  delay(300);
}
