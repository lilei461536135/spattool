#include "menus.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

Menu::Menu(int height, int width, int starty, int startx, char *choices[]);
{
    ITEM **items;
    MENU *menu;
    WINDOW *menu_win;
    int n_choices;
    int i;

    n_choices = ARRAY_SIZE(choices);    /* choices items number */
    items = (ITEM **) new [n_choices];
    for(i=0; i<n_choices; ++i)
        items[i] = new_item(choices[i], choices[i]);

    /* create menu */
    menu = new_menu((ITEM **) items);
    /* create the window to be associated with the menu */
    menu_win = newwin(height, width, starty, startx);
    keypad(menu_win, TRUE);

    /* set main window and sub window */
    set_menu_win(menu, menu_win);
    set_menu_sub(menu, derwin(menu_win, ))
}
