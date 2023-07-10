int sensor=7; // khai báo rằng ngõ ra cảm biến PIR gắn với chân số 7
int sensor_value; // giá trị sensor_value là giá trị đọc từ cảm biến

void setup(){
  pinMode(sensor,INPUT); // cấu hình chân 7 của Arduino là chân ngõ vào
  Serial.begin(9600); // Khai báo dòng lênh ngày để có thể hiển thị giá trị cảm biến bằng serial monitor
}

void loop(){
  sensor_value=digitalRead(sensor); // lệnh đọc giá trị cảm biến từ chân 7
  Serial.println(sensor_value); // in giá trị ngõ ra ra serial monitor
  delay(1000);
}
