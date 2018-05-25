#include<stdio.h>
#include<stdlib.h>

int main()
{

	char ch,*ptr[3];
	int i,count;

	for(i=0;i<3;i++)
	{
		//ptr[i] = malloc(sizeof(char));
		printf("i value %d\n",i);
		count = 0;
		ptr[i]=NULL;
		printf("enter name:");
		while((ch = getchar())!= '\n')
		{
			//printf("after while for ptr[%d]\n",i);
			count++;
			ptr[i] = realloc(ptr[i],count);
			if(ptr[i] == NULL)
			{
				printf("realloc error\n");
			}
			//printf("after alloc i value:%d count value:%d\n",i,count);
			*(ptr[i]+(count-1)) = ch;
			//printf("after assign i value:%d count value:%d\n",i,count);
		}
		if(ch == '\n')
		{
			//printf("new line encountered :%d\n",i);
			count++;
			ptr[i] = realloc(ptr[i],count);
			*(ptr[i]+(count-1)) = '\0';
		}

	}

	for(i=0;i<3;i++)
	{
		printf("str[%d]:%s\n",i+1,ptr[i]);
                free(ptr[i]);
	}

	//for(i=0;i<3;i++)
        //{
        //}


}
