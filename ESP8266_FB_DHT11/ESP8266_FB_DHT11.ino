//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
#define DHTPIN 4   // what digital pin we're connected to
#define DHTTYPE DHT11
#define projectID "Your_Project_ID"
DHT dht(DHTPIN, DHTTYPE);
Firebase firebase(projectID);
const char *ssid = "Your_SSID_Name";      //Your Wi-Fi SSID
const char *password = "Password"; //Your Wi-Fi password

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
  Serial.println("");
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("-");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  Serial.println("");

}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to Read from DHT-11 Sensor!");
    //   firebase.setString("VEHILCE/IGNITION", "VEHICLE BEING TAMPERED !!");
    firebase.setString("DHT", "Failed to Read from DHT-11 Sensor!");
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  String humid = String(h);
  String temp = String(t) ;

  firebase.pushString("/DHT11/Humidity", humid);
  firebase.pushString("/DHT11/Temperature", temp);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F ");





}
