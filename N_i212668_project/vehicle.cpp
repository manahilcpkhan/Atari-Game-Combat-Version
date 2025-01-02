/*
 * vehicle.cpp
 *
 *  Created on: Jun 3, 2022
 *      Author: manahil kamran i21-2668
 */

#include "vehicle.h"

vehicle::vehicle (unsigned char n)
{				//parametrised constructor
  // TODO Auto-generated constructor stub
  xI = 0;
  yI = 520;
  choice = n;
  if (choice == '1')
    {
      drawTank ();
    }
  else
    drawHelicopter ();
}

vehicle::vehicle ()
{				//default constructor
  xI = 0;
  yI = 520;
  choice = '1';
  if (choice == '1')
    {
      drawTank ();
    }
  else
    drawHelicopter ();
}

void
vehicle::setchoice (unsigned char n)
{				//set of vehicle
  choice = n;
  if (choice == '1')
    {
      drawTank ();
    }
  else
    drawHelicopter ();

}

unsigned char
vehicle::getchoice ()
{				//get of vehicle
  return choice;

}

void
vehicle::drawTank ()
{				//draw the tank
  DrawRectangle (xI + 5, yI + 19, 20, 10, colors[DARK_GOLDEN_ROD]);
  DrawRectangle (xI, yI + 10, 30, 10, colors[DARK_GOLDEN_ROD]);
  DrawCircle (xI + 5, yI + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (xI + 25, yI + 5, 5, colors[DARK_SLATE_BLUE]);

}

void
vehicle::drawHelicopter ()
{				//draw the helicopter
  DrawRectangle (xI + 5, yI + 19, 20, 10, colors[RED]);
  DrawRectangle (xI, yI + 10, 30, 10, colors[RED]);
  DrawCircle (xI + 5, yI + 5, 5, colors[DARK_SLATE_BLUE]);
  DrawCircle (xI + 25, yI + 5, 5, colors[DARK_SLATE_BLUE]);
}

void
vehicle::control1 (int key)
{				//controls for arrows

  if (key ==
      GLUT_KEY_LEFT
      /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key */ )
    {
      // what to do when left key is pressed...
      xI -= 10;

    }
  else if (key ==
	   GLUT_KEY_RIGHT
	   /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key */
	   )
    {
      xI += 10;

    }
  else if (key ==
	   GLUT_KEY_UP
	   /*GLUT_KEY_UP is constant and contains ASCII for up arrow key */ )
    {
      yI += 10;

    }

  else if (key ==
	   GLUT_KEY_DOWN
	   /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key */
	   )
    {
      yI -= 10;

    }

  spawn ();

}

void
vehicle::control2 (unsigned char key)
{				//controls for letter keys
  if (key == 'a')
    {
      xI -= 10;
    }
  if (key == 'd')
    {
      xI += 10;
    }
  if (key == 'w')
    {
      yI += 10;
    }
  if (key == 's')
    {
      yI -= 10;
    }
  spawn ();
}

void
vehicle::spawn ()
{				//spawn of vehicle
  if (xI < 0)
    {
      xI = 570;

    }
  else if (xI > 570)
    {
      xI = 10;
    }
  else if (yI < 0)
    {
      yI = 570;

    }
  else if (yI > 570)
    {
      yI = 10;
    }



  glutPostRedisplay ();
}

void
vehicle::l1Collision ()
{				//collision for level 1

  //1
  if (xI >= 30 && xI <= 180)
    {
      if (yI == 160)
	{
	  yI -= 10;
	}
      if (yI == 200)
	{
	  yI += 10;
	}
    }
  if (yI >= 160 && yI <= 200)
    {
      if (xI == 30)
	{
	  xI -= 10;
	}
      if (xI == 180)
	{
	  xI += 10;
	}
    }
  //2
  if (xI >= 30 && xI <= 90)
    {
      if (yI == 190)
	{
	  yI -= 10;
	}
      if (yI == 380)
	{
	  yI += 10;
	}
    }
  if (yI >= 190 && yI <= 380)
    {
      if (xI == 30)
	{
	  xI -= 10;
	}
      if (xI == 90)
	{
	  xI += 10;
	}
    }
  //3
  if (xI >= 450 && xI <= 500)
    {
      if (yI == 440)
	{
	  yI -= 10;
	}
      if (yI == 540)
	{
	  yI += 10;
	}
    }
  if (yI >= 440 && yI <= 540)
    {
      if (xI == 450)
	{
	  xI -= 10;
	}
      if (xI == 500)
	{
	  xI += 10;
	}
    }

}

void
vehicle::l2Collision ()
{				//collision for level 2
  //1
  if (xI >= 30 && xI <= 180)
    {
      if (yI == 160)
	{
	  yI -= 10;
	}
      if (yI == 200)
	{
	  yI += 10;
	}
    }
  if (yI >= 160 && yI <= 200)
    {
      if (xI == 30)
	{
	  xI -= 10;
	}
      if (xI == 180)
	{
	  xI += 10;
	}
    }
  //2
  if (xI >= 30 && xI <= 90)
    {
      if (yI == 190)
	{
	  yI -= 10;
	}
      if (yI == 380)
	{
	  yI += 10;
	}
    }
  if (yI >= 190 && yI <= 380)
    {
      if (xI == 30)
	{
	  xI -= 10;
	}
      if (xI == 90)
	{
	  xI += 10;
	}
    }
  //3
  if (xI >= 450 && xI <= 500)
    {
      if (yI == 440)
	{
	  yI -= 10;
	}
      if (yI == 540)
	{
	  yI += 10;
	}
    }
  if (yI >= 440 && yI <= 540)
    {
      if (xI == 450)
	{
	  xI -= 10;
	}
      if (xI == 500)
	{
	  xI += 10;
	}
    }

  //4
  if (xI >= 90 && xI <= 270)
    {
      if (yI == 430)
	{
	  yI -= 10;
	}
      if (yI == 470)
	{
	  yI += 10;
	}
    }
  if (yI >= 430 && yI <= 470)
    {
      if (xI == 90)
	{
	  xI -= 10;
	}
      if (xI == 270)
	{
	  xI += 10;
	}
    }
  //5
  if (xI >= 100 && xI <= 150)
    {
      if (yI == 460)
	{
	  yI -= 10;
	}
      if (yI == 500)
	{
	  yI += 10;
	}
    }
  if (yI >= 460 && yI <= 500)
    {
      if (xI == 100)
	{
	  xI -= 10;
	}
      if (xI == 150)
	{
	  xI += 10;
	}
    }
  //6
  if (xI >= 390 && xI <= 450)
    {
      if (yI == 570)
	{
	  yI -= 10;
	}
      if (yI == 50)
	{
	  yI += 10;
	}
    }
  if (yI >= 0 && yI <= 50)
    {
      if (xI == 390)
	{
	  xI -= 10;
	}
      if (xI == 450)
	{
	  xI += 10;
	}
    }
  //7
  if (xI >= 330 && xI <= 580)
    {
      if (yI == 90)
	{
	  yI -= 10;
	}
      if (yI == 130)
	{
	  yI += 10;
	}
    }
  if (yI >= 90 && yI <= 130)
    {
      if (xI == 330)
	{
	  xI -= 10;
	}
      if (xI == 0)
	{
	  xI += 10;
	}
    }

}

void
vehicle::l3Collision ()
{				//collision for level 1

  //8
  l1Collision ();
  l2Collision ();
  if (xI >= 390 && xI <= 450)
    {
      if (yI == 570)
	{
	  yI -= 10;
	}
      if (yI == 50)
	{
	  yI += 10;
	}
    }
  if (yI >= 0 && yI <= 50)
    {
      if (xI == 390)
	{
	  xI -= 10;
	}
      if (xI == 450)
	{
	  xI += 10;
	}
    }
  //9
  if (xI >= 420 && xI <= 540)
    {
      if (yI == 280)
	{
	  yI -= 10;
	}
      if (yI == 410)
	{
	  yI += 10;
	}
    }
  if (yI >= 280 && yI <= 410)
    {
      if (xI == 420)
	{
	  xI -= 10;
	}
      if (xI == 540)
	{
	  xI += 10;
	}
    }
  //10
  if (xI >= 240 && xI <= 420)
    {
      if (yI == 200)
	{
	  yI -= 10;
	}
      if (yI == 240)
	{
	  yI += 10;
	}
    }
  if (yI >= 200 && yI <= 240)
    {
      if (xI == 240)
	{
	  xI -= 10;
	}
      if (xI == 420)
	{
	  xI += 10;
	}
    }
}

vehicle::~vehicle ()
{
  // TODO Auto-generated destructor stub
}
