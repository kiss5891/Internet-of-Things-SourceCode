/*
 按鈕

 按一個連接到引腳 2 的按鈕, 打開和關閉一個連接到引腳 13 的發光二極管(LED).


 電路:
 * LED 燈連接到引腳 13 和 ground
 * 按鈕連接從 +5V 到引腳 2 
 * 10K 電阻連接從 ground 到引腳 2

 * 注: 在大多數的 Arduino, 已經有 LED 連接到引腳 13


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

const int buttonPin = 2;     // 這個數字是按鈕的引腳
const int ledPin =  13;      // 這個數字是 LED 的引腳

int buttonState = 0;         // 變數用來讀取按鈕狀態

void setup() {
  pinMode(ledPin, OUTPUT);                // 初始化 ledPin 作為輸出
  pinMode(buttonPin, INPUT);              // 初始化 buttonPin 作為輸入
}

void loop() {
  buttonState = digitalRead(buttonPin);   // 讀取按鈕值的狀態

/*
  檢查如果按下按鈕.
  如果是, 則 buttonState 為 HIGH
*/
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);           // LED 亮
  } else {
    digitalWrite(ledPin, LOW);            // LED 暗
  }
}
