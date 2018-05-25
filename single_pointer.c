#include<stdio.h>
#include<stdlib.h>

int main()
{

	int *single_ptr = NULL;

	int i,j;

	single_ptr = (int *) malloc(3*4*sizeof(int ));
	if(single_ptr == NULL)
	{
		printf("memory not avilbale\n");
		return 0;
	}
	else
	{
		printf("memory allocated\n");
	}
	

	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			*(single_ptr+i*4+j)=i+j;
		}
	}

	for(i=0;i<3;i++)
        {
                for(j=0;j<4;j++)
                {
                       printf("single_ptr[%d][%d]:%d\n",i,j,*(single_ptr+i*4+j));
                }
        }

	free(single_ptr);
}
