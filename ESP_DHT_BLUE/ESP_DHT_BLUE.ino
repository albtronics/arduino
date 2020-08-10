//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
#include "DHT.h"
#define DHTPIN 27
#define DHTTYPE DHT11
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
DHT dht(DHTPIN, DHTTYPE);
String res = "";
BluetoothSerial SerialBT;

void setup() {
  dht.begin();
  Serial.begin(115200);

  SerialBT.begin("ESP32");
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
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);



  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");

  // Assigning Actions on particular conditions
  if (res == "A")
  {
    Serial.println("Connection Established!!!");

  }
  if (res == "H")
  {
    Serial.print("Humidity: ");
    Serial.print(h);
  }
  if (res == "T")
  {
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("Temperature: ");
    Serial.print(t);
  }


  res = ""; // clearing the string.


}
