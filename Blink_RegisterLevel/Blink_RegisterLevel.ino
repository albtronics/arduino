//For More Info Visit: https://albtronics.wordpress.com/
void setup() {
  // put your setup code here, to run once:
  //DDRD = B00100000;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD = B00100000;
  delay(100);
  PORTD = B00000000;
  delay(100);
}
