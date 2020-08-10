#ifndef DabbleGamepad_H
#define DabbleGamepad_H
#include "ESP32_BLE.h"
class DabbleGamepad
{
    
  public:
    DabbleGamepad();
    void begin(std::string a);
    void processBleData();
    // uint8_t getFunctionId();
    // uint8_t getModuleId();
    bool isUpPressed();
    bool isDownPressed();
    bool isRightPressed();
    bool isLeftPressed();
    bool isCrossPressed();
    bool isSquarePressed();
    bool isCirclePressed();
    bool isTrianglePressed();
    bool isSelectPressed();
    bool isStartPressed();
    uint16_t getAngle();
    uint8_t getRadius();
    float getx_axis();
    float gety_axis();
};
#endif
