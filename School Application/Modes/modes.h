#ifndef MODES_H_
#define MODES_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   /*to call getch() functions*/

#include "outline.h" /*to print the outline of table on each mode*/
#include "terminal.h"/*to use function gotoxy() and delay()*/
#include "school.h"  /*to see the school layer */

void chooseMode();
void mode1();/*is used to print the school and print the outline of this mode */
void mode2();/*is used to call look for Student and print the data */
void mode3();/*is used to call add Student to the school and print the data after collecting it */
void mode4();/*is used to call edit Student and appropriate outline and print the data */
void mode5();/*is used to call Delete Student and print appropriate outline*/
void mode6();/*is used to call a Student */

#endif