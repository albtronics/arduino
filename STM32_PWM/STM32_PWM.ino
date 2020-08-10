//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
int ledPin[] = {3, 4, 5, 8, 9, 10, 27, 26, 25, 16};

void setup() {
  int thisPin;
  for (int thisPin = 0; thisPin < 10; thisPin++)  {
    pinMode(ledPin[thisPin], PWM);  // setup the pin as PWM
  }
}

void loop()  {
  // Fade in from min to max in increments of 1280 points:
  for (int fadeValue = 0; fadeValue <= 65535; fadeValue += 1280) {
    // Sets the value (range from 0 to 65535):
    for (int thisPin = 0; thisPin < 11; thisPin++) {
      pwmWrite(ledPin[thisPin], fadeValue);
    }
    // Wait for 30 milliseconds to see the dimming effect:
    delay(30);
  }

  // Fade out from max to min in increments of 1280 points:
  for (int fadeValue = 65535 ; fadeValue >= 0; fadeValue -= 1280) {
    // Sets the value (range from 0 to 1280):
    for (int thisPin = 0; thisPin < 11; thisPin++) {
      pwmWrite(ledPin[thisPin], fadeValue);
    }
    // Wait for 30 milliseconds to see the dimming effect:
    delay(30);
  }
}
