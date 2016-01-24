/*
  ASCII 表

 印出所有字可能的形式:
 * 如原始的二進位
 * 如 ASCII 碼的十進位, 十六進位, 八進位, 二進位

 更多 ASCII, 看 http://www.asciitable.com 和 http://en.wikipedia.org/wiki/ASCII

 電路:  無需外部硬體.

 created 2006
 by Nicholas Zambetti
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 <http://www.zambetti.com>

 */
void setup() {
  //初始化序列和等待開口打開:
  Serial.begin(9600);
  while (!Serial) {
    ; // 等待序列端口連接. 需要 USB 端口
  }

  // 印出標題並換行
  Serial.println("ASCII Table ~ Character Map");
}

// 第一個變數 ASCII 碼 '!' 是數字 33:
int thisByte = 33;
// 你也可以寫 ASCII 碼用單引號
// 例如. '!' 一樣是 33, 所以你可以這樣使用:
//int thisByte = '!';

void loop() {
  // 印出的值不變, 即原始二進位的字.
  // serial monitor 解讀 bytes 為
  // ASCII, 所以 33, 第一個數,  會顯示 '!'
  Serial.write(thisByte);

  Serial.print(", dec: ");
  // 印出的值是 ASCII 十進位的字串 (基數 10).
  // 十進位是 Serial.print() 和 Serial.println() 的默認格式,
  // 所以沒必要修改:
  Serial.print(thisByte);
  // 如果你想你也可以修改為小數.
  // 如果你取消註解:

  // Serial.print(thisByte, DEC);


  Serial.print(", hex: ");
  // 印出十六進位的字串 (基數 16):
  Serial.print(thisByte, HEX);

  Serial.print(", oct: ");
  // 印出八進位的字串 (基數 8);
  Serial.print(thisByte, OCT);

  Serial.print(", bin: ");
  // 印出二進位的字串 (基數 2)
  // 印出結束後換行:
  Serial.println(thisByte, BIN);

  // 如果印出的最後一個字是 '~' 或 126, 就停止:
  if (thisByte == 126) {    // 你也可以使用 if (thisByte == '~') {
    // 這個迴圈會一直什麼都不做的循環
    while (true) {
      continue;
    }
  }
  // 去下一個字符
  thisByte++;
}
