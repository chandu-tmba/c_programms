#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int num,mod,mul,len;
	char str[10]={0};

	mul=1;
	num=0;
	printf("enter str:");
	gets(str);

	len = strlen(str)-1;
	while( len!= -1)
	{
		mod = str[len];
		mod = mod-48;
		num = mod*mul+num;
		mul = mul*10;
		len--;

	}
	
	printf("num :%d\n",num);
	
	
}
