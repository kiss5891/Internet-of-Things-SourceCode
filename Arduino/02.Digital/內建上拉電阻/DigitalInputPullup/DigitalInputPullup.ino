/*
 內建上拉電阻

 這個範例用來示範 pinMode(INPUT_PULLUP). 它會讀取引腳 2 並顯示在 serial monitor.

 電路:
 * 按鈕連接到引腳 2 和 ground
 * 引腳 13 的內建 LED

 不同於 pinMode(INPUT), 沒有必要下拉電阻. 內部20K-ohm 電阻被拉至 5V.
 當開關打開該配置會導致輸入 HIGH, 當開關關閉輸入就是 LOW.

 created 14 March 2012
 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/InputPullupSerial

 This example code is in the public domain

 */

void setup() {
  //啟動序列連接
  Serial.begin(9600);
  //設置引腳 2 為輸入並使用內部上拉電阻
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop() {
  //讀取按鈕狀態儲存到變數
  int sensorVal = digitalRead(2);
  //印出按鈕的值
  Serial.println(sensorVal);

  // 記住 pullup 是按鈕電路被反轉
  // 當它被打開它就是 HIGH, 按下按鈕就是 LOW.
  // 當按下按鈕就打開引腳 13, 反之就是關:
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
  }
}



