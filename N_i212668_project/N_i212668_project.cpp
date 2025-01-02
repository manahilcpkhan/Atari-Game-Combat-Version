//============================================================================
// Name        : ManahilKamran N_i21-2668
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include "Menu.h"
#include "canon.h"
#include "p1vsbots.h"
#include "p1vsp2.h"
#include <iostream>
#include<string>
#include<cmath>			// for basic math functions such as cos, sin, sqrt
using namespace std;
static Menu m;
static p1vsbots a;
static p1vsp2 b;
static canon c (a);
int lastnonprint_key;
unsigned char lastprint_key;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void
SetCanvasSize (int width, int height)
{
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glOrtho (0, width, 0, height, -1, 1);	// set the screen size to given width and height.
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
}

/*
 * Main Canvas drawing function.
 * */

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
static bool flag_m = true, flag_r = true;
void
Timer (int m)
{				//for timely movement of bot, canon, collision


  a.moveBot1 ();
  a.moveBot2 ();
  a.moveBot3 ();
  a.l1Collision ();

  a.l2Collision ();
  a.l3Collision ();

  c.moveCanon ();


  // once again we tell the library to call our Timer function after next 1000/FPS
  glutTimerFunc (100, Timer, 0);
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void
NonPrintableKeys (int key, int x, int y)
{
  lastnonprint_key = key;

  a.control1 (key);		//for arrow controls of player
  if (flag_r == false)
    b.control1 (key);
  glutPostRedisplay ();

}


/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void
PrintableKeys (unsigned char key, int x, int y)
{				//for letter controls of a player
  lastprint_key = key;
  a.control2 (key);

  a.l1Collision ();

  a.l2Collision ();

  a.l3Collision ();

  if (flag_r == false)
    {
      b.control2 (key);
      b.l1Collision ();

      b.l2Collision ();

      b.l3Collision ();
    }

  if (key == 27 /* Escape key ASCII */ )
    {
      exit (1);			// exit the program when escape key is pressed.
    }

  if (key == 'b' || key == 'B')	//Key for placing the bomb
    {
      c.flag = false;
      c.canonbot ();
      //shoot small canon is pressed
      cout << "b pressed" << endl;
    }

  if (key == 'v' || key == 'V')	//Key for placing the bomb
    {
      c.flag = false;
      c.canonbot ();
      //shoot medium canon v is pressed
      cout << "v pressed" << endl;
    }

  if (key == 'C' || key == 'c')	//Key for placing the bomb
    {
      c.flag = false;
      c.canonbot ();
      //shoot large canon if c is pressed
      cout << "v pressed" << endl;
    }
  if (key == 'm' || key == 'M')
    {				//to display menu
      flag_m = false;

    }
  if (key == 'r' || key == 'R')
    {
      flag_m = false;
      flag_r = false;
    }
  if (key == '1')
    {				//to choose vehicle
      a.setV (key);
    }
  if (key == '2')
    {				//to choose vehicle
      a.setV (key);
    }

  glutPostRedisplay ();
}


void
GameDisplay ()
  /**/
{
  // set the background color using function glClearColor.

  glClearColor (0 /*Red Component */ , 0,	//148.0/255/*Green Component*/,
		0.0 /*Blue Component */ , 0 /*Alpha component */ );	// Red==Green==Blue==1 --> White Colour
  glClear (GL_COLOR_BUFFER_BIT);	//Update the colors

  a.level1 ();			//to display level 1
  c.directionCanon (lastnonprint_key, lastprint_key);	//selection of canon size and speed and direction wrt to arrow keys
  if (a.score >= 10)
    {
      c.reset ();		//to reset bools
      a.level2 ();		//to display level 2
      c.directionCanon (lastnonprint_key, lastprint_key);	//selection of canon size and speed and direction wrt to arrow keys
    }
  if (a.score >= 30)
    {
      c.reset ();		//to reset bools
      a.level3 ();		//to display level 3
      c.directionCanon (lastnonprint_key, lastprint_key);	//selection of canon size and speed and direction wrt to arrow keys
    }

  if (flag_r == false)
    {
      b.level1 ();		//to display level 1
      // c.directionCanon (lastnonprint_key, lastprint_key); //selection of canon size and speed and direction wrt to arrow keys
      if (b.score >= 10)
	{
	  // c.reset ();             //to reset bools
	  b.level2 ();		//to display level 2
	  //c.directionCanon (lastnonprint_key, lastprint_key);     //selection of canon size and speed and direction wrt to arrow keys
	}
      if (b.score >= 30)
	{
	  // c.reset ();             //to reset bools
	  b.level3 ();		//to display level 3
	  //c.directionCanon (lastnonprint_key, lastprint_key);     //selection of canon size and speed and direction wrt to arrow keys
	}
    }

  DrawString (10, 610, "score" + to_string (a.score), colors[WHITE]);	//to display score
  if (a.score >= 60)
    {
      m.End_display ();		//to diplay end slide
    }

  if (flag_m)
    {
      m.Menu_display ();	//to display menu
    }
  glutSwapBuffers ();		// do not modify this line..
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void
MousePressedAndMoved (int x, int y)
{
  cout << x << " " << y << endl;
  glutPostRedisplay ();
}

void
MouseMoved (int x, int y)
{
  //cout << x << " " << y << endl;
  glutPostRedisplay ();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void
MouseClicked (int button, int state, int x, int y)
{

  if (button == GLUT_LEFT_BUTTON)	// dealing only with left button
    {
      cout << GLUT_DOWN << " " << GLUT_UP << endl;

    }
  else if (button == GLUT_RIGHT_BUTTON)	// dealing with right button
    {
      cout << "Right Button Pressed" << endl;

    }
  glutPostRedisplay ();
}

/*
 * our gateway main function
 * */
int
main (int argc, char *argv[])
{

  int width = 600, height = 640;	// i have set my window size to be 800 x 600

  InitRandomizer ();		// seed the random number generator...
  glutInit (&argc, argv);	// initialize the graphics library...
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);	// we will be using color display mode
  glutInitWindowPosition (50, 50);	// set the initial position of our window
  glutInitWindowSize (width, height);	// set the size of our window
  glutCreateWindow ("Ataari by Mannu");	// set the title of our game window
  SetCanvasSize (width, height);	// set the number of pixels...


  // Register your functions to the library,
  // you are telling the library names of function to call for different tasks.
  //glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

  glutDisplayFunc (GameDisplay);	// tell library which function to call for drawing Canvas.
  glutSpecialFunc (NonPrintableKeys);	// tell library which function to call for non-printable ASCII characters
  glutKeyboardFunc (PrintableKeys);	// tell library which function to call for printable ASCII characters
  // This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
  glutTimerFunc (1.0, Timer, 0);

  glutMouseFunc (MouseClicked);
  glutPassiveMotionFunc (MouseMoved);	// Mouse
  glutMotionFunc (MousePressedAndMoved);	// Mouse


  // now handle the control to library and it will call our registered functions when
  // it deems necessary...
  glutMainLoop ();
  return 1;
}
#endif /* RushHour_CPP_ */
