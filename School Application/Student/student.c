#define studentfile
#include "student.h"

/*global variable to get the next y coordinates to print */
int yLocation=0;

/*global array of stu_t type to intialize the databae for the first time only*/
stu_t students[maxOfStudent]={{0,"Ahmed Essam",22,'A','M',"01098114283","5/2"},{1,"Ahmed Rezk",21,'A','M',"01001525033","1/6"},{2,"Ziyad Kassem",20,'F','M',"01011225566","4/2"},{3,"Sama Essam",14,'B','F',"01055659863","2/2"}};

/*this function to read from the database  and intialize the array with it then it 
 calls another funtion to intialize other arrays in another files                 */
 
void initStudent(int stdnumber)
{
	FILE *fp;/*decleration of a pointer to file*/
	fp=fopen("student.txt","rb");/*open the file to read*/
	if(fp==NULL)
	{
		printf("\n Error can't open file");/*if there's a problem with opening it print this message*/
	}
	fread(students,sizeof(stu_t),stdnumber,fp);/*to read all the data from the file*/
	fclose(fp);/*close the file*/
	initSubject(stdnumber);/*call another function to intialize the array in it's file*/
}

/*this function to update  the database with the new values in the array  
 then calls another funtion to update others databases of another files    */
 
void terminateStudent(int stdnumber)
{
	FILE *fp;/*decleration of a pointer to file*/
	fp=fopen("student.txt","wb");/*open the file to write*/
	if(fp==NULL)
	{
		printf("\n Error can't open file");/*if there's a problem with opening it print this message*/
	}
	fwrite(students,sizeof(stu_t),stdnumber,fp);/*to write all the array in the file*/
	fclose(fp);/*close the file*/
	terminateSubject(stdnumber);/*call another function to update other databases*/
	
}

/*function to print the student information by taking the index of this student
and print in the appropiate place it needs the size to reset the ylocation   */

void printStudent(const int index,int size)
{
	/*****************************************************************************/
	/*****************************************************************************/
	/****************** get the appropiate place and print ***********************/
	/*****************************************************************************/
	/*****************************************************************************/
	gotoxy(1,4+yLocation+1);
	printf("%3d",students[index].id);
	gotoxy(6,4+yLocation+1);
	printf("    %s",students[index].name);
	gotoxy(28,4+yLocation+1);
	printf("%3d",students[index].age);
	gotoxy(40,4+yLocation+1);
	printf("%c",students[index].gender);
	gotoxy(49,4+yLocation+1);
	printf("%s",students[index].class);
	gotoxy(60,4+yLocation+1);
	printf("%c",students[index].grade);
	gotoxy(67,4+yLocation+1);
	printf("%s",students[index].phone);
	printSubject(index,size);
	yLocation+=2;/*increase the y coordinates by 2 to print the next student in the appropiate place*/
	if(index==(size-1)||flag)
	{
		yLocation=0;/*if the last student information is printed or there's only one student to print reset ylocation */
	}
}

/*this function scan name then compare it with other names in the array
if it's founded it return it's index else it return -1               */

student_Error_t lookForStudent(const int size,int *index)
{
	int i;
	char key[NAMEMAX],flag=0;
	printf("Name of Student: ");
	strScan(key,NAMEMAX);/*scan the name to search*/
	for(i=0;i<size;i++)
	{
		if(str_compare(key,students[i].name)==0)/*linear search for the student name in the array*/
		{
			flag=1;/*if it's founded set the flag and break*/
			break;
		}
	}
	if(flag)
	{
		*index=i;
		return STUDENT_FOUNDED;/*if the flag =1 then i is index of this student return it*/
	}
	else 
	{
		return INVALID_NAME;/*if the flag=0 the student isn't founded so return -1 */
	}
}

/*this function to scan new student from the user and print it after scanning*/

void scanStudent(const int index)
{
	students[index].id=index;/*to set the id automatically*/
	printf("Name :");
	strScan(students[index].name,NAMEMAX);/*scan the user's name*/
	printf("\nAge: ");
	scanf("%d",&(students[index].age));/*scan the user's age*/
	printf("\nGender: ");
	fflush(stdin);/*clear the buffer*/
	scanf(" %c",&(students[index].gender));/*scan the user's gender*/
	printf("\nClass: ");
	strScan(students[index].class,3);/*scan the user's class*/
	printf("\nGrade: ");
	fflush(stdin);/*clear the buffer*/
	scanf(" %c",&(students[index].grade));/*scan the user's grade*/
	printf("\nPhone: ");
	strScan(students[index].phone,PHONEMAX);/*scan the user's phone*/
	scanSubject(index);/*call another function to scan this student degrees*/
	flag=1;/*set the flag*/
	system("cls");/*To clear the terminal screen*/
	printStudent(index,index+1);/*to print this student information after the scanning*/
	flag=0;/*reset the flag*/
	
}

/*this function to  scan the new information to edit and print it after scanning*/

void scanStudentForEdit(const int index)
{
	char key,age;
	students[index].id=index;/*to set the id automatically*/
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("Do uou want to edit name[y/n]: ");
	scanf(" %c",&key);/*if the user enter y then name need to be edited*/
	if(key=='y'||key=='Y')
	{
		gotoxy(6,5);/*the appropriate place in the screen to the next print */
		printf("                   ");
		gotoxy(6,5);/*the appropriate place in the screen to the next print */
		strScan(students[index].name,NAMEMAX);/*scan the name*/
	}
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("                                         ");
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("Do uou want to edit age[y/n]: ");
	scanf(" %c",&key);/*if the user enter y then age need to be edited*/
	if(key=='y'||key=='Y')
	{
		gotoxy(28,5);/*the appropriate place in the screen to the next print */
		printf("    ");
		gotoxy(28,5);/*the appropriate place in the screen to the next print */
		scanf("%d",&(age));/*scan the age in variable becuse %d scan 4 byte and age of the struct is of char type so scan it in variable of int and cast it */
		students[index].age=(unsigned char)age;/*cast the variable age and assign it to the struct member*/
	}
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("                                         ");
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("Do uou want to edit gender[y/n]: ");/*if the user enter y then gender need to be edited*/
	scanf(" %c",&key);
	if(key=='y'||key=='Y')
	{
		gotoxy(40,5);/*the appropriate place in the screen to the next print */
		printf("     ");
		gotoxy(40,5);/*the appropriate place in the screen to the next print */
		fflush(stdin);/*clear the buffer*/
		scanf(" %c",&(students[index].gender));/*scan the gender*/
	}
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("                                         ");
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("Do uou want to edit Class[y/n]: ");
	scanf(" %c",&key);/*if the user enter y then class need to be edited*/
	if(key=='y'||key=='Y')
	{
		gotoxy(49,5);/*the appropriate place in the screen to the next print */
		printf("      ");
		gotoxy(49,5);/*the appropriate place in the screen to the next print */
		fflush(stdin);/*clear the buffer*/
		strScan(students[index].class,3);/*scan the class*/
	}
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("                                         ");
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("Do uou want to edit Grade[y/n]: ");
	scanf(" %c",&key);/*if the user enter y then grade need to be edited*/
	if(key=='y'||key=='Y')
	{
		gotoxy(60,5);/*the appropriate place in the screen to the next print */
		printf("     ");
		gotoxy(60,5);/*the appropriate place in the screen to the next print */
		fflush(stdin);/*clear the buffer*/
		scanf(" %c",&(students[index].grade));/*scan the grade*/
	}
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("                                         ");
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("Do uou want to edit Phone[y/n]: ");
	scanf(" %c",&key);/*if the user enter y then phone need to be edited*/
	if(key=='y'||key=='Y')
	{
		gotoxy(67,5);/*the appropriate place in the screen to the next print */
		printf("            ");
		gotoxy(67,5);/*the appropriate place in the screen to the next print */
		strScan(students[index].phone,PHONEMAX);/*scan the phone*/
	}
	scanSubjecttForEdit(index);/*call another function to scan the subjects degree*/
	
}

/*this function to scan id and check it if valid return the id else return -1*/

student_Error_t scanCheckID(const int size,int *index)
{
	int id;
	student_Error_t state;
	gotoxy(4,6+(size*2));/*the appropriate place in the screen to the next print */
	printf("ID To Edit :");
	scanf("%d",&id);/*scan the id*/
	system("cls");/*To clear the terminal screen*/
	 if(CHECKINDEX(id,size))/*if the id is valid return it*/
	 {
		 state= STUDENT_FOUNDED;
		 *index=id;
	 }
	 else
	 {
		 gotoxy(2,3);/*the appropriate place in the screen to the next print */
		 printf("There's No Student With This ID...");
		 printf("\a");/*make sound of error*/
		 state= INVALID_ID;/*if id isn't valid return -1*/
		 *index=-1;
	 }
	 return state;
}

/*this function call another one to search for the student if founded print some 
information about him/her and print "calling"                                 */

void callStudent(const int size)
{
	
	int index;
	student_Error_t state =lookForStudent(size,&index);/*search for the student and get the id*/
	if(state==STUDENT_FOUNDED)/*if founded*/
	{
		system("cls");/*To clear the terminal screen*/
		gotoxy(2,3);/*the appropriate place in the screen to the next print */
		printf("Name: %s",students[index].name);
		gotoxy(2,4);/*the appropriate place in the screen to the next print */
		printf("Phone: %s",students[index].phone);
		gotoxy(2,5);/*the appropriate place in the screen to the next print */
		printf("Calling");
		delay(400);/*delay for 400 msecond*/
		for(int i=0;i<4;i++)
		{
			gotoxy(11,5);/*the appropriate place in the screen to the next print */
			printf("            ");
			gotoxy(11,5);/*the appropriate place in the screen to the next print */
			printf(" .");
			Beep(500, 700);/*make sound indication*/
			delay(400);/*delay for 400 msecond*/
			printf(" .");
			Beep(500, 700);/*make sound indication*/
			delay(400);/*delay for 400 msecond*/
			printf(" .");
			delay(400);/*delay for 400 msecond*/
		}
		gotoxy(18,5);/*the appropriate place in the screen to the next print */
		printf("    No Answer  ");
		delay(1500);/*delay for 1500 msecond*/
	}
	else
	{
		gotoxy(2,3);/*the appropriate place in the screen to the next print */
		 printf("There's No Student With This Name...");
		 printf("\a");/*make sound of error*/
	}
}

/*to swap two student in the array*/

void swapStudent(const int stdA,const int stdB)
{
	stu_t temp=students[stdA];
	students[stdA]=students[stdB];
	students[stdB]=temp;
}

/*this function to delete student scaning id then swap the other students and bring 
one to be deleted at the end and decrease the number of the students by 1
so when the user need to add 1 the user overwrite on                          */

student_Error_t deleteStudent(const int size)
{
	int id;
	gotoxy(4,6+(size*2));/*the appropriate place in the screen to the next print */
	printf("id To Delete: ");
	scanf("%d",&id);/*scan the id*/
	if(CHECKINDEX(id,size))
	{
		for(int i=id+1;i<size;i++)
		{
			(students[i].id)--;/*decrease student id after one to be deleted by 1 before swaping*/
			swapStudent(i-1,i);/*swap the student to be deleted with next one*/
		}
		deleteSubject(id,size);/*call a function to delete his/subjects degree*/
		return STUDENT_FOUNDED;/*return 1 if deleated*/
		
	}
	else
	{
		system("cls");/*To clear the terminal screen*/
		gotoxy(2,3);/*the appropriate place in the screen to the next print */
		printf("There's No Student With This ID...");
		printf("\a");/*make sound of error*/
		return INVALID_ID;/*return 0 if not deleated*/
	}
}
