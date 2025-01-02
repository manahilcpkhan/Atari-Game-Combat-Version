/*
 * p1vsp2.h
 *
 *  Created on: Jun 9, 2022
 *      Author: manahil kamran 21i-2668
 */

#ifndef P1VSP2_H_
#define P1VSP2_H_
#include <iostream>
#include<string>
#include "util.h"
#include "map.h"
#include "vehicle.h"
using namespace std;

class p1vsp2 {
	  vehicle p1;
	  vehicle p2;
	  int by1, bx1;
public:
  p1vsp2();
  virtual ~p1vsp2();
  p1vsp2(const p1vsp2 &other);

  int score;
  void setV (unsigned char);
  void level1 ();
  void level2 ();
  void level3 ();
  void control1 (int);
  void control2 (unsigned char);
  void Score (int);
  void l1Collision ();
  void l2Collision ();
  void l3Collision ();


};

#endif /* P1VSP2_H_ */
