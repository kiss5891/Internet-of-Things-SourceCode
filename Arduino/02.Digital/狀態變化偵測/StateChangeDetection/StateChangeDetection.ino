/*
  狀態變化偵測 (邊緣偵測)

 通常你不需要知道數字引腳輸入的狀態,
 但你需要知道輸入狀態改變.
 例如, 你想知道按鈕從 OFF 改變成 ON. 
 這就被稱為狀態變化偵測, 或邊緣偵測.

 這個例子顯示當按鈕改變要如何偵測.

 電路:
 * 按鈕連接從 +5V 引腳 2
 * 10K 電阻連接從 ground 到引腳 2 
 * LED 連接從引腳 13 到 ground (或使用大多數 Arduino 的內建 LED)

 created  27 Sep 2005
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/ButtonStateChange

 */

// this constant won't change:
const int  buttonPin = 2;    // 按鈕連接的引腳
const int ledPin = 13;       // LED 連接的引腳

// Variables will change:
int buttonPushCounter = 0;   // 計算按了幾次按鈕
int buttonState = 0;         // 記錄按鈕狀態
int lastButtonState = 0;     // 按鈕上一個狀態

void setup() {
  // 初始化按鈕引腳作為輸入:
  pinMode(buttonPin, INPUT);
  // 初始化 LED 引腳作為輸出:
  pinMode(ledPin, OUTPUT);
  // 初始化序列通訊:
  Serial.begin(9600);
}


void loop() {
  // 讀取 buttonPin:
  buttonState = digitalRead(buttonPin);

  // 比較按鈕當前和以前狀態
  if (buttonState != lastButtonState) {
    // 如果狀態被改變, 增加計數
    if (buttonState == HIGH) {
      // 如果當前狀態是 HIGH 則按鈕從 off 到 on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } else {
      // 如果當前狀態是 LOW 則按鈕從 on 到 off:
      Serial.println("off");
    }
    // 延遲一下下避免反彈
    delay(50);
  }
  // 為了下一次的迴圈, 儲存按鈕上一個狀態,
  lastButtonState = buttonState;


  // 藉由檢查模擬按下按鈕的計數, 每按四次就打開 LED.
  // 這個模擬功能提供了兩個數字相除的餘數:
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}









