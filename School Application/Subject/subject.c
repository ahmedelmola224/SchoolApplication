#include "subject.h"

/*flag to detect which function is the calle*/
int flag=0;

/*global variables to determine the appropriate place to print the subjects on the screen*/
int xdir=0,ydir=0;

/*array of type subj_t to store the degrees of each student ,the index of each array of intgers is the id */
subj_t sub[maxOfStudent]={{50,60,70,80,90},{66,77,88,99,68},{45,39,15,88,56},{88,98,78,56,98}};

/*array of strings that stores the names of the subjects*/
char *subjects[5]={"Arabic","English","French","Science","Math"};


/*this function to read from the database  and intialize the array with it*/

void initSubject(int stdnumber)
{
	FILE *fp;/*decleration of a pointer to file*/
	fp=fopen("subject.txt","rb");/*open the file to read*/
	if(fp==NULL)
	{
		printf("\n Error can't open file");/*if there's a problem with opening it print this message*/
	}
	fread(sub,sizeof(subj_t),stdnumber,fp);/*to read all the data from the file*/
	fclose(fp);/*close the file*/
}

/*this function to update  the database with the new values in the array*/

void terminateSubject(int stdnumber)
{
	FILE *fp;/*decleration of a pointer to file*/
	fp=fopen("subject.txt","wb");/*open the file to write*/
	if(fp==NULL)
	{
		printf("\n Error can't open file");/*if there's a problem with opening it print this message*/
	}
	fwrite(sub,sizeof(subj_t),stdnumber,fp);/*to write all the array in the file*/
	fclose(fp);/*close the file*/
}

/*this funcrtion takes the id as the index of the array of degrees that needed to be printed */
void printSubject(const int id,int size)
{
	for(int i=0;i<maxOfSubjects;i++)
	{
		gotoxy(83+xdir,5+ydir);/*the appropriate place in the screen to the next print */
		printf("%d",sub[id].degree[i]);
		xdir+=9;/*to get the approprite place to print the next time*/
	}
	xdir=0;/*to get the approprite place to print the next time*/
	ydir+=2;/*to get the approprite place to print the next time*/
	if(id==(size-1)||flag)
	{
		ydir=0;/*to get the approprite place to print the next time*/
	}
}

/*function to scan the degrees of subjects of new student*/

void scanSubject(const int id)
{
	for(int i=0;i<maxOfSubjects;i++)
	{
		printf("\n%s :",subjects[i]);
		scanf("%d",&(sub[id].degree[i]));/*takes the id as inedx of the array*/
	}
}

/*function to scan the modificated degrees student*/

void scanSubjecttForEdit(const int id)
{
	int xdis=0;
	char key;
	for(int i=0;i<maxOfSubjects;i++)
	{
		gotoxy(2,7);/*the appropriate place in the screen to the next print */
		printf("                                               ");
		gotoxy(2,7);/*the appropriate place in the screen to the next print */
		printf("Do uou want to edit %s degree[y/n]: ",subjects[i]);
		scanf(" %c",&key);/*if the user enter y scan the new degree of this subject*/
		if(key=='y'||key=='Y')
		{
			gotoxy(83+xdis,5);/*the appropriate place in the screen to the next print */
			printf("   ");
			gotoxy(83+xdis,5);/*the appropriate place in the screen to the next print */
			scanf("%d",&(sub[id].degree[i]));/*takes the id as inedx of the array*/
		}
		xdis+=9;/*to get the approprite place to print the next time*/
	}
	
}

/*function to swap bewtwwn to elements of type subj_t*/

void swapSubjects(const int subA ,const int subB)
{
	subj_t temp=sub[subA];
	sub[subA]=sub[subB];
	sub[subB]=temp;
}

/*function to delete the degrees of a student*/

void deleteSubject(const int index,const int size)
{
	for(int i=index+1;i<size;i++)
	{
		swapSubjects(i-1,i);
	}
}

