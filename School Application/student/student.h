#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>/*to use beep()*/

#include "terminal.h"/*to use function gotoxy() and delay()*/
#include "string.h"/*to use strscan() and strCompare()*/

#ifdef studentfile
#include "subject.h"/*to see the subject layer */
#endif

#define maxOfStudent 100  /*seting the max number of students*/
#define maxOfStdName 20  /*seting the max student name*/
#define maxOfPhone 12   /*seting the max student phone*/
#define maxClassNumber 4 /*seting the max student class*/
#define checkIndex(index,size) (((index)<(size))&&((index)>=0)) /*macro to check the id*/

extern int flag;/*flag to know which function is the calee*/

typedef struct
{
	int id; 
	char name[maxOfStdName];
	unsigned char age;
	char grade;
	char gender;
	char phone[maxOfPhone];
	char class[maxClassNumber];
}stu_t;

void initStudent(int n);/*is used to read the data from the database */
void terminateStudent(int n);/*is used to write the data in the database */
void printStudent(const int index,int size);/*is used to print student inforamtion*/
int lookForStudent(const int size);/*is used to search for  student */
void scanStudent(const int index);/*is used to scan new student*/
void scanStudentForEdit(const int index);/*is used to scan the modifications*/
int scanCheckID(const int size);/*is used to scan id and check it*/
void callStudent(const int size);/*is used to call student*/
void swapStudent(const int a,int b);/*is used to swap two student*/
int deleteStudent(const int size);/*is used to delete student*/
#endif
