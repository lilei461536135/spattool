#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include "menus.h"
#include <string.h>

using namespace std;

WINDOW *create_mainwin(int height, int width);
void del_mainwin(WINDOW *win);


int main(int argc, char *argv[])
{
    WINDOW *p_window;
    MENU *p_menu;
    MENU *p_title_menu;
    menu_content mc_file;

    mc_file.title = " File ";
    mc_file.choices[0] = "Open";
    mc_file.choices[1] = "Exit";

    Menu menu_1(mc_file);

    //Initialize standard screen
    initscr();              /* Start curses mode        */
    cbreak();               /* Line buffering mode      */
    noecho();               /* Disable echo mode        */
    keypad(stdscr, TRUE);   /* Enable keyboard input    */
    curs_set(0);            /* Disable curse display    */
    refresh();              /* Refresh stdandard screen */

    p_window = create_mainwin(20, 60);
    p_title_menu = menu_1.create_menu_title(1, 6, 3, 1, p_window);
    //p_menu = menu_1.create_menu(6, 20, 5, 1, p_window);

    getch();

    del_mainwin(p_window);
    //refresh();

    while(1);
    endwin();               /* release resources */

    return 0;
}

WINDOW *create_mainwin(int height, int width)
{
    WINDOW *win;
    int starty, startx;
    char name[] = "spattool";
    int name_len;
    int i;

    name_len = sizeof(name);

    starty = (LINES - height)  / 2;
    startx = (COLS - width) / 2;

    win = newwin(height, width, starty, startx); /* create new window */
    box(win, 0, 0);
    mvwaddch(win, 2, 0, ACS_LTEE);               /* draw boundary of new window */
    mvwhline(win, 2, 1, ACS_HLINE, width-2);     /* draw a line */
    mvwaddch(win, 2, width-1, ACS_RTEE);
    for(i=0; i<name_len-1; i++)
        mvwaddch(win, 1, (width-name_len)/2+i, name[i]);
    wrefresh(win);

    return win;
}

void del_mainwin(WINDOW *win)
{
    werase(win);
    wrefresh(win);
    delwin(win);    /* delete window */
}
