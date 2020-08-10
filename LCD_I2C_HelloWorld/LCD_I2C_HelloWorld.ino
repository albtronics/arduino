//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{

  // initialize the LCD,
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();



}

void loop()
{


  lcd.clear();
  //lcd.print(" albtronics.com");
  lcd.setCursor (0, 1); // go to start of 2nd line
  lcd.print("Owned By : albtronics");
  //lcd.print(millis() / 1000);
  delay(500);

}
