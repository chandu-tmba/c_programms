#include<stdio.h>
#include<stdlib.h>

int main()
{

	int **double_ptr = NULL;

	int i,j;

	double_ptr = (int **) malloc(3*sizeof(int *));
	if(double_ptr == NULL)
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
		*(double_ptr+i) = (int *)malloc(4 * sizeof(int));
	}


	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			double_ptr[i][j]=i+j;
		}
	}

	for(i=0;i<3;i++)
        {
                for(j=0;j<4;j++)
                {
                       printf("double_ptr[%d][%d]:%d\n",i,j,double_ptr[i][j]);
                }
        }


        for(i=0;i<3;i++)
	{
		free(*(double_ptr+i));
	}
	
	free(double_ptr);


}
