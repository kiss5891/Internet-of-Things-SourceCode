/* 無延遲霹靂燈

 打開和關閉一個發光二極管 (LED) 連接到一個數字腳, 不使用 delay(). 
 這意味其他程式碼可以同時運行不會被 LED 程式碼中斷.

 電路:
 * LED 連接引腳 13 到 ground.
 * 注: 在大多數的 Arduino, 已經有 LED 連接到引腳 13, 所以這個例子不一定是必要的.

 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified 11 Nov 2013
 by Scott Fitzgerald


 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

const int ledPin =  13;                                     // 這個號碼是 LED 的引腳

int ledState = LOW;                                         // ledState 用來設置 LED

/*
  通常, 你應該使用 "unsigned long" 為變數保持時間
  這個值很快會儲存成一個太大的 int
*/
unsigned long previousMillis = 0;                           // 將儲存最後一次 LED 被更新

const long interval = 1000;                                 // interval 代表閃爍一次 (毫秒)

void setup() {
  pinMode(ledPin, OUTPUT);                                  // 設置引腳為輸出
}

void loop() {
/*
  這裡放你全部需要運行的程式碼.
    
  檢查看看 LED 燈是不是時後閃爍; 那就是說,
  如果當前時間比上一次閃爍時間更大
  該時間要讓 LED 燈閃爍
*/
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;                         // 保存最後一次閃爍LED的時間
    if (ledState == LOW) {                                  // 如果 LED 燈熄滅就打開, 反之亦然
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);                         // 設置 LED 和可變 ledState
  }
}

