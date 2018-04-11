#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num,mod,i,len;
	char buff[10],temp;
	char str[10];
	
	i=0;
	printf("enter integer:");
	scanf("%d",&num);
	//sprintf(buff,"%d",num);
	//printf("str is %s\n",buff);
	while(num)
	{
	
		mod = num%10;
		str[i] = mod+48;
		printf("str[%d]:%c\n",i,str[i]);
		num=num/10;
		i++;

	}
	
	printf("reverse str :%s\n",str);
	len=strlen(str)-1;
	for(i=0;i<len;i++,len--)
	{
		temp=str[i];
		str[i]=str[len];
		str[len]=temp;
	}
	
	printf(" str :%s\n",str);
	
	
}
