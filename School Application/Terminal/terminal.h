#ifndef TERMINAL_H_
#define TERMINAL_H_

#ifdef terminalfile

#include <time.h>

#include <windows.h>

#endif

void delay(int milli_seconds);/*is used to stay in line for specific time*/
void gotoxy(int x,int y);/*is used to move to specfic (x,y) coordinates on the screen*/
#endif