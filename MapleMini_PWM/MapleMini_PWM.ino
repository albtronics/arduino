//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
int ledPin1[] = {3, 5, 9, 27, 25};
int ledPin2[] = {4, 8, 10, 26, 16};
int ledPin3[] = {3, 4, 5, 8, 9, 10, 27, 26, 25, 16};
int pincount = 10;
int period = 10;
void setup() {
  int Leftpin;
  for (int Leftpin = 0; Leftpin < 5; Leftpin++)  {
    pinMode(ledPin1[Leftpin], PWM);  // setup the pin as PWM
  }
  int Rightpin;
  for (int Rightpin = 0; Rightpin < 5; Rightpin++)  {
    pinMode(ledPin2[Rightpin], PWM);  // setup the pin as PWM
  }
  int Allpin;
  for (int Allpin = 0; Allpin < pincount; Allpin++)  {
    pinMode(ledPin3[Allpin], PWM);  // setup the pin as PWM
  }
}

void loop()  {
  //All();
  Left();
  Right();
  All();

}
void Left() {

  for (int fadeValue = 0; fadeValue <= 65535; fadeValue += 1280) {

    for (int Leftpin = 0; Leftpin < 5; Leftpin++) {
      pwmWrite(ledPin1[Leftpin], fadeValue);
    }

    delay(period);
  }


  for (int fadeValue = 65535 ; fadeValue >= 0; fadeValue -= 1280) {

    for (int Leftpin = 0; Leftpin < 5; Leftpin++) {
      pwmWrite(ledPin1[Leftpin], fadeValue);
    }

    delay(period);
  }
}

void Right() {

  for (int fadeValue = 0; fadeValue <= 65535; fadeValue += 1280) {

    for (int Rightpin = 0; Rightpin < 5; Rightpin++) {
      pwmWrite(ledPin2[Rightpin], fadeValue);
    }

    delay(period);
  }


  for (int fadeValue = 65535 ; fadeValue >= 0; fadeValue -= 1280) {

    for (int Rightpin = 0; Rightpin < 5; Rightpin++) {
      pwmWrite(ledPin2[Rightpin], fadeValue);
    }

    delay(period);
  }
}

void All() {

  for (int fadeValue = 0; fadeValue <= 65535; fadeValue += 1280) {

    for (int Allpin = 0; Allpin < pincount; Allpin++) {
      pwmWrite(ledPin3[Allpin], fadeValue);
    }

    delay(period);
  }


  for (int fadeValue = 65535 ; fadeValue >= 0; fadeValue -= 1280) {

    for (int Allpin = 0; Allpin < pincount; Allpin++) {
      pwmWrite(ledPin3[Allpin], fadeValue);
    }

    delay(period);
  }
}
