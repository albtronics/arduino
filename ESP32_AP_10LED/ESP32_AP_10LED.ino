//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials

const char* ssid = "Your_SSID_Name";
const char* password = "Password";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output1State = "OFF";
String output2State = "OFF";
String output3State = "OFF";
String output4State = "OFF";
String output5State = "OFF";
String output6State = "OFF";
String output7State = "OFF";
String output8State = "OFF";
String output9State = "OFF";
String output10State = "OFF";

// Assign output variables to GPIO pins
const int output1 = 26;
const int output2 = 25;
const int output3 = 33;
const int output4 = 32;
const int output5 = 2;
const int output6 = 0;
const int output7 = 4;
const int output8 = 16;
const int output9 = 17;
const int output10 = 5;

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(output5, OUTPUT);
  pinMode(output6, OUTPUT);
  pinMode(output7, OUTPUT);
  pinMode(output8, OUTPUT);
  pinMode(output9, OUTPUT);
  pinMode(output10, OUTPUT);

  digitalWrite(output1, LOW);
  digitalWrite(output2, LOW);
  digitalWrite(output3, LOW);
  digitalWrite(output4, LOW);
  digitalWrite(output5, LOW);
  digitalWrite(output6, LOW);
  digitalWrite(output7, LOW);
  digitalWrite(output8, LOW);
  digitalWrite(output9, LOW);
  digitalWrite(output10, LOW);

  WiFi.softAP(ssid, password);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /1/ON") >= 0) {
              Serial.println("OUTPUT1 ON");
              output1State = "ON";
              digitalWrite(output1, HIGH);
            } else if (header.indexOf("GET /1/OFF") >= 0) {
              Serial.println("OUTPUT1 OFF");
              output1State = "OFF";
              digitalWrite(output1, LOW);
            } else if (header.indexOf("GET /2/ON") >= 0) {
              Serial.println("OUTPUT2 ON");
              output2State = "ON";
              digitalWrite(output2, HIGH);
            } else if (header.indexOf("GET /2/OFF") >= 0) {
              Serial.println("OUTPUT2 OFF");
              output2State = "OFF";
              digitalWrite(output2, LOW);
            } else if (header.indexOf("GET /3/ON") >= 0) {
              Serial.println("OUTPUT3 ON");
              output3State = "ON";
              digitalWrite(output3, HIGH);
            } else if (header.indexOf("GET /3/OFF") >= 0) {
              Serial.println("OUTPUT3 OFF");
              output3State = "OFF";
              digitalWrite(output3, LOW);
            } else if (header.indexOf("GET /4/ON") >= 0) {
              Serial.println("OUTPUT4 ON");
              output4State = "ON";
              digitalWrite(output4, HIGH);
            } else if (header.indexOf("GET /4/OFF") >= 0) {
              Serial.println("OUTPUT4 OFF");
              output4State = "OFF";
              digitalWrite(output4, LOW);
            } else if (header.indexOf("GET /5/ON") >= 0) {
              Serial.println("OUTPUT5 ON");
              output5State = "ON";
              digitalWrite(output5, HIGH);
            } else if (header.indexOf("GET /5/OFF") >= 0) {
              Serial.println("OUTPUT5 OFF");
              output5State = "OFF";
              digitalWrite(output5, LOW);
            } else if (header.indexOf("GET /6/ON") >= 0) {
              Serial.println("OUTPUT6 ON");
              output6State = "ON";
              digitalWrite(output6, HIGH);
            } else if (header.indexOf("GET /6/OFF") >= 0) {
              Serial.println("OUTPUT6 OFF");
              output6State = "OFF";
              digitalWrite(output6, LOW);
            } else if (header.indexOf("GET /7/ON") >= 0) {
              Serial.println("OUTPUT7 ON");
              output7State = "ON";
              digitalWrite(output7, HIGH);
            } else if (header.indexOf("GET /7/OFF") >= 0) {
              Serial.println("OUTPUT7 OFF");
              output7State = "OFF";
              digitalWrite(output7, LOW);
            } else if (header.indexOf("GET /8/ON") >= 0) {
              Serial.println("OUTPUT8 ON");
              output8State = "ON";
              digitalWrite(output8, HIGH);
            } else if (header.indexOf("GET /8/OFF") >= 0) {
              Serial.println("OUTPUT8 OFF");
              output8State = "OFF";
              digitalWrite(output8, LOW);
            } else if (header.indexOf("GET /9/ON") >= 0) {
              Serial.println("OUTPUT9 ON");
              output9State = "ON";
              digitalWrite(output9, HIGH);
            } else if (header.indexOf("GET /9/OFF") >= 0) {
              Serial.println("OUTPUT9 OFF");
              output9State = "OFF";
              digitalWrite(output9, LOW);
            } else if (header.indexOf("GET /10/ON") >= 0) {
              Serial.println("OUTPUT10 ON");
              output10State = "ON";
              digitalWrite(output10, HIGH);
            } else if (header.indexOf("GET /10/OFF") >= 0) {
              Serial.println("OUTPUT10 OFF");
              output10State = "OFF";
              digitalWrite(output10, LOW);

            }


            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            client.println("<body><h2>albtronics.com</h2>");
            // Display current state, and ON/OFF buttons for GPIO 26
            client.println("<p>OUTPUT 1 - State " + output1State + "</p>");
            // If the output1State is off, it displays the ON button
            if (output1State == "OFF") {
              client.println("<p><a href=\"/1/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/1/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 27
            client.println("<p>OUTPUT 2 - State " + output2State + "</p>");
            // If the output2State is off, it displays the ON button
            if (output2State == "OFF") {
              client.println("<p><a href=\"/2/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>OUTPUT 3 - State " + output3State + "</p>");
            // If the output3State is off, it displays the ON button
            if (output3State == "OFF") {
              client.println("<p><a href=\"/3/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/3/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>OUTPUT 4 - State " + output4State + "</p>");
            // If the output4State is off, it displays the ON button
            if (output4State == "OFF") {
              client.println("<p><a href=\"/4/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>OUTPUT 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button
            if (output5State == "OFF") {
              client.println("<p><a href=\"/5/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>OUTPUT 6 - State " + output6State + "</p>");
            // If the output6State is off, it displays the ON button
            if (output6State == "OFF") {
              client.println("<p><a href=\"/6/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/6/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>OUTPUT 7 - State " + output7State + "</p>");
            // If the output7State is off, it displays the ON button
            if (output7State == "OFF") {
              client.println("<p><a href=\"/7/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/7/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>OUTPUT 8 - State " + output8State + "</p>");
            // If the output8State is off, it displays the ON button
            if (output8State == "OFF") {
              client.println("<p><a href=\"/8/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/8/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>OUTPUT 9 - State " + output9State + "</p>");
            // If the output9State is off, it displays the ON button
            if (output9State == "OFF") {
              client.println("<p><a href=\"/9/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/9/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("<p>OUTPUT 10 - State " + output10State + "</p>");
            // If the output10State is off, it displays the ON button
            if (output10State == "OFF") {
              client.println("<p><a href=\"/10/ON\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/10/OFF\"><button class=\"button button2\">OFF</button></a></p>");
            }

            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
