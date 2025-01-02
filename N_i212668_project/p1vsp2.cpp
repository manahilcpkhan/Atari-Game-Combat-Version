/*
 * p1vsp2.cpp
 *
 *  Created on: Jun 2, 2022
 *      Author: manahil kamran i21-2668
 */

#include "p1vsp2.h"
p1vsp2::p1vsp2 ()
{
  // TODO Auto-generated constructor stub

  by1 = p2.yI;
  bx1 = p2.xI;
  score = 0;
  level1 ();
}

p1vsp2::~p1vsp2 ()
{
//destructor
}

p1vsp2::p1vsp2 (const p1vsp2 & other)
{				//copy constructor

  this->p1 = other.p1;

  this->by1 = other.by1;

  this->bx1 = other.bx1;

}

void
p1vsp2::Score (int s)
{				//to set score
  score = s;
}



void
p1vsp2::level1 ()
{				//to select vehicle and display level one graphics
  map l1 (0.6, 0.3, 0.6, 2);

  Score (score);

  if (p1.getchoice () == '1')
    {
      p1.drawTank ();
    }
  else
    p1.drawHelicopter ();

  if (p2.getchoice () == '1')
    {
      p2.drawTank ();
    }
  else
    p2.drawHelicopter ();

}

void
p1vsp2::level2 ()
{				//to select vehicle and display level 2 graphics
  map l2 (0.3, 0.9, 0.2, 3);
  Score (score);


  if (p1.getchoice () == '1')
    {
      p1.drawTank ();
    }
  else
    p1.drawHelicopter ();

  if (p2.getchoice () == '1')
    {
      p2.drawTank ();
    }
  else
    p2.drawHelicopter ();
}

void
p1vsp2::level3 ()
{				//to select vehicle and display level 3 graphics
  map l2 (0.5, 0, 0, 4);
  Score (score);

  if (p1.getchoice () == '1')
    {
      p1.drawTank ();
    }
  else
    p1.drawHelicopter ();

  if (p2.getchoice () == '1')
    {
      p2.drawTank ();
    }
  else
    p2.drawHelicopter ();
}


void
p1vsp2::control1 (int key)
{
  p1.control1 (key);
  p1.l1Collision ();
}

void
p1vsp2::control2 (unsigned char key)
{
  p2.control2 (key);
  p2.l1Collision ();
}

void
p1vsp2::setV (unsigned char n)
{
  p1.setchoice (n);
  p2.setchoice (n);
}

void
p1vsp2::l1Collision ()
{
  p1.l1Collision ();
  p2.l1Collision ();
}

void
p1vsp2::l2Collision ()
{

  p1.l2Collision ();
  p2.l2Collision ();
}

void
p1vsp2::l3Collision ()
{
  p1.l3Collision ();
  p2.l3Collision ();
}
