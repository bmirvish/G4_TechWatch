#include "KickJr2Power.h"

KickJr2Power pwr;


void setup()
{
  pwr.begin();
}

void loop()
{
  bool chrgStatus = pwr.isCharging();
  uint16_t battVoltage = pwr.getBatteryVoltage();
  //print this information to my watch screen
}
