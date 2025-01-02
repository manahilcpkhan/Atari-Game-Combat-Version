/*
 * vehicle.h
 *
 *  Created on: Jun 3, 2022
 *      Author: manahil kamran i21-2668
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>
#include<string>
#include "util.h"
using namespace std;
class vehicle
{
public:
  int xI, yI;
  unsigned char choice;
public:
    vehicle ();
    vehicle (unsigned char);
  void setchoice (unsigned char);
  unsigned char getchoice ();
  void spawn ();
  void l1Collision ();
  void l2Collision ();
  void l3Collision ();
  void drawTank ();
  void drawHelicopter ();
  virtual void control1 (int);
  virtual void control2 (unsigned char);
    virtual ~ vehicle ();
};

#endif /* VEHICLE_H_ */
