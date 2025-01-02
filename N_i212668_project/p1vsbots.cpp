/*
 * p1vsbots.cpp
 *
 *  Created on: Jun 2, 2022
 *      Author: manahil kamran i21-2668
 */

#include "p1vsbots.h"
p1vsbots::p1vsbots ()
{
  // TODO Auto-generated constructor stub
  flag1 = true, flag2 = true, flag3 = true, flag = true;
  displayB1 = true;
  displayB2 = true;
  displayB3 = true;
  by1 = 100, by2 = 160, bx3 = 20, by3 = 160;
  bx1 = 300;
  bx2 = 560;
  score = 0;
  level1 ();
}

p1vsbots::~p1vsbots ()
{
//destructor
}

p1vsbots::p1vsbots (p1vsbots & other)
{				//copy constructor
  this->flag1 = other.flag1;

  this->flag2 = other.flag2;

  this->flag = other.flag;

  this->flag3 = other.flag3;

  this->flag4 = other.flag4;

  this->p1 = other.p1;

  this->by1 = other.by1;

  this->bx1 = other.bx1;

  this->by2 = other.by2;

  this->displayB1 = other.displayB1;
}

void
p1vsbots::Score (int s)
{				//to set score
  score = s;
}

void
p1vsbots::bot1 ()
{				//to draw bot1

  DrawRectangle (300, by1 + 10, 30, 10, colors[POWDER_BLUE]);

  DrawCircle (300 + 5, by1 + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (300 + 25, by1 + 5, 5, colors[DARK_SLATE_BLUE]);

}

void
p1vsbots::bot2 ()
{				//to draw bot2
  DrawRectangle (560, by2 + 10, 30, 10, colors[WHITE]);
  DrawCircle (560 + 5, by2 + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (560 + 25, by2 + 5, 5, colors[DARK_SLATE_BLUE]);
}

void
p1vsbots::bot3 ()
{				//to draw bot3
  DrawRectangle (20, by3 + 10, 30, 10, colors[WHITE]);
  DrawCircle (20 + 5, by3 + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (20 + 25, by3 + 5, 5, colors[DARK_SLATE_BLUE]);
}

void
p1vsbots::level1 ()
{				//to select vehicle and display level one graphics
  map l1 (0.6, 0.3, 0.6, 2);
  if (displayB1 == true)
    {
      bot1 ();
    }
  Score (score);

  if (p1.getchoice () == '1')
    {
      p1.drawTank ();
    }
  else
    p1.drawHelicopter ();

}

void
p1vsbots::level2 ()
{				//to select vehicle and display level 2 graphics
  map l2 (0.3, 0.9, 0.2, 3);
  displayB1 = true;
  displayB2 = true;
  if (displayB1 == true)
    bot1 ();
  if (displayB2 == true)
    bot2 ();


  Score (score);


  if (p1.getchoice () == '1')
    {
      p1.drawTank ();
    }
  else
    p1.drawHelicopter ();
}

void
p1vsbots::level3 ()
{				//to select vehicle and display level 3 graphics
  map l2 (0.5, 0, 0, 4);
  displayB1 = true;
  displayB2 = true;
  displayB3 = true;
  if (displayB1 == true)
    bot1 ();
  if (displayB2 == true)
    bot2 ();
  if (displayB3 == true)
    bot3 ();
  Score (score);

  if (p1.getchoice () == '1')
    {
      p1.drawTank ();
    }
  else
    p1.drawHelicopter ();
}

void
p1vsbots::moveBot1 ()		//movement of bot 1
{
  if (by1 > 10 && flag1)
    {
      by1 -= 5;
      cout << "going up";
      if (by1 < 99)
	flag1 = false;

    }
  else if (by1 < 600 && !flag1)
    {
      cout << "go down";
      by1 += 5;
      if (by1 > 570)
	flag1 = true;
    }

  glutPostRedisplay ();
}

void
p1vsbots::moveBot2 ()		//movement of bot 2
{
  if (by2 < 570 && flag2)
    {
      by2 += 5;
      cout << "going up";
      if (by2 > 560)
	flag2 = false;

    }
  else if (by2 > 20 && !flag2)
    {
      cout << "go down";
      by2 -= 5;
      ;
      if (by2 < 30)
	flag2 = true;
    }

}

void
p1vsbots::moveBot3 ()		////movement of bot 3
{
  if (by3 < 570 && flag3)
    {
      by3 += 5;
      cout << "going up";
      if (by3 > 560)
	flag3 = false;

    }
  else if (by3 > 20 && !flag3)
    {
      cout << "go down";
      by3 -= 5;
      ;
      if (by3 < 30)
	flag3 = true;
    }

}

void
p1vsbots::control1 (int key)
{
  p1.control1 (key);
  p1.l1Collision ();
}

void
p1vsbots::control2 (unsigned char key)
{
  p1.control2 (key);
}

void
p1vsbots::setV (unsigned char n)
{
  p1.setchoice (n);
}

void
p1vsbots::l1Collision ()
{
  p1.l1Collision ();
}

void
p1vsbots::l2Collision ()
{

  p1.l2Collision ();

}

void
p1vsbots::l3Collision ()
{
  p1.l3Collision ();
}
