#include<stdio.h>
#include<stdlib.h>

int main()
{

	int (*ptr_to_array)[3] = NULL;

	int i,j;

	ptr_to_array = (int  *)malloc(3 * sizeof(int *));

	
	printf("sizeof ptr_to_array:%d\n",sizeof(ptr_to_array));
        for(i=0;i<3;i++)
		ptr_to_array+i = (int *)malloc(4 * sizeof(int));

	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			*((ptr_to_array+i)+j) = i+j;
		}
	}

	for(i=0;i<3;i++)
        {
                for(j=0;j<4;j++)
                {
                       printf("double_ptr[%d][%d]:%d\n",i,j,*((ptr_to_array+i)+j));
                }
        }


        for(i=0;i<3;i++)
	{
		free(ptr_to_array+i);
	}
	
	free(ptr_to_array);


}
