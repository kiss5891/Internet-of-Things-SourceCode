/*
  超級 analogWrite() 測試

  控制 LED 亮度並從引腳 2 到 13 變動.
  這個 sketch 是為 Arduino Mega 寫的, 且不會對電路板做事.

  電路:
  * LED 連接引腳 2 到 13 和 ground.

  created 8 Feb 2009
  by Tom Igoe

  This example code is in the public domain.

 */
// 這些常數不會改變.  它們用來給引腳當名稱:
const int lowestPin = 2;
const int highestPin = 13;


void setup() {
  // 設置引腳 2 到 13 為輸出:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // 循環引腳:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    // 控制 thisPin 的 LED 亮度從暗到亮:
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(thisPin, brightness);
      delay(2);
    }
    // 控制 thisPin 的 LED 亮度從亮到暗:
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(thisPin, brightness);
      delay(2);
    }
    // LED 之間暫停:
    delay(100);
  }
}
