/*
 * canon.cpp
 *
 *  Created on: Jun 6, 2022
 *      Author: manahil  kamran i21-2668
 */

#include "canon.h"
canon::canon (p1vsbots & obj):player (obj)
{				//copy constructor
  flag = true;
}

void
canon::canonbot ()
{
  // TODO Auto-generated constructor stub

  bx1 = player.getBx1 ();
  by1 = player.getBy1 ();
  bx2 = player.getBx2 ();
  by2 = player.getBy2 ();
  bx3 = player.getBx3 ();
  by3 = player.getBy3 ();
  x = player.getP1 ().xI;
  y = player.getP1 ().yI;

}

void
canon::directionCanon (int key, unsigned char choice)
{				//selection of canon size and speed and direction wrt to arrow keys
  if (key == GLUT_KEY_LEFT)
    {

      if (flag == false)
	{
	  x -= 5;
	  if (choice == 'b' || choice == 'B')
	    {

	      DrawCircle (x, y + 10, 4, colors[BLACK]);
	      glutPostRedisplay ();
	    }

	  else if (choice == 'v' || choice == 'V')
	    {

	      medium ();


	      glutPostRedisplay ();
	    }
	  else if (choice == 'c' || choice == 'C')
	    {

	      large ();

	      glutPostRedisplay ();
	    }

	}

    }
  else if (key == GLUT_KEY_RIGHT)
    {

      if (flag == false)
	{
	  x += 5;
	  if (choice == 'b' || choice == 'B')
	    {

	      small ();
	      glutPostRedisplay ();
	    }

	  else if (choice == 'v' || choice == 'V')
	    {

	      medium ();
	      glutPostRedisplay ();
	    }
	  else if (choice == 'c' || choice == 'C')
	    {

	      large ();
	      glutPostRedisplay ();
	    }
	}
    }
  else if (key == GLUT_KEY_UP)
    {

      if (flag == false)
	{
	  y += 5;
	  if (choice == 'b' || choice == 'B')
	    {

	      small ();
	      glutPostRedisplay ();
	    }

	  else if (choice == 'v' || choice == 'V')
	    {

	      medium ();
	      glutPostRedisplay ();
	    }
	  else if (choice == 'c' || choice == 'C')
	    {

	      large ();
	      glutPostRedisplay ();
	    }
	}
    }
  else if (key == GLUT_KEY_DOWN)
    {

      if (flag == false)
	{
	  y -= 5;
	  if (choice == 'b' || choice == 'B')
	    {

	      small ();
	      glutPostRedisplay ();
	    }

	  else if (choice == 'v' || choice == 'V')
	    {

	      medium ();
	      glutPostRedisplay ();
	    }
	  else if (choice == 'c' || choice == 'C')
	    {

	      large ();
	      glutPostRedisplay ();
	    }
	}
    }
}

void
canon::small ()
{				//small canon
  DrawCircle (x, y + 10, 4, colors[BLACK]);
}

void
canon::medium ()
{				//medium canon
  DrawCircle (x, y + 10, 6, colors[BLACK]);
}

void
canon::large ()
{				//large canon
  DrawCircle (x, y + 10, 8, colors[BLACK]);
}

void
canon::moveCanon ()
{				//movement of canon and score increment if the canon shoots bot
  if (flag == false)
    {
      //y+=10;
      if (((y >= by1) && (y <= by1 + 30)) && ((x >= bx1) && (x <= bx1 + 30)))
	{
	  flag = true;
	  player.displayB1 = true;
	  player.score += 10;
	}
      else if (((y >= by2) && (y <= by2 + 30))
	       && ((x >= bx2) && (x <= bx2 + 30)))
	{
	  flag = true;
	  player.score += 10;
	  player.displayB2 = true;
	}
      else if (((y >= by3) && (y <= by3 + 30))
	       && ((x >= bx3) && (x <= bx3 + 30)))
	{
	  flag = true;
	  player.score += 10;
	  player.displayB3 = true;
	}


    }
  else if ((y <= 0) || (y >= 580))
    flag = true;
  else if ((x <= 0) || (x >= 580))
    flag = true;
}

void
canon::reset ()			// resets bool conditions
{
  flag = false;
  player.displayB1 = true;
  player.displayB2 = true;
  player.displayB3 = true;
}

canon::~canon ()
{
  // TODO Auto-generated destructor stub
}
