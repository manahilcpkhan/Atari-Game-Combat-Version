/*
 * Menu.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: manahil kamran i21-2668
 */

#include "Menu.h"
#include "util.h"

Menu::Menu ()
{
  // TODO Auto-generated constructor stub
  Vchoice = 0;
  Gchoice = 0;
  Cchoice = 0;
  p = new p1vsbots;
  names = new char[100];


}

Menu::~Menu ()
{
  // TODO Auto-generated destructor stub

}

void
Menu::Menu_display ()		//to display menu
{

  DrawSquare (0, 0, 600, colors[BLACK]);
  DrawString (220, 510, "MENU", colors[WHITE]);
  DrawString (100, 460, "To start Ataari:", colors[WHITE]);
  DrawString (100, 430, "Settings", colors[WHITE]);

  DrawString (100, 400, "Choose Vehicle:", colors[WHITE]);
  DrawString (100, 360, "1.Tank Or 2.Helicopter", colors[WHITE]);
  DrawString (100, 310, "Choose Game Mode:", colors[WHITE]);
  DrawString (100, 280, "Player vs computer: press 'm'", colors[WHITE]);
  DrawString (100, 250, "Player vs player: press 'r'", colors[WHITE]);
  DrawString (100, 200, "Press 'Esc' to exit", colors[WHITE]);

}

void
Menu::End_display ()
{				//to display the end slide
  DrawSquare (0, 0, 600, colors[BLACK]);
  DrawString (220, 510, "YOU WINNN!!!!!!!!", colors[WHITE]);
  DrawString (100, 460, "HIGHSCORE:", colors[WHITE]);
  DrawString (110, 430, "Manu: 120", colors[WHITE]);

  DrawString (100, 400, "Credits:", colors[WHITE]);
  DrawString (100, 360, "Game by Manahil.", colors[WHITE]);
  DrawString (100, 310, "Copy right reserved.", colors[WHITE]);
  DrawString (100, 280, " You steal. ", colors[WHITE]);
  DrawString (100, 250, " I hunt you down.", colors[WHITE]);
  DrawString (100, 200, "Press 'Esc' to exit", colors[WHITE]);

}

void
Menu::setVchoice (unsigned char n)
{
  Vchoice = n;
  p->setV (n);


}
