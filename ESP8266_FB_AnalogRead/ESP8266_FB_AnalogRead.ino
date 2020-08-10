#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

const char *ssid = "Your_SSID_Name";      //Your Wi-Fi SSID
const char *password = "Password"; //Your Wi-Fi password

#define projectID "Your_Project_ID" //Your Firebase Project ID; can be found in project settings.
String myString;
//int sdata ;
Firebase firebase(projectID);
void setup() {
  // pinMode(A0 ,INPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  //Attempt to connect to Wifi network:
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

  //Create an object.

  //firebase.pushString("Variable/Value","Albin");
  //Examples of pushing String, integer and float values.
  //firebase.pushString("push", "Hello");
  //firebase.pushInt("push", 789);
  //firebase.pushFloat("push", 89.54);
}

void loop() {

  int sdata = analogRead(A0);
  myString = String(sdata);
  Serial.println(myString);
  firebase.pushString("Variable/Value", myString);
  //firebase.pushInt("push", sdata);
  delay(1);
}
