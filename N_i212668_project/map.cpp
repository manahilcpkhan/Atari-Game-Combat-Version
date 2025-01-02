/*
 * map.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: manahil
 */

#include "map.h"

map::map ()
{
  // TODO Auto-generated constructor stub
  red = 0;
  green = 0;
  blue = 0;
//obstacle=0;

  obstacle = GetRandInRange (1, 4);
  background ();
}

map::map (double r, double g, double b, int o)
{				//parametreised constructor
  if (r <= 1)
    {
      red = r;
    }
  if (g <= 1)
    {
      green = g;
    }
  if (b <= 1)
    {
      blue = b;
    }
  else
    {
      red = 0;
      green = 0;
      blue = 0;
    }
  obstacle = o;
  cout << "start";
  background ();
  cout << "end";

}

void
map::background ()
{				//to display the background of game
  glClearColor (red + 0.2 /*Red Component */ , green - 0.3,	//148.0/255/*Green Component*/,
		blue + 0.3 /*Blue Component */ , 0 /*Alpha component */ );	// Red==Green==Blue==1 --> White Colour


  glClear (GL_COLOR_BUFFER_BIT);	//Update the colors

  DrawLine (0, 601, 600, 601, 2, colors[BLACK]);
  DrawLine (30, 0, 30, 600, 1, colors[AQUA]);
  DrawLine (60, 0, 60, 600, 1, colors[AQUA]);
  DrawLine (90, 0, 90, 600, 1, colors[AQUA]);
  DrawLine (120, 0, 120, 600, 1, colors[AQUA]);
  DrawLine (150, 0, 150, 600, 1, colors[AQUA]);
  DrawLine (180, 0, 180, 600, 1, colors[AQUA]);
  DrawLine (210, 0, 210, 600, 1, colors[AQUA]);
  DrawLine (240, 0, 240, 600, 1, colors[AQUA]);
  DrawLine (270, 0, 270, 600, 1, colors[AQUA]);
  DrawLine (300, 0, 300, 600, 1, colors[AQUA]);
  DrawLine (330, 0, 330, 600, 1, colors[AQUA]);
  DrawLine (360, 0, 360, 600, 1, colors[AQUA]);
  DrawLine (390, 0, 390, 600, 1, colors[AQUA]);
  DrawLine (420, 0, 420, 600, 1, colors[AQUA]);
  DrawLine (450, 0, 450, 600, 1, colors[AQUA]);
  DrawLine (480, 0, 480, 600, 1, colors[AQUA]);
  DrawLine (510, 0, 510, 600, 1, colors[AQUA]);
  DrawLine (540, 0, 540, 600, 1, colors[AQUA]);
  DrawLine (570, 0, 570, 600, 1, colors[AQUA]);
  DrawLine (600, 0, 600, 600, 1, colors[AQUA]);
  randomdraw ();
}

void
map::randomdraw ()
{				//to select which obstacle function to display in each level

  if (obstacle == 2)
    {
      drawbuilding2 ();
    }
  else if (obstacle == 3)
    {
      drawbuilding3 ();
    }
  else
    {
      drawbuilding4 ();
    }
}

map::~map ()
{
  // TODO Auto-generated destructor stub
}


void
map::drawbuilding2 ()
{				//function to draw obstacles
  DrawRectangle (60, 180, 120, 30, colors[DARK_VIOLET]);	//1
  DrawRectangle (60, 210, 30, 180, colors[DARK_VIOLET]);	//2
  DrawRectangle (480, 460, 30, 90, colors[DARK_VIOLET]);	//3
}

void
map::drawbuilding3 ()
{				//function to draw obstacles
  DrawRectangle (120, 450, 150, 30, colors[DARK_VIOLET]);	//4
  DrawSquare (120, 480, 30, colors[DARK_VIOLET]);	//5
  DrawRectangle (420, 0, 30, 60, colors[DARK_VIOLET]);	//6
  DrawRectangle (360, 110, 240, 30, colors[DARK_VIOLET]);	//7
  DrawRectangle (60, 180, 120, 30, colors[DARK_VIOLET]);	//1
  DrawRectangle (60, 210, 30, 180, colors[DARK_VIOLET]);	//2
  DrawRectangle (480, 460, 30, 90, colors[DARK_VIOLET]);	//3
}

void
map::drawbuilding4 ()
{				//function to draw obstacles
  DrawRectangle (420, 0, 30, 60, colors[DARK_VIOLET]);	//8
  DrawRectangle (450, 300, 90, 120, colors[DARK_VIOLET]);	//9
  DrawRectangle (270, 220, 150, 30, colors[DARK_VIOLET]);	//10
  DrawRectangle (120, 450, 150, 30, colors[DARK_VIOLET]);	//4
  DrawSquare (120, 480, 30, colors[DARK_VIOLET]);	//5
  DrawRectangle (420, 0, 30, 60, colors[DARK_VIOLET]);	//6
  DrawRectangle (360, 110, 240, 30, colors[DARK_VIOLET]);	//7
  DrawRectangle (60, 180, 120, 30, colors[DARK_VIOLET]);	//1
  DrawRectangle (60, 210, 30, 180, colors[DARK_VIOLET]);	//2
  DrawRectangle (480, 460, 30, 90, colors[DARK_VIOLET]);	//3
}
