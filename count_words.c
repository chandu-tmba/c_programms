#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

	char str[100]="how a     reyou?";
	int len = strlen(str);
	int i,count;
	count=0;

	for(i=0;i<len;i++)	
	{
	
		if((str[i] == ' ') && (str[i+1] != ' '))
		{	
			count++;
		}

	}
	count++;
	printf("word count is %d\n",count);
}
