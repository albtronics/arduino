//For More Info : https://albtronics.wordpress.com/
//Lightshow Video : https://www.youtube.com/watch?v=x1RXNMLPP4w
#define t   30
#define t1  20
#define t2  100
#define t3  50
bool LED = true; // [ true for LED and false for RELAY(Active-LOW) ]
void setup() {
  // set up pins 2 to 13 as outputs
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
}
/////////////////////////////////////////////////////////////////////////////////Effect 1
void loop(){

 effect_1();
 effect_1();

 effect_2();
 effect_2();

 effect_3();
 effect_3();

 effect_4();
 effect_4();

 effect_5();
 effect_5();

 effect_6();
 effect_6();

 effect_7();
 effect_7();
  }
//left to right and right to left
void effect_1()
{
for(int i=2; i<10; i++){
digitalWrite(i, LED);
delay(t1);
digitalWrite(i+1, LED);
delay(t1);
digitalWrite(i+2, LED);
delay(t1);
digitalWrite(i, !LED);
delay(t1);
digitalWrite(i+1, !LED);
delay(t1);
}
for(int i=9; i>1; i--){
digitalWrite(i, LED);
delay(t1);
digitalWrite(i-1, LED);
delay(t1);
digitalWrite(i-2, LED);
delay(t1);
digitalWrite(i, !LED);
delay(t1);
digitalWrite(i-1, !LED);
delay(t1);
}
}
/////////////////////////////////////////////////////////////////////////////////Effect 2
void effect_2()
{
int count = 9; // keeps track of second LED movement

  // move first LED from left to right and second from right to left
  for (int i = 2; i < 9; i++) {
    clear();
    digitalWrite(i, LED);      // chaser 1
    digitalWrite(count, LED); // chaser 2
    count--;
    // stop LEDs from appearing to stand still in the middle
    if (count != 7) {
      delay(t2);
    }
  }

  // move first LED from right to left and second LED from left to right
  for (int i = 9; i > 2; i--) {
    clear();
    digitalWrite(i, LED);      // chaser 1
    digitalWrite(count, LED); // chaser 2
    count++;
    // stop LEDs from appearing to stand still in the middle
    if (count != 8) {
      delay(t2);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////Effect 3

void effect_3()
{
for(int i=2; i<10; i++){
  digitalWrite(i, LED);
  delay(t3);
}
for(int i=2; i<10; i++){
  digitalWrite(i, !LED);
  delay(t3);
}


for(int i = 9; i>=2; i--){
  digitalWrite(i, LED);
  delay(t3);
}
for(int i = 9; i>=2; i--){
  digitalWrite(i, !LED);
  delay(t3);
}
}
  ///////////////////////////////////////////////////////////////////////////Effect 4
void effect_4()
{
for(int j = 2; j <= 9; j++){
  digitalWrite(j, LED);
  delay(t2);
  j=j+1;
  }
for(int j = 2; j <= 9; j++){
  digitalWrite(j, !LED);
  delay(t2);
  }

  for(int k = 9; k > 2; k--){
  digitalWrite(k, LED);
  delay(t2);
  k=k-1;
  }
for(int k = 9; k > 2; k--){
  digitalWrite(k, !LED);
  delay(t2);
  }
}
//////////////////////////////////////////////////////////////////////////////Effect 5
  void effect_5()
{
 for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin, LED);
  delay(t1);
  digitalWrite(pin+1, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+1, LED);
  delay(t1);
  digitalWrite(pin+2, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+2, LED);
  delay(t1);
  digitalWrite(pin+3, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+3, LED);
  delay(t1);
  digitalWrite(pin+4, !LED);
  delay(t1);
  }
    for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+4, LED);
  delay(t1);
  digitalWrite(pin+5, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+5, LED);
  delay(t1);
  digitalWrite(pin+6, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+6, LED);
  delay(t1);
  digitalWrite(pin+7, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+7, LED);
  delay(t1);
  digitalWrite(pin+8, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+8, LED);
  delay(t1);
  digitalWrite(pin+9, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+9, LED);
  delay(t1);
  digitalWrite(pin+10, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+10, LED);
  delay(t1);
  digitalWrite(pin+11, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+11, LED);
  delay(t1);
  digitalWrite(pin+12, !LED);
  delay(t1);
  }
  for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+12, LED);
  delay(t1);
  digitalWrite(pin+13, !LED);
  delay(t1);
  }for(int pin = 9; pin >= 2; pin--)
  {
  digitalWrite(pin+13, LED);
  delay(t1);
  digitalWrite(pin, !LED);
  }
  }
  /////////////////////////////////////////////////////////////////////////////Effect 6
void effect_6()
{
for(int j=2; j<10; j++){
  digitalWrite(j, !LED);
  delay(t);
  digitalWrite(j, LED);
  delay(t);
  digitalWrite(j-2, !LED);
  delay(t);
  digitalWrite(j, LED);
}
for(int k = 9; k>2; k--){
  digitalWrite(k, !LED);
  delay(t);
  digitalWrite(k, LED);
  delay(t);
  digitalWrite(k+2, !LED);
  delay(t);
  digitalWrite(k, LED);
}
for(int k = 2; k<10; k++){
  digitalWrite(k, !LED);
  delay(t);
  digitalWrite(k, LED);
  delay(t);
  digitalWrite(k-2, !LED);
  delay(t);
  digitalWrite(k, LED);
}
for(int k = 9; k>2; k--){
  digitalWrite(k, !LED);
  delay(t);
  digitalWrite(k, LED);
  delay(t);
  digitalWrite(k+4, !LED);
  delay(t);
  digitalWrite(k, LED);
}
for(int k = 2; k<10; k++){
  digitalWrite(k, !LED);
  delay(t);
  digitalWrite(k, LED);
  delay(t);
  digitalWrite(k-4, !LED);
  delay(t);
  digitalWrite(k, LED);
} 
}
///////////////////////////////////////////////////////////////////////////////////Effect 7
void effect_7()
{
for(int j=2; j<10; j++){
  digitalWrite(j, LED);
  delay(t);
  digitalWrite(j+2, !LED);
  delay(t);
}
for(int k = 9; k>2; k--){
  digitalWrite(k, LED);
  delay(t);
  digitalWrite(k+2, !LED);
  delay(t);
}
}

// function to switch all LEDs off
void clear(void)
{
  for (int i = 2; i <= 10; i++) {
    digitalWrite(i, !LED);
  }
}
