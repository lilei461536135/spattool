#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <menu.h>
#include <string>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

using namespace std;

struct menu_content
{
    string title;
    string choices[2];
    string quick[2];
};

class Menu
{
private:
    ITEM **items;
    ITEM **title_item;
    int n_choices;
public:
    Menu(menu_content mc);
    ~Menu();
    MENU *create_menu_title(int h, int w, int y, int x, WINDOW *parent_win);
    MENU *create_menu(int h, int w, int y, int x, WINDOW *parent_win);
};

#endif // MENUS_H_INCLUDED
