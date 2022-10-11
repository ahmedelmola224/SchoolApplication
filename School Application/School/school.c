#define schoolfile
#include "school.h"

/*glabal variable of school_t type to intialize the database for the first time only */
           /*school name*//*student number*//*students id*/
school_t sch={"MANSOURA SCHOOL",4,{0,1,2,3}};

/*this function to read from the database  and intialize the array with it then it 
 calls another funtion to intialize other arrays in another files                 */

void initSchool()
{
	FILE *fp;/*decleration of a pointer to file*/
	fp=fopen("school.txt","rb");/*open the file to read*/
	if(fp==NULL)
	{
		printf("\n Error can't open file");/*if there's a problem with opening it print this message*/
	}
	fread(&sch,sizeof(school_t),1,fp);/*to read all the data from the file*/
	fclose(fp);/*close the file*/
	initStudent(sch.stdnumber);/*call another function to intialize the array in it's file*/
	
	
}

/*this function to update  the database with the new values in the array  
 calls another funtion to update others databases of another files    */
 
void terminateSchool()
{
	FILE *fp;/*decleration of a pointer to file*/
	fp=fopen("school.txt","wb");/*open the file to write*/
	if(fp==NULL)
	{
		printf("\n Error can't open file");/*if there's a problem with opening it print this message*/
	}
	fwrite(&sch,sizeof(school_t),1,fp);/*to write all the array in the file*/
	fclose(fp);/*close the file*/
	terminateStudent(sch.stdnumber);/*call another function to update other databases*/
}

/*function to return the current number of the students in the school*/

int getNumberOfStudent()
{
	return sch.stdnumber;
}

/*function that's used to print all students in the school
 by calling anoter function that need the id of each student*/

void printSchool()
{
	gotoxy(50,1);/*the appropriate place in the screen to the next print */
	printf("%s STUDENTS TABLE",sch.name);
	for(int i=0;i<sch.stdnumber;i++)
	{

		printStudent(sch.std[i],sch.stdnumber);/*loop through each id and pass it to print student function */
	}
}

/*calls a function that look for the student name in the school
 if it exists then it prints this student information 
 and return APPROVED_OPERATION to print the appropriate outline 
 if it's not exist it returns DECLINED_OPERATION                               */

school_Error_t printSpecificStudent()
{
	int index;/*to get the index of the student to print it's information*/
	student_Error_t std_state=lookForStudent(sch.stdnumber,&index);
	school_Error_t school_state;
	if(std_state==STUDENT_FOUNDED)/*if the student exist*/
	{
		flag=1;/*global variable in another file to let the printStudent function that printSpecificStudent ()is the calee */
		printStudent(index,sch.stdnumber);/*print the whole infrmation*/
		flag=0;/*reset it again*/
		school_state=APPROVED_OPERATION;
	}
	else
	{
		printf("\nThere's no student with this name");
		printf("\a");
		school_state=DECLINED_OPERATION;/*the student isn't exist so doesn't */
	}
	return school_state;
}

/*This function check if the school is full or not
 if not it sets an id for the new student then 
 call anoter function to scan the rest of the information
 finally, it increase the number of students un the school by 1 and return 1 to print the appropriate outline*/

school_Error_t addStudentToSchool()
{
		school_Error_t school_state=DECLINED_OPERATION;/*no place so don't print any outline*/
	if((sch.stdnumber)<=MAXSTUDENTS)/*check the availbilty of free space for new student */
	{
		sch.std[sch.stdnumber]=sch.stdnumber;/*set the id automatically*/
		scanStudent(sch.std[sch.stdnumber]);/*call a function that scans the rest of the information*/
		(sch.stdnumber)++;/*increase the number of the students in the school*/
		school_state=APPROVED_OPERATION;/*to print the appropriate outline*/
	}
	return school_state;
}

/*this function call a function that check if this student in the school or not using the id */

school_Error_t checkStudentInSchool(int *index)
{
	school_Error_t school_state=DECLINED_OPERATION;
	student_Error_t std_state=scanCheckID(sch.stdnumber,index);
	if(std_state==STUDENT_FOUNDED)
	{
		school_state=APPROVED_OPERATION;
	}
	
	return school_state ;
}

/* print it's old information then call another function that scan the new information */

void editStudentInSchool(int id)
{
	flag=1;/*global variable in another file to let the printStudent function that editStudentInSchool()is the calee */
	printStudent(id,sch.stdnumber);/*print the old information */
	flag=0;/*reset it again*/
	scanStudentForEdit(id);/*scan the modifications*/
}

/*function that is used to call another funtion to call specific student*/

void callStudentInSchool()
{
	callStudent(sch.stdnumber);
}

/*function to delete std from the school by calling another function 
then if it deleated already decrease the number of the students by 1*/

school_Error_t deleteStudentInSchool()
{
	student_Error_t deleted=deleteStudent(sch.stdnumber);/*function to scan id and check it*/
	school_Error_t state=DECLINED_OPERATION;
	if(deleted==STUDENT_FOUNDED)/*if it's deleated*/
	{
		(sch.stdnumber)--;/*decrease the number of the students by 1*/
		state=APPROVED_OPERATION;
		
	}
	return state;
	
}


