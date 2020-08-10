//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif


String res = "";

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(22, OUTPUT);
  SerialBT.begin("ESP32"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop()
{
  while (!SerialBT.available()); // Wait Until anything is coming from bluetooth client

  while (SerialBT.available()) // Read until the bluetooth client is sending.
  {
    char add = SerialBT.read();
    res = res + add;
    delay(1);
  }



  // Assigning Actions on particular conditions
  if (res == "T")
  {
    Serial.println("Connection Established!!!");
  }
  if (res == "abc")
  {
    Serial.println("Turning ON 1st led");
    digitalWrite(2, HIGH);
  }
  if (res == "def")
  {
    Serial.println("Turning OFF 1st led");
    digitalWrite(2, LOW);
  }
  if (res == "2")
  {
    Serial.println("Turning ON 2nd led");
    digitalWrite(5, HIGH);
  }
  if (res == "B")
  {
    Serial.println("Turning OFF 2nd led");
    digitalWrite(5, LOW);
  }
  if (res == "3")
  {
    Serial.println("Turning ON 3rd led");
    digitalWrite(18, HIGH);
  }
  if (res == "C")
  {
    Serial.println("Turning OFF 3rd led");
    digitalWrite(18, LOW);
  }
  if (res == "4")
  {
    Serial.println("Turning ON 4th led");
    digitalWrite(22, HIGH);
  }
  if (res == "D")
  {
    Serial.println("Turning OFF 4th led");
    digitalWrite(22, LOW);
  }
  if (res == "9")
  {
    Serial.println("Turning ON all led");
    digitalWrite(17, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(18, HIGH);
    digitalWrite(22, HIGH);

  }
  if (res == "I")
  {
    Serial.println("Turning OFF all led");
    digitalWrite(17, LOW);
    digitalWrite(5, LOW);
    digitalWrite(18, LOW);
    digitalWrite(22, LOW);

  }


  res = ""; // clearing the string.


}
