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

#define NAMEMAX 20 /*seting the max student name*/
#define PHONEMAX 12   /*seting the max student phone*/
#define CLASSNAMEMAX 4 /*seting the max class name*/
#define CHECKINDEX(index,size) (((index)<(size))&&((index)>=0)) /*macro to check the id*/

extern int flag;/*flag to know which function is the calee*/

typedef struct
{
	int id; 
	char name[NAMEMAX];
	unsigned char age;
	char grade;
	char gender;
	char phone[PHONEMAX];
	char class[CLASSNAMEMAX];
}stu_t;

typedef enum 
{
	STUDENT_FOUNDED,
	INVALID_ID,
	INVALID_NAME,
}student_Error_t;

void initStudent(int );/*is used to read the data from the database */
void terminateStudent(int );/*is used to write the data in the database */
void printStudent(const int ,int );/*is used to print student inforamtion*/
student_Error_t lookForStudent(const int ,int *);/*is used to search for  student */
void scanStudent(const int );/*is used to scan new student*/
void scanStudentForEdit(const int );/*is used to scan the modifications*/
student_Error_t scanCheckID(const int ,int *);/*is used to scan id and check it*/
void callStudent(const int );/*is used to call student*/
void swapStudent(const int ,const int );/*is used to swap two student*/
student_Error_t deleteStudent(const int );/*is used to delete student*/
#endif
