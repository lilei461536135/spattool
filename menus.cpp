#include "menus.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

Menu::Menu(const char *choices[])
{
    int i;

    n_choices = ARRAY_SIZE(choices);    /* choices items number */
    items = new ITEM* [n_choices];
    for(i=0; i<n_choices; ++i)
        items[i] = new_item(choices[i], choices[i]);
}

Menu::~Menu()
{
    delete [] items;
}

MENU *Menu::create_menu(int h, int w, int y, int x, WINDOW *parent_win)
{
    MENU *menu;
    WINDOW *menu_win;

    /* create menu */
    menu = new_menu((ITEM **) items);
    /* create the window to be associated with the menu */
    menu_win = derwin(parent_win, h, w, y, x);
    keypad(menu_win, TRUE);

    /* set main window and sub window */
    set_menu_win(menu, parent_win);
    set_menu_sub(menu, menu_win);
    set_menu_mark(menu, "*");

    /* post the menu */
    post_menu(menu);
    wrefresh(parent_win);

    return menu;
}
