/*
 開關

 每次輸入引腳從 LOW 到 HIGH (例如因為按下一個按鈕),
 輸出引腳為低電壓從 LOW 到 HIGH 或從 HIGH 到 LOW.
 有一個最小延遲在切換開關電路(即忽略 noise).

 電路:
 * LED 連接引腳 13 到 ground
 * 按鈕連接引腳 2 到 +5V
 * 10K 電阻連接引腳 2 到 ground

 * 注: 在大多數的 Arduino, 已經有 LED 連接到引腳 13, 所以這個例子不一定是必要的.


 created 21 November 2006
 by David A. Mellis
 modified 30 Aug 2011
 by Limor Fried
 modified 28 Dec 2012
 by Mike Walters

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Debounce
 */

// 常數不會改變. 用來設置引腳號碼.
const int buttonPin = 2;    // 這個數字是按鈕的引腳
const int ledPin = 13;      // 這個數字是 LED 的引腳

// 變數將改變:
int ledState = HIGH;         // 輸出引腳的當前狀態
int buttonState;             // 從輸入引腳讀取當前的數
int lastButtonState = LOW;   // 從輸入引腳讀取過去的數

// 因為是時間以下的變數是以毫秒為單位的 long,
// 將很快變成更大的數, 可以被儲存在 int.
long lastDebounceTime = 0;  // 在最後一次, 輸出引腳被切換
long debounceDelay = 50;    // 開關時間; 如果輸出閃爍就增加

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // 初始化 LED 狀態
  digitalWrite(ledPin, ledState);
}

void loop() {
  // 讀取開關狀態到一個變數:
  int reading = digitalRead(buttonPin);

  // 檢查如果你只是按按鈕(輸入從 LOW 到 HIGH),
  // 且你已經從上一次按按鈕到忽略 noise 之間等很久:

  // 如果開關改變, 由於 noise 或按按鈕:
  if (reading != lastButtonState) {
    // 重新設定開關時間
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // 無論讀數多少, 它已經比開關延遲的時間更長
    // 因此把它當作實際的當前狀態:

    // 如果按鈕狀態被改變:
    if (reading != buttonState) {
      buttonState = reading;

      // 如果新的按鈕狀態是 HIGH 就只改變 LED
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // 設置 LED:
  digitalWrite(ledPin, ledState);

  // 保存讀數.  下一次通過循環回圈,它就是 lastButtonState:
  lastButtonState = reading;
}

