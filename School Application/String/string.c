#include <stdio.h>
#include <stdlib.h>

void strScan(char *str,int size)
{
	int i;
	fflush(stdin);
	scanf("%c",str);
	for(i=0;str[i]!='\n'&&i<size;)
	{
		i++;
		scanf("%c",str+i);
	}
	str[i]=0;
	fflush(stdin);
}

int str_length(char *str)
{
    int i;
    for( i=0;str[i];i++)
    {

    }
    return i;
}

char ToLower(char a,char b)
{
    if(a>='A'&&a<='Z')
    {
        a='a'+(a-'A');
    }
      if(b>='A'&&b<='Z')
    {
        b='a'+(b-'A');
    }
    return a-b;
}


int str_compare(char *str1,char *str2)
{
    for(int i=0;str1[i]||str2[i];i++)
    {
        if(ToLower(str1[i],str2[i])!=0)
        {
            return -1;
        }
    }
    return 0;
}