#include "KickJr2Power.h"

const uint8_t chrgPin = 27;
const uint8_t battPin = A4;
// const uint8_t gpsPwrPin = 2;
const uint16_t VDD = 3300;
const uint16_t adcResolution = 1023;

/*
 * int - most Arduino boards define 2-bytes, but some actually do 4-bytes
 * float - give you decimals; float is less precise than double
 * double - give you decimals; more precise than float
 * 
 * uint8_t - unsigned 8 bit integer [0, 255]
 * uint16_t - unsigned 16 bit integer [0, 65355]
 *
 * int8_t - signed 8 bit integer [-127, 127]
 * int16_t - signed 16 bit integer [-32768, 32767]
 * 
 */

KickJr2Power::KickJr2Power()
{
}

void KickJr2Power::begin()
{
  pinMode(chrgPin, INPUT);
  //pinMode(gpsPwrPin, OUTPUT);
}

//Returns whether or not the battery is charging
bool KickJr2Power::isCharging()
{
  return !digitalRead(chrgPin); //return 0 if charging, 1 if not charging
}

uint16_t KickJr2Power::getBatteryVoltage()
{
  uint16_t val = analogRead(battPin); // 10-bit ADC, will return a number between 0 (0V) and 1023 (3.3V)
  uint16_t voltage = VDD*(val/(float)adcResolution);

  return 2*voltage;
  //return 2*3300*(analogRead(battPin)/1023);
}

/* 
void KickJr2Power::enableGPS()
{
  digitalWrite(gpsPwrPin, HIGH); // Enables regulator, turning ON GPS circuit
}

void KickJr2Power::disableGPS()
{
  digitalWrite(gpsPwrPin, LOW); // Enables regulator, turning ON GPS circuit
}
  
void KickJr2Power::enableMP3()
{
  
}

void KickJr2Power::disableMP3()
{
  
}
*/
