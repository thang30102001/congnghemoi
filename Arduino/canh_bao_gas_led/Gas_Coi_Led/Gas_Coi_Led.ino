int buzzer = 10;      //khai báo chân 10 của còi
int ledxanh = 11;     //khai báo chân 11 của led
int leddo=12; 
int Value; 
int nguong_canh_bao = 150;

void setup()
{
  pinMode(ledxanh, OUTPUT);
  pinMode(leddo, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);           //Mở cổng Serial tại port 9600
}
void loop()
{
  Value = analogRead(A0);      //đọc giá trị điện áp ở chân Analog A0, còn ở chân Digital(Ax) là DigitalRead(ten_bien)
  Serial.print("Value: ");
  Serial.print(Value);
    
  if(Value > nguong_canh_bao)
  {
    Serial.print("\nGia tri vuot nguong canh bao 150, Phat hien  khi gas !!!\n");
    digitalWrite(leddo, HIGH);
    delay(1000);
    digitalWrite(leddo, LOW);
    delay(1000);
    tone(buzzer, 1000, 5000);                   //bật còi báo động, 1000 là tần số, 500 là t/g phát báo động
  }
  else
  {
    Serial.print("\nKhoong phat hien khi gas\n");
    digitalWrite(ledxanh, HIGH);
    noTone(buzzer);                            //tắt còi báo động

  }
  delay(3000); 
}
