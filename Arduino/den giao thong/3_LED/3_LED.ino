int led_xanh = 11;
int led_do = 12;
int led_vang = 13;
void setup()
{
  pinMode(led_xanh, OUTPUT);
  pinMode(led_vang, OUTPUT);
  pinMode(led_do, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(led_xanh, HIGH);
  Serial.print("Led Xanh sang\n");
  digitalWrite(led_vang, LOW);
  digitalWrite(led_do, LOW);
  delay(6000); 
  
  digitalWrite(led_vang, HIGH);
  Serial.print("Led Vang sang\n");
    digitalWrite(led_xanh, LOW);
  digitalWrite(led_do, LOW);
  delay(3000);

  digitalWrite(led_do, HIGH);
  Serial.print("Led Do sang\n");
  digitalWrite(led_xanh, LOW);
  digitalWrite(led_vang, LOW); 
  delay(4000);
}
