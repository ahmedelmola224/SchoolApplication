#include "modes.h"

/*To let the user choose the mode,
The first function is called in the program,
it intialize the database and update it*/

void chooseMode()
{
	initSchool();/*to intialize the Database of the program and read it */
	while(1)
	{
		/*****************************************************************************/
		/*****************************************************************************/
		/******************Printing the outline of this window************************/
		/*****************************************************************************/
		/*****************************************************************************/
		int key;
	    system("cls");/*To clear the terminal screen*/
		printf("Select The Mode: \n");
		gotoxy(0,2);/*the appropriate place in the screen to the next print */
		printf("1.Print School");
		gotoxy(21,2);/*the appropriate place in the screen to the next print */
		printf("2.Look For Student");	
		gotoxy(45,2);/*the appropriate place in the screen to the next print */
		printf("3.Add Student");
		gotoxy(65,2);/*the appropriate place in the screen to the next print */
		printf("4.Edit Student");
		gotoxy(85,2);/*the appropriate place in the screen to the next print */
		printf("5.Delete Student");
		gotoxy(105,2);/*the appropriate place in the screen to the next print */
		printf("6.Call Student");
		gotoxy(125,2);/*the appropriate place in the screen to the next print */
		printf("7.Quit");
		gotoxy(0,5);/*the appropriate place in the screen to the next print */
		printf("You Choose Mode Number: ");
		scanf("%d",&key);/*take the number of mode the user want in variable 'key'*/
		switch(key)     /*check the number the user enter based on that the appropriate window appear */
		{
			case 1:
			mode1();                      
			break;
			case 2:
			mode2();
			break;
			case 3:
			mode3();
			break;
			case 4:
			mode4();
			break;
			case 5:
			mode5();
			break;
			case 6:
			mode6();
			break;
			case 7:
			terminateSchool();/*in this case the user to quit so the the database need to be saved  */
			return ;/*Return to the main and close the program*/
			break;
		}
	}
		
}


/*it get the number of the student to print the table at the appropriate size
then it call some function from the school file to print all students and their information*/
 
void mode1()
{
	do{
	int stdnumber=getNumberOfStudent();/*to get the number of students  */
	system("cls");/*To clear the terminal screen*/
	modeOutline1(stdnumber);/*to print the table outline*/
	printSchool();/*to print the students after the outline is printed */
	gotoxy(4,6+(stdnumber*2));/*the appropriate place in the screen to the next print */
	printf("Press any key to get back... ");
	}while(!getch());/*if the user press any button the loop end*/
}

/* it call printSpecificStudent to scan the name of student and
 check if he/she exist if founded it print the appropriate outline 
and print the information of this student                        */

void mode2()
{
	int esc;
	do
	{
		system("cls");/*To clear the terminal screen*/
		int founded=printSpecificStudent();/*scan the name and check if it exist in the database and print the information of this student in the school*/
		if(founded)
		{
			modeOutline2();/*to print the appropriate outline*/
			gotoxy(53,1);/*the appropriate place in the screen to the next print */
		printf("Student Search ");
		}
		gotoxy(2,7);/*the appropriate place in the screen to the next print */
		printf("Press Esc now to get back or any button to continue ... ");
		esc=getch();/*if the user press esc button the loop end*/
	}while(esc!=27);
	
}

/*To check if ther's space in the school if true 
take the information of the student and it to the school */

void mode3()
{
	int esc;
	do
	{
		system("cls");/*To clear the terminal screen*/
		int added =addStudentToSchool();/*check if there's enough space in the school if true the students is added*/
		if(added)
		{
		modeOutline3();/*to print the appropriate outline*/
		gotoxy(50,1);/*the appropriate place in the screen to the next print */
		printf("Student Recently Added Information");
		gotoxy(2,7);/*the appropriate place in the screen to the next print */
		printf("Added successfully... ");
		delay(2000);
		}
		else
		{
			printf("School is full ");
			printf("\a");/*to get sound that there's error*/
		}
		gotoxy(2,7);/*the appropriate place in the screen to the next print */
		printf("Press Esc now to get back or any button to continue ... ");
		esc=getch();/*if the user press esc button the loop end*/
	}while(esc!=27);
}

/*it call a function that take the id of the student that needed to be edit
  then it check the id if it is valid enable the user to edit            */
  
void mode4()
{
	int index;
	int esc;
	do{
	int stdnumber=getNumberOfStudent();/*to get the number of students  */
	system("cls");/*To clear the terminal screen*/
	modeOutline1(stdnumber);/*to print the table outline*/
	printSchool();/*to print the students after the outline is printed */
	index=checkStudentInSchool();/*to scan the id and check if this student in the school and get the index if exist or -1 if not*/
	if(index!=-1)/*if the student exist*/
	{
		modeOutline3();/*to print the appropriate outline*/
		editStudentInSchool(index);/*to enable the user to edit the student data*/
		system("cls");/*To clear the terminal screen*/
		modeOutline1(stdnumber);/*to print the appropriate outline*/
		printSchool();/*to print the students after edit */
	}
	
	gotoxy(4,6+(stdnumber*2));/*the appropriate place in the screen to the next print */
	printf("Press Esc now to get back or any button to continue ... ");
	esc=getch();/*if the user press esc button the loop end*/
	}while(esc!=27);
}

/*it call function that prints the  table outline and another function that print it's content 
 then  ask for id if it exist it deletes this student                                       */
 
void mode5()
{
	int index;
	int esc;
	do{
	int stdnumber=getNumberOfStudent();/*to get the number of students  */
	system("cls");/*To clear the terminal screen*/
	modeOutline1(stdnumber);/*to print the appropriate outline*/
	printSchool();/*to print the students of the school */
	int deleted=deleteStudentInSchool();/*call a function that ask for id to delete and return 1 if it's exist*/
	if(deleted)
	{
		system("cls");/*To clear the terminal screen*/
		gotoxy(2,3);/*the appropriate place in the screen to the next print */
		printf("Refresh ");
		delay(300);/*delay for 300 msecond*/
		printf(". ");
		delay(300);/*delay for 300 msecond*/
		printf(". ");
		delay(300);/*delay for 300 msecond*/
		printf(". ");
		delay(300);/*delay for 300 msecond*/
		system("cls");/*To clear the terminal screen*/
		modeOutline1(stdnumber-1);/*to print the appropriate outline after deleting*/
		printSchool();/*to print the students of the school after deleting*/
	}
	gotoxy(4,6+(stdnumber*2));/*the appropriate place in the screen to the next print */
	printf("Press Esc now to get back or any button to continue ... ");
	esc=getch();/*if the user press esc button the loop end*/
	}while(esc!=27);
}

/*it call a funtion that scan the name of student
if it exist in the database it call the student on phone*/

void mode6()
{
	int esc;
	do
	{
	system("cls");/*To clear the terminal screen*/
	callStudentInSchool();
	gotoxy(2,7);/*the appropriate place in the screen to the next print */
	printf("Press Esc now to get back or any button to continue ... ");
	esc=getch();/*if the user press esc button the loop end*/
	}while(esc!=27);
	
}