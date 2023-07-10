int SignalPin = 2;   // Connect the signal pin of IR module to the D2 pin of Arduino 
void setup() {
  pinMode(SignalPin, INPUT); // Initialize D2 as an INput pin
  Serial.begin(9600); 
}
int Object = HIGH;
void loop() {
  Object = digitalRead(SignalPin);
  if (Object == LOW)
  {
    Serial.println("Object Not Found"); // If there is nothing in its path
    delay(200);
  }
  else
  {
    Serial.println("Obstacle Found"); //If there is obstacle 
  }
  delay(100);
}
