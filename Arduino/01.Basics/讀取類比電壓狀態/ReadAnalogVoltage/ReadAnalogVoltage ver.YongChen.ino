/*
  讀取數位電壓
  讀取 pin 0 所讀到的類比數值, 把它轉換成電壓 , 並打印結果在 serial monitor 上
  將可變電阻中間的腳接到 A0, 外面的兩隻腳接到 +5V 跟地。
 
 這個範例程式碼是屬於公開的。
 */


void setup() {                                                   // setup 函數當程式開始執行或重新設定時只會跑一次

  Serial.begin(9600);                                            // 註冊一個Serial 9600
}

void loop() {                                                    // loop 函數會不斷的循環執行
 
  int sensorValue = analogRead(A0);                              // 讀取類比輸入腳 A0 的值，並丟給 sensorValue
  float voltage = sensorValue * (5.0 / 1023.0);                  // 將類比輸入的值 (0 - 1023) 轉換成電壓 (0 - 5V) 並丟給 voltage
  Serial.println(voltage);                                       // 打印出 voltage 數值
}
