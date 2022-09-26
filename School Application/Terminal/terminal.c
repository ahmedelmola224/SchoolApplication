#define terminalfile
#include "terminal.h"

/*function to dealy that takes the number of msecond and get the starting time of the function 
while the sum of msecond and starting time is less than the clock now ,stay in the same line*/

void delay(int milli_seconds)
{
    clock_t start_time = clock();/*the starting time of the function*/
    while (clock() < start_time + milli_seconds)
        ;
}

/*function to move to specfic x,y coordinates on the screen*/
void gotoxy(int x,int y)
{
    COORD crd;
    crd.X=x;
    crd.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd);
}



