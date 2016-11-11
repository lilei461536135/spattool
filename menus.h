#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <menu.h>

class Menu()
{
private:

public:
    Menu::Menu(int height, int width, int starty, int startx, char *choices[]);
    Menu::~Menu();
};

#endif // MENUS_H_INCLUDED
