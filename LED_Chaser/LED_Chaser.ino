//For More Info : https://albtronics.wordpress.com/

#define t   30
#define t1  20
#define t2  100
#define t3  50
void setup() {
  // set up pins 2 to 13 as outputs
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
}
/////////////////////////////////////////////////////////////////////////////////mode 1
void loop() {

  mode_1();
  mode_1();

  mode_2();
  mode_2();

  mode_3();
  mode_3();

  mode_4();
  mode_4();

  mode_5();
  mode_5();

  mode_6();
  mode_6();

  mode_7();
  mode_7();
}
//left to right and right to left
void mode_1()
{
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
    delay(t1);
    digitalWrite(i + 1, LOW);
    delay(t1);
    digitalWrite(i + 2, LOW);
    delay(t1);
    digitalWrite(i, HIGH);
    delay(t1);
    digitalWrite(i + 1, HIGH);
    delay(t1);
  }
  for (int i = 9; i > 1; i--) {
    digitalWrite(i, LOW);
    delay(t1);
    digitalWrite(i - 1, LOW);
    delay(t1);
    digitalWrite(i - 2, LOW);
    delay(t1);
    digitalWrite(i, HIGH);
    delay(t1);
    digitalWrite(i - 1, HIGH);
    delay(t1);
  }
}
/////////////////////////////////////////////////////////////////////////////////mode 2
void mode_2()
{
  int count = 9; // keeps track of second LED movement

  // move first LED from left to right and second from right to left
  for (int i = 2; i < 9; i++) {
    clear();
    digitalWrite(i, LOW);      // chaser 1
    digitalWrite(count, LOW); // chaser 2
    count--;
    // stop LEDs from appearing to stand still in the middle
    if (count != 7) {
      delay(t2);
    }
  }

  // move first LED from right to left and second LED from left to right
  for (int i = 9; i > 2; i--) {
    clear();
    digitalWrite(i, LOW);      // chaser 1
    digitalWrite(count, LOW); // chaser 2
    count++;
    // stop LEDs from appearing to stand still in the middle
    if (count != 8) {
      delay(t2);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////mode 3

void mode_3()
{
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, LOW);
    delay(t3);
  }
  for (int i = 2; i < 10; i++) {
    digitalWrite(i, HIGH);
    delay(t3);
  }


  for (int i = 9; i >= 2; i--) {
    digitalWrite(i, LOW);
    delay(t3);
  }
  for (int i = 9; i >= 2; i--) {
    digitalWrite(i, HIGH);
    delay(t3);
  }
}
///////////////////////////////////////////////////////////////////////////mode 4
void mode_4()
{
  for (int j = 2; j <= 9; j++) {
    digitalWrite(j, LOW);
    delay(t2);
    j = j + 1;
  }
  for (int j = 2; j <= 9; j++) {
    digitalWrite(j, HIGH);
    delay(t2);
  }

  for (int k = 9; k > 2; k--) {
    digitalWrite(k, LOW);
    delay(t2);
    k = k - 1;
  }
  for (int k = 9; k > 2; k--) {
    digitalWrite(k, HIGH);
    delay(t2);
  }
}
//////////////////////////////////////////////////////////////////////////////mode 5
void mode_5()
{
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin, LOW);
    delay(t1);
    digitalWrite(pin + 1, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 1, LOW);
    delay(t1);
    digitalWrite(pin + 2, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 2, LOW);
    delay(t1);
    digitalWrite(pin + 3, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 3, LOW);
    delay(t1);
    digitalWrite(pin + 4, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 4, LOW);
    delay(t1);
    digitalWrite(pin + 5, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 5, LOW);
    delay(t1);
    digitalWrite(pin + 6, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 6, LOW);
    delay(t1);
    digitalWrite(pin + 7, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 7, LOW);
    delay(t1);
    digitalWrite(pin + 8, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 8, LOW);
    delay(t1);
    digitalWrite(pin + 9, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 9, LOW);
    delay(t1);
    digitalWrite(pin + 10, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 10, LOW);
    delay(t1);
    digitalWrite(pin + 11, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 11, LOW);
    delay(t1);
    digitalWrite(pin + 12, HIGH);
    delay(t1);
  }
  for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 12, LOW);
    delay(t1);
    digitalWrite(pin + 13, HIGH);
    delay(t1);
  } for (int pin = 9; pin >= 2; pin--)
  {
    digitalWrite(pin + 13, LOW);
    delay(t1);
    digitalWrite(pin, HIGH);
  }
}
/////////////////////////////////////////////////////////////////////////////mode 6
void mode_6()
{
  for (int j = 2; j < 10; j++) {
    digitalWrite(j, HIGH);
    delay(t);
    digitalWrite(j, LOW);
    delay(t);
    digitalWrite(j - 2, HIGH);
    delay(t);
    digitalWrite(j, LOW);
  }
  for (int k = 9; k > 2; k--) {
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k + 2, HIGH);
    delay(t);
    digitalWrite(k, LOW);
  }
  for (int k = 2; k < 10; k++) {
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k - 2, HIGH);
    delay(t);
    digitalWrite(k, LOW);
  }
  for (int k = 9; k > 2; k--) {
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k + 4, HIGH);
    delay(t);
    digitalWrite(k, LOW);
  }
  for (int k = 2; k < 10; k++) {
    digitalWrite(k, HIGH);
    delay(t);
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k - 4, HIGH);
    delay(t);
    digitalWrite(k, LOW);
  }
}
///////////////////////////////////////////////////////////////////////////////////mode 7
void mode_7()
{
  for (int j = 2; j < 10; j++) {
    digitalWrite(j, LOW);
    delay(t);
    digitalWrite(j + 2, HIGH);
    delay(t);
  }
  for (int k = 9; k > 2; k--) {
    digitalWrite(k, LOW);
    delay(t);
    digitalWrite(k + 2, HIGH);
    delay(t);
  }
}

// function to switch all LEDs off
void clear(void)
{
  for (int i = 2; i <= 10; i++) {
    digitalWrite(i, HIGH);
  }
}
