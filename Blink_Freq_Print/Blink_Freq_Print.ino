//For More Info Visit: https://albtronics.wordpress.com/
float X = 555, f;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(X);
  digitalWrite(LED_BUILTIN, LOW);
  delay(X);
  f = ((1 / X) * 1000); // T is in ms
  Serial.print("\nFrequency = ");
  Serial.print(f);
  Serial.print("Hz");
}
