
#ifndef SCHOOL_H_
#define SCHOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>/* to use the file operations*/

#include "terminal.h"/*to use function gotoxy()*/

#ifdef schoolfile
#include "student.h"/*to see the student layer */
#endif

#define MAXSTUDENTS 100 /*to set the max allowable number of the students in the school*/
#define NAMEMAX 20 /*to set the max allowable number of char in name*/

/*a new type to define the school*/

typedef struct school
{
	char name[NAMEMAX];/*the name of the school*/
	int stdnumber;/*current number of the students in the school*/
	int std[MAXSTUDENTS];/*array that have intgers that refers to IDS*/
}school_t;

typedef enum 
{
	APPROVED_OPERATION,
	DECLINED_OPERATION
	
}school_Error_t;

void initSchool();/*is used to read the data from the database */
void terminateSchool();/*is used to write the data in the database */
int getNumberOfStudent();/*is used to return the current number of the students */
void printSchool();/*is used to print all the students in the school*/
school_Error_t printSpecificStudent();/*is used to print specifin student in the school*/
school_Error_t addStudentToSchool();/*is used to add new student to the school*/
school_Error_t checkStudentInSchool(int *);/*is used to check if this student in the school*/
void editStudentInSchool();/*is used to edit student information*/
void callStudentInSchool();/*is used to call student in the school*/
school_Error_t deleteStudentInSchool();/*is used to delete student from the school*/

#endif
