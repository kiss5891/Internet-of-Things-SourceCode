/*
  Reading a serial ASCII-encoded string.

 這個程式碼展示 Serial.parseInt() 的功能.
 它給 comma-separated ASCII 的值.
 parsesInt 成整數, 並控制 RGB LED 亮度.

 電路: Common-anode RGB LED 接線像是:
 * Red 負極: 引腳 3
 * Green 負極: 引腳 5
 * blue 負極: 引腳 6
 * 正極: +5V

 created 13 Apr 2012
 by Tom Igoe

 This example code is in the public domain.
 */

// pins for the LEDs:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  while (Serial.available() > 0) {                  // 當有接到到值
    int red = Serial.parseInt();                    // 找輸入的有效整數
    int green = Serial.parseInt();
    int blue = Serial.parseInt();

    if (Serial.read() == '\n') {                    // 尋找句子結尾的換行
      red = 255 - constrain(red, 0, 255);           // 限制範圍在 0 - 255 
      green = 255 - constrain(green, 0, 255);
      blue = 255 - constrain(blue, 0, 255);

      analogWrite(redPin, red);                     // 控制 red 的亮度
      analogWrite(greenPin, green);                 // 控制 green 的亮度
      analogWrite(bluePin, blue);                   // 控制 blue 的亮度

      Serial.print(red, HEX);                       // 印出 red 的十六進位
      Serial.print(green, HEX);                     // 印出 green 的十六進位
      Serial.println(blue, HEX);                    // 印出 blue 的十六進位
    }
  }
}

