#include "ESP32_BLE.h"

bool isDeviceConnected = false;
bool prevDeviceConnected = false;
uint8_t tx_Value = 0;
uint8_t rxdatalength = 0;
uint8_t bytesremaining = 0;
uint8_t* rxdataBuffer = NULL;


BLEServer *bleServer = NULL;
BLECharacteristic *bleTxCharacteristic;


class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* bleServer) {
      isDeviceConnected = true;
    };

    void onDisconnect(BLEServer* bleServer) {
      isDeviceConnected = false;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *bleCharacteristic) {
      std::string rx_Value = bleCharacteristic->getValue();
      delete [] rxdataBuffer;
      if (rx_Value.length() > 0) {
        rxdataBuffer = new uint8_t[rx_Value.length()];
       // Serial.println("*********");
       // Serial.print("Received Value: ");
        for (int i = 0; i < rx_Value.length(); i++)
        {
          rxdataBuffer[i] = rx_Value[i];
        //  Serial.print(rxdataBuffer[i]);
        //  Serial.println();
        }
       // Serial.println("*********");
        rxdatalength = rx_Value.length();
        bytesremaining = rx_Value.length();

      }
    }
};

ESP32_BLE::ESP32_BLE(){}
void ESP32_BLE::init(std::string a)
{
  BLEDevice::init(a);

  // Create the BLE Server
  bleServer = BLEDevice::createServer();
  bleServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *bleService = bleServer->createService(UUID_Service);

  // Create a BLE Characteristic
  bleTxCharacteristic = bleService->createCharacteristic(
                          UUID_Transmit,
                          BLECharacteristic::PROPERTY_NOTIFY
                        );

  bleTxCharacteristic->addDescriptor(new BLE2902());

  BLECharacteristic * bleRxCharacteristic = bleService->createCharacteristic(
        UUID_Receive,
        BLECharacteristic::PROPERTY_WRITE
      );

  bleRxCharacteristic->setCallbacks(new MyCallbacks());

  // Start the service
  bleService->start();

  // Start advertising
  bleServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}

uint8_t ESP32_BLE::available()
{
  return bytesremaining;
}
uint8_t ESP32_BLE::read()
{
  if (bytesremaining > 0)
  {
    uint8_t a = rxdataBuffer[rxdatalength - bytesremaining];
    bytesremaining--;
    return a;
  }
  else
  {
    return 0;
  }
}

void ESP32_BLE::stop()
{
  btStop();
}

