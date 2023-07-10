#include "DHT.h"             //khai báo thư viện DHT
const int DHTPIN = 10;       //Đọc dữ liệu từ DHT11 ở chân 10 trên mạch Arduino
const int DHTTYPE = DHT11;   //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
int led_xanh = 2;
int led_vang = 3;
int led_do = 4;
int buzzer = 9;             //khai báo chân 10 của còi

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(led_xanh, OUTPUT);
  pinMode(led_vang, OUTPUT);
  pinMode(led_do, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(led_vang, LOW);
  digitalWrite(led_xanh, LOW);
  digitalWrite(led_do, LOW);
  Serial.begin(9600);        //mở serial tại port 9600
  dht.begin();               //Khởi động cảm biến
}
 
void loop() {
  float h = dht.readHumidity();    //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ
  Serial.print("Nhiet do: ");
  Serial.println(t);               //Xuất nhiệt độ

  if(t<20){
    digitalWrite(led_xanh, HIGH);  
    digitalWrite(led_vang, LOW);
    digitalWrite(led_do, LOW);
    noTone(buzzer);            //tắt còi báo động

  }else if(t>=20 && t<25){
    digitalWrite(led_vang, HIGH);
    digitalWrite(led_xanh, LOW);
    digitalWrite(led_do, LOW);
    noTone(buzzer);            //tắt còi báo động

  }else if(t>=25){
    digitalWrite(led_do, HIGH);
    digitalWrite(led_xanh, LOW);
    digitalWrite(led_vang, LOW);
    tone(buzzer, 1000, 500);         //bật còi báo động, 1000 là tần số, 500 là t/g phát báo động
  }

  Serial.print("Do am: ");
  Serial.println(h);               //Xuất độ ẩm
  Serial.println();                
  delay(4000);                     //thời gian lấy mẫu dữ liệu là 4s
}
