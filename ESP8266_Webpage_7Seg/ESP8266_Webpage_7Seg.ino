//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "FS.h"
//SSID and Password of your WiFi router
const char* ssid = "Your_SSID_Name";
const char* password = "Password";
String data, data1;
const int A = 5;
const int B = 4;
const int C = 0;
const int D = 2;
const int E = 12;
const int F = 13;
const int G = 15;
ESP8266WebServer server(80); //Server on port 80
//==============================================================
//                  SETUP
//==============================================================
void setup(void) {
  pinMode(A, OUTPUT);  digitalWrite(A, HIGH);
  pinMode(B, OUTPUT);  digitalWrite(B, HIGH);
  pinMode(C, OUTPUT);  digitalWrite(C, HIGH);
  pinMode(D, OUTPUT);  digitalWrite(D, HIGH);
  pinMode(E, OUTPUT);  digitalWrite(E, HIGH);
  pinMode(F, OUTPUT);  digitalWrite(F, HIGH);
  pinMode(G, OUTPUT);  digitalWrite(G, HIGH);
  pinMode(14, OUTPUT); // digitalWrite(14,HIGH);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);                                       //ESP8266 operates on Station(client) mode only
  WiFi.begin(ssid, password);                                //Connect to your WiFi router
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());                            //IP address assigned to your ESP
  prepareFile();                                             //Loads and open html file from SPIFFS
  server.on("/", HTTP_GET, handleRoot);                      //Which routine to handle at root location
  server.on("/submit", HTTP_POST , handleSubmit);
  server.on("/main.js", []() {                               //Loading the javascript file from SPIFFS
    loadScript("/main.js", "application/javascript");
  });
  server.begin();                                            //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void) {
  server.handleClient();          //Handle client requests
  digitalWrite(14, HIGH);
  delay(100);
  digitalWrite(14, LOW);
  delay(100);
}
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
  server.send(200, "text/html", data); //Send web page
}
//=============================================================================
// This routine is executed when server get data from the form of root html page
//=============================================================================
void handleSubmit() {
  if ( ! server.hasArg("nam") || server.arg("nam") == NULL) {
    server.send(400, "text/plain", "400: Invalid Request");
    return;
  }
  if (server.arg("nam") == "0") {
    server.send(200, "text/html", data1);
    sevenSeg(0);
  }
  else if (server.arg("nam") == "1") {
    server.send(200, "text/html", data1);
    sevenSeg(1);
  }
  else if (server.arg("nam") == "2") {
    server.send(200, "text/html", data1);
    sevenSeg(2);
  }
  else if (server.arg("nam") == "3") {
    server.send(200, "text/html", data1);
    sevenSeg(3);
  }
  else if (server.arg("nam") == "4") {
    server.send(200, "text/html", data1);
    sevenSeg(4);
  }
  else if (server.arg("nam") == "5") {
    server.send(200, "text/html", data1);
    sevenSeg(5);
  }
  else if (server.arg("nam") == "6") {
    server.send(200, "text/html", data1);
    sevenSeg(6);
  }
  else if (server.arg("nam") == "7") {
    server.send(200, "text/html", data1);
    sevenSeg(7);
  }
  else if (server.arg("nam") == "8") {
    server.send(200, "text/html", data1);
    sevenSeg(8);
  }
  else if (server.arg("nam") == "9") {
    server.send(200, "text/html", data1);
    sevenSeg(9);
  }
  else {
    server.send(401, "text/plain", "401: Unauthorized");
  }
}
void prepareFile() {
  bool ok = SPIFFS.begin();
  if (ok) {
    File f = SPIFFS.open("/index.html", "r");
    File f1 = SPIFFS.open("/index1.html", "r");
    data = f.readString();
    data1 = f1.readString();
    f.close();
    f1.close();
  }
  else
    Serial.println("No such file found.");
}
void loadScript(String path, String type) {
  if (SPIFFS.exists(path)) {
    File file = SPIFFS.open(path, "r");
    server.streamFile(file, type);
  }
}
//=========================================================================================
// This routine is called from handleSubmit() to control our 7 segment LED display(hardware)
//=========================================================================================
void sevenSeg(int num) {
  if (num == 0) {
    onA(); onB(); onC(); onD(); onE(); onF();
    offG();
  }
  else if (num == 1) {
    onB(); onC();
    offA(); offD(); offE(); offF(); offG();
  }
  else if (num == 2) {
    onA(); onB(); onG(); onE(); onD();
    offF(); offC();
  }
  else if (num == 3) {
    onA(); onB(); onG(); onC(); onD();
    offE(); offF();
  }
  else if (num == 4) {
    onF(); onG(); onB(); onC();
    offA(); offE(); offD();
  }
  else if (num == 5) {
    onA(); onF(); onG(); onC(); onD();
    offB(); offE();
  }
  else if (num == 6) {
    onA(); onC(); onD(); onE(); onF(); onG();
    offB();
  }
  else if (num == 7) {
    onA(); onB(); onC();
    offD(); offE(); offF(); offG();
  }
  else if (num == 8) {
    onA(); onB(); onC(); onD(); onE(); onF(); onG();
  }
  else if (num == 9) {
    onA(); onB(); onC(); onF(); onG();
    offE(); onD();
  }
}
/*THESE FUNCTIONS ARE SELF EXPLATNATORY FOR CONTROLLING(ON/OFF) THE 7SEGMENT LED DISPLAY */
void onA() {
  digitalWrite(A, LOW);
} void offA() {
  digitalWrite(A, HIGH);
}
void onB() {
  digitalWrite(B, LOW);
} void offB() {
  digitalWrite(B, HIGH);
}
void onC() {
  digitalWrite(C, LOW);
} void offC() {
  digitalWrite(C, HIGH);
}
void onD() {
  digitalWrite(D, LOW);
} void offD() {
  digitalWrite(D, HIGH);
}
void onE() {
  digitalWrite(E, LOW);
} void offE() {
  digitalWrite(E, HIGH);
}
void onF() {
  digitalWrite(F, LOW);
} void offF() {
  digitalWrite(F, HIGH);
}
void onG() {
  digitalWrite(G, LOW);
} void offG() {
  digitalWrite(G, HIGH);
}
