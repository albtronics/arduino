#include "DabbleGamepad.h"
#define PI 3.14159
ESP32_BLE BLE;
uint8_t* receivedData = NULL;
uint8_t moduleId = 0;
uint8_t functionId = 0;
uint8_t Arg1 = 0;
uint8_t Arg2 = 0;
uint8_t** dataByte = NULL;
DabbleGamepad::DabbleGamepad(){}


void DabbleGamepad::begin(std::string a)
{
 BLE.init(a); 
}
void DabbleGamepad::processBleData()
{
  if (BLE.available())
  {
   // Serial.println("In available");
    for (int i = 0; i < Arg1; i++)
    {
      delete [] dataByte[i];
    }
    delete [] dataByte;
    int dataLength = BLE.available();
    receivedData = new uint8_t[dataLength];
    int i = 0;
    while (BLE.available())
    {
      receivedData[i] = BLE.read();
      i++;
    }
    if (receivedData[0] == 0xFF)
    {
      moduleId = receivedData[1];
      functionId = receivedData[2];
      Arg1 = receivedData[3];
      Arg2 = receivedData[4];
    }
    dataByte = new uint8_t*[Arg1];
    for (int i = 0; i < Arg1; i++)
    {
      dataByte[i] = new uint8_t[Arg2];
    }
    for (int i = 0; i < Arg1; i++)
    {
      int a = 5 + i * (Arg2 + 1);
      for (int j = 0; j < Arg2; j++)
      {
        dataByte[i][j] = receivedData[a + j];
      }
    }
  }
}


//uint8_t DabbleGamepad::getFunctionId()
//{
//  return functionId;
//}
//
//uint8_t DabbleGamepad::getmoduleId()
//{
//  return moduleId;
//}
bool DabbleGamepad::isUpPressed()
{
  if ((moduleId == 0x01) && (functionId == 0x01))
  {
    return ((dataByte[0][1] & 0x01) == 0x01);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isDownPressed()
{
  if ((moduleId == 0x01) && (functionId == 0x01))
  {
    return ((dataByte[0][1] & 0x02) == 0x02);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isLeftPressed()
{
  if ((moduleId == 0x01) && (functionId == 0x01))
  {
    return ((dataByte[0][1] & 0x04) == 0x04);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isRightPressed()
{
  if ((moduleId == 0x01) && (functionId == 0x01))
  {
    return ((dataByte[0][1] & 0x08) == 0x08);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isCrossPressed()
{
  if ((moduleId == 0x01) && ((functionId == 0x01) || (functionId == 0x02) || (functionId == 0x03)))
  {
    return ((dataByte[0][0] & 0x10) == 0x10);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isSquarePressed()
{
  if ((moduleId == 0x01) && ((functionId == 0x01) || (functionId == 0x02) || (functionId == 0x03)))
  {
    return ((dataByte[0][0] & 0x20) == 0x20);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isTrianglePressed()
{
  if ((moduleId == 0x01) && ((functionId == 0x01) || (functionId == 0x02) || (functionId == 0x03)))
  {
    return ((dataByte[0][0] & 0x04) == 0x04);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isSelectPressed()
{
  if ((moduleId == 0x01) && ((functionId == 0x01) || (functionId == 0x02) || (functionId == 0x03)))
  {
    return ((dataByte[0][0] & 0x02) == 0x02);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isStartPressed()
{
  if ((moduleId == 0x01) && ((functionId == 0x01) || (functionId == 0x02) || (functionId == 0x03)))
  {
    return ((dataByte[0][0] & 0x01) == 0x01);
  }
  else
  {
    return 0;
  }
}

bool DabbleGamepad::isCirclePressed()
{
  if ((moduleId == 0x01) && ((functionId == 0x01) || (functionId == 0x02) || (functionId == 0x03)))
  {
    return ((dataByte[0][0] & 0x08) == 0x08);
  }
  else
  {
    return 0;
  }
}

uint16_t DabbleGamepad::getAngle()
{
  if ((moduleId == 0x01) && ((functionId == 0x02) || (functionId == 0x03)))
    return ((dataByte[0][1] >> 3) * 15);
  else
    return 0;
}

uint8_t DabbleGamepad::getRadius()
{
  if ((moduleId == 0x01) && ((functionId == 0x02) || (functionId == 0x03)))
    return (dataByte[0][1] & 0x07);
  else
    return 0;
}

float DabbleGamepad::getx_axis()
{
  if ((moduleId == 0x01) && ((functionId == 0x02) || (functionId == 0x03)))
  {
    float x_value = float(getRadius() * (float(cos(float(getAngle() * PI / 180)))));
    return x_value;
  }
  else
    return 0;
}

float DabbleGamepad::gety_axis()
{
  if ((moduleId == 0x01) && ((functionId == 0x02) || (functionId == 0x03)))
  {
    float y_value = float(getRadius() * (float(sin(float(getAngle() * PI / 180)))));
	return y_value;
  }
  else
    return 0;
}
