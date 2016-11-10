#include <iostream>
#include <ncurses.h>
#include <stdio.h>

using namespace std;

WINDOW *create_mainwin(int height, int width);
void del_mainwin(WINDOW *win);

int main(int argc, char *argv[])
{
    WINDOW * window;

    //Initialize standard screen
    initscr();              /* Start curses mode        */
    cbreak();               /* Line buffering mode      */
    noecho();               /* Disable echo mode        */
    keypad(stdscr, TRUE);   /* Enable keyboard input    */
    curs_set(0);            /* Disable curse display    */
    refresh();              /* Refresh stdandard screen */

    window = create_mainwin(20, 40);

    getch();

    del_mainwin(window);
    //refresh();

    while(1);
    endwin();               /* release resources */

    return 0;
}

WINDOW *create_mainwin(int height, int width)
{
    WINDOW *win;
    int starty, startx;
    char name[] = "spatt";
    int name_len;
    int i;

    //Create main window
    height = 20;
    width = 60;

    name_len = sizeof(name);

    starty = (LINES - height)  / 2;
    startx = (COLS - width) / 2;

    win = newwin(height, width, starty, startx); /* create new window */
    box(win, 0, 0);                              /* draw boundary of new window */
    mvwhline(win, 2, 1, ACS_HLINE, width-2);     /* draw a line */
    for(i=0; i<name_len-1; i++)
        mvwaddch(win, starty+1, startx+(width-name_len)/2+i, name[i]);
    wrefresh(win);

    return win;
}

void del_mainwin(WINDOW *win)
{
    werase(win);
    wrefresh(win);
    delwin(win);    /* delete window */
}