#ifndef SUBJECT_H_
#define SUBJECT_H_
#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"/*to use gotxy()*/

#define maxOfStudent 100/*set the max number of students in the school*/
#define maxOfSubjects 5/*to set the man number of subjects*/

typedef struct subj_t
{
	int degree[maxOfSubjects];/*array of student's degrees in each subject*/
}subj_t;

void initSubject(int );/*is used to read from the database and intialize the array with it*/
void terminateSubject(int );/*is used to update  the database with the new values in the array*/
void printSubject(const int ,int );/*is used to take the id as the index of the array of degrees that needed to be printed */
void scanSubject(const int );/*is used to scan the degrees of subjects of new student*/
void scanSubjecttForEdit(const int );/*is used to to scan the modificated degrees student*/
void swapSubjects(const int  ,const int );/*is used to swap bewtwwn to elements of type subj_t*/
void deleteSubject(const int ,const int );/*is used to delete the degrees of a student*/
#endif
