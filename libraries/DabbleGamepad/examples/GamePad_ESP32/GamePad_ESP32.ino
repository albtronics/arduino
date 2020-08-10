#include "DabbleGamepad.h"

DabbleGamepad Gamepad;

void setup() {
  Serial.begin(115200);
  Gamepad.begin("ESP32_BLE");   //enter name that you want to keep for your bluetooth.
}

void loop() {
  Gamepad.processBleData();
  Serial.print("KeyPressed: ");
  if (Gamepad.isUpPressed())
  {
    Serial.print("UP");
  }
  if (Gamepad.isDownPressed())
  {
    Serial.print("UP");
  }
  if (Gamepad.isRightPressed())
  {
    Serial.print("Right");
  }
  if (Gamepad.isLeftPressed())
  {
    Serial.print("Left");
  }
  if (Gamepad.isCirclePressed())
  {
    Serial.print("Circle");
  }
  if (Gamepad.isCrossPressed())
  {
    Serial.print("Cross");
  }
  if (Gamepad.isStartPressed())
  {
    Serial.print("Start");
  }
  if (Gamepad.isSelectPressed())
  {
    Serial.print("Select");
  }
  if (Gamepad.isSquarePressed())
  {
    Serial.print("Square");
  }
  if (Gamepad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }
  Serial.print('\t');
  Serial.print("Angle: ");
  Serial.print(Gamepad.getAngle());
  Serial.print('\t');
  Serial.print("Radius: ");
  Serial.print(Gamepad.getRadius());
  Serial.print('\t');
  Serial.print("x_value: ");
  Serial.print(Gamepad.getx_axis());
  Serial.print('\t');
  Serial.print("y_value: ");
  Serial.println(Gamepad.gety_axis());
}
