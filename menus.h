#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <menu.h>

class Menu
{
private:
    ITEM **items;
    int n_choices;
public:
    Menu(const char *choices[]);
    ~Menu();
    MENU *create_menu(int h, int w, int y, int x, WINDOW *parent_win);
};

#endif // MENUS_H_INCLUDED
