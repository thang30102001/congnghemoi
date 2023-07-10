int PIRPin = 12;        // chân PIR
int pirState = LOW;     // Bắt đầu với không có báo động
int val;
int pinSpeaker = 13;    // chân còi
 
void setup()
{
  pinMode(PIRPin, INPUT);
  pinMode(pinSpeaker, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  val = digitalRead(PIRPin);    // đọc giá trị đầu vào.
  if (val == HIGH)              // nếu giá trị ở mức cao.(1)
  {
    playTone(300, 200);          // phát 200Hz trong 300ms
    delay(1000);
 
    if (pirState == LOW)
    {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  }
  else
  {
    playTone(0, 0);
    delay(1000);
    if (pirState == HIGH)
    {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
 
void playTone(long duration, int freq)
{
  duration *= 1000;
  int period = (1.0 / freq) * 1000000;
  long elapsed_time = 0;
  while (elapsed_time < duration)
  {
    digitalWrite(pinSpeaker,HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(pinSpeaker, LOW);
    delayMicroseconds(period / 2);
    elapsed_time += (period);
  }
}
