//𝓕𝓸𝓻 𝓜𝓸𝓻𝓮 𝓘𝓷𝓯𝓸 𝓥𝓲𝓼𝓲𝓽: 𝓱𝓽𝓽𝓹𝓼://𝓪𝓵𝓫𝓽𝓻𝓸𝓷𝓲𝓬𝓼.𝔀𝓸𝓻𝓭𝓹𝓻𝓮𝓼𝓼.𝓬𝓸𝓶/
#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into 
BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;
int LED = 23;
void setup() {
  Serial.begin(9600); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode (LED, OUTPUT);//Specify that LED pin is output
}

void loop() {

  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we recevive
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == 49)
    {
      digitalWrite(LED, HIGH);
      ESP_BT.println("LED TURNED ON");
    }

    if (incoming == 48)
    {
      digitalWrite(LED, LOW);
      ESP_BT.println("LED TURNED OFF");
    }
  }
  delay(20);
}
