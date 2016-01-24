/*
 漸暗漸亮

 這個例子透過　analogWrite() 讓　LED 漸暗漸亮.

 電路:
 * LED 連接到引腳 9 和 ground.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */


int ledPin = 9;    // LED 連接到引腳 9

void setup() {
  // 沒有事情發生在 setup
}

void loop() {
  // 從最小到最大, 每次增加 5:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // 設一個值 (範圍從 0 到 255):
    analogWrite(ledPin, fadeValue);
    // 等待 30 毫秒來觀看效果
    delay(30);
  }

  // 由最大到最小, 每次減少 5:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // 設一個值 (範圍從 0 到 255):
    analogWrite(ledPin, fadeValue);
    // 等待 30 毫秒來觀看效果
    delay(30);
  }
}


