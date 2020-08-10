//For More Info : https://albtronics.wordpress.com/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int currentPin = A0;
int sensitivity = 185;
int adcValue = 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.print(" Current Sensor ");
  lcd.setCursor(0, 1);
  lcd.print("  with Arduino  ");
  lcd.backlight();
  delay(2000);
}

void loop()
{
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);

  Serial.print("Raw Sensor Value = " );
  Serial.print(adcValue);

  lcd.clear();
  delay(1000);
  //lcd.display();
  lcd.setCursor(0, 0);
  lcd.print("ADC Value =     ");
  lcd.setCursor(12, 0);
  lcd.print(adcValue);

  delay(2000);

  Serial.print("\t Voltage(mV) = ");
  Serial.print(adcVoltage, 3);

  lcd.setCursor(0, 0);
  lcd.print("V in mV =       ");
  lcd.setCursor(10, 0);
  lcd.print(adcVoltage, 1);

  delay(2000);

  Serial.print("\t Current = ");
  Serial.println(currentValue, 3);

  lcd.setCursor(0, 0);
  lcd.print("Current =       ");
  lcd.setCursor(10, 0);
  lcd.print(currentValue, 2);
  lcd.setCursor(14, 0);
  lcd.print("A");
  delay(2500);
}
