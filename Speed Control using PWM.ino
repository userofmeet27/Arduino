int motorValue;
int potValue;
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
}
void loop()
{
  potValue = analogRead (0);
  motorValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(9, motorValue);
  digitalWrite(6, LOW);
}
