/*
 * p1vsbots.h
 *
 *  Created on: Jun 2, 2022
 *      Author: manahil  kamran i21-2668
 */

#ifndef P1VSBOTS_H_
#define P1VSBOTS_H_
#include <iostream>
#include<string>
#include "util.h"
#include "map.h"
#include "vehicle.h"
using namespace std;

class p1vsbots
{

  bool flag1, flag2, flag, flag3, flag4;
  vehicle p1;
  int by1, bx1, bx2, by2, bx3, by3;
public:
  int score;
  bool displayB1;
  bool displayB2;
  bool displayB3;
    p1vsbots ();
    p1vsbots (p1vsbots & other);
  void bot1 ();
  void bot2 ();
  void bot3 ();
  void setV (unsigned char);
  void moveBot1 ();
  void moveBot2 ();
  void moveBot3 ();
  void level1 ();
  void level2 ();
  void level3 ();
  void control1 (int);
  void control2 (unsigned char);
  void Score (int);
  void l1Collision ();
  void l2Collision ();
  void l3Collision ();
    virtual ~ p1vsbots ();

  int getBx1 () const
  {
    return bx1;
  }

  int getBy1 () const
  {
    return by1;
  }

  bool isDisplayB1 () const
  {
    return displayB1;
  }

  const vehicle & getP1 () const
  {
    return p1;
  }

  void setP1 (const vehicle & p1)
  {
    this->p1 = p1;
  }

  void setDisplayB1 (bool displayB1)
  {
    this->displayB1 = displayB1;
  }

  int getBx2 () const
  {
    return bx2;
  }

  void setBx2 (int bx2)
  {
    this->bx2 = bx2;
  }

  int getBx3 () const
  {
    return bx3;
  }

  void setBx3 (int bx3)
  {
    this->bx3 = bx3;
  }

  int getBy2 () const
  {
    return by2;
  }

  void setBy2 (int by2)
  {
    this->by2 = by2;
  }

  int getBy3 () const
  {
    return by3;
  }

  void setBy3 (int by3)
  {
    this->by3 = by3;
  }
};
#endif /* P1VSBOTS_H_ */
