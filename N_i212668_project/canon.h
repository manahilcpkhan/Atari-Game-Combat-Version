/*
 * canon.h
 *
 *  Created on: Jun 6, 2022
 *      Author: manahil kamran i21-2668
 */

#ifndef CANON_H_
#define CANON_H_
#include <iostream>
#include<string>
#include "p1vsbots.h"
#include "util.h"
using namespace std;
class canon
{
  p1vsbots & player;
public:
  int x;
  int y;
  int bx1;
  int by1;
  int bx2;
  int by2;
  int bx3;
  int by3;
public:
    bool flag;
    canon ();
    canon (p1vsbots & obj);
  void canonbot ();
  void directionCanon (int, unsigned char);
  void moveCanon ();
  void small ();
  void medium ();
  void large ();
    virtual ~ canon ();
  void reset ();
};

#endif /* CANON_H_ */
