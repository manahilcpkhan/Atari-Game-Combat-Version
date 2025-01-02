/*
 * Menu.h
 *
 *  Created on: Jun 1, 2022
 *      Author:  manahil kamran i21-2668
 */

#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include<string>
#include "util.h"
#include "p1vsbots.h"
using namespace std;
class Menu
{
  p1vsbots *p;
  unsigned char Vchoice;
  int Gchoice;
  int Cchoice;

public:
  char *names;
    Menu ();
  void Menu_display ();
  void End_display ();
    virtual ~ Menu ();
  void Credit ();
  void setVchoice (unsigned char);
  void setGchoice ();
  void Highscore ();
};

#endif /* MENU_H_ */
