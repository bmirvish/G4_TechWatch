/*
 * DESCRIPTION
 * 
 * 
 */

#ifndef KickJr2Power_h
#define KickJr2Power_h

#include <Arduino.h>

class KickJr2Power
{
private:

public:

  KickJr2Power();
  void begin();

  bool isCharging(); //bool
  uint16_t getBatteryVoltage();

  /*
  void enableGPS();
  void disableGPS();
  
  void enableMP3();
  void disableMP3();
  */
  
};

#endif
