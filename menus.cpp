#include "menus.h"


Menu::Menu(menu_content mc)
{
    int i;

    n_choices = ARRAY_SIZE(mc.choices[0]);    /* choices items number */
    items = new ITEM* [n_choices+1];
    title_item = new ITEM*;
    *title_item = new_item(mc.title.c_str(), "");
    for(i=0; i<n_choices; ++i)
        items[i] = new_item(mc.choices[i].c_str(), "");
}

Menu::~Menu()
{
    delete [] items;
    delete [] title_item;
}

MENU *Menu::create_menu_title(int h, int w, int y, int x, WINDOW *parent_win)
{
    MENU *menu;
    WINDOW *menu_win;

    /* create title menu */
    menu = new_menu((ITEM **) title_item);
    /* create the window to be associated with the menu */
    menu_win = derwin(parent_win, h, w, y, x);
    keypad(menu_win, TRUE);

    /* set main window and sub window */
    set_menu_win(menu, parent_win);
    set_menu_sub(menu, menu_win);
    set_menu_mark(menu, "");

    post_menu(menu);
    wrefresh(parent_win);

    return menu;
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
    set_menu_mark(menu, "");

    /* post the menu */
    post_menu(menu);
    wrefresh(parent_win);

    return menu;
}
