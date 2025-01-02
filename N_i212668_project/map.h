/*
 * map.h
 *
 *  Created on: Jun 1, 2022
 *      Author: manahilkamran i21-2668
 */

#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include<string>
#include "util.h"
using namespace std;
class map
{
public:
  double red;
  double green;
  double blue;
  int obstacle;

public:
    map ();
    map (double, double, double, int);
  void background ();
  void randomdraw ();
  void drawbuilding2 ();
  void drawbuilding3 ();
  void drawbuilding4 ();
    virtual ~ map ();
};

#endif /* MAP_H_ */
