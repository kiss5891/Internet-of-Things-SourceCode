/*
  類比輸入
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 電路:
 * 可變電阻中心引腳連接 A0
 * 外部引腳連接 ground 和 +5V
 * LED 長腳連接引腳 13
 * LED 短腳連接 ground

 * 注: 大多數 Arduino 有一個內建的 LED 連接到主板上的引腳 13 .


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

int sensorPin = A0;    // 選擇可變電阻的輸入引腳
int ledPin = 13;      // 選擇 LED 的引腳
int sensorValue = 0;  // 變數用來儲存 sensor 的值

void setup() {
  // 宣告 ledPin 為 OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 從 sensor 讀取值:
  sensorValue = analogRead(sensorPin);
  // 讓 ledPin 亮
  digitalWrite(ledPin, HIGH);
  // 停止 <sensorValue> 毫秒:
  delay(sensorValue);
  // 讓 ledPin 暗:
  digitalWrite(ledPin, LOW);
  // 停止 <sensorValue> 毫秒:
  delay(sensorValue);
}
