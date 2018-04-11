#include<stdio.h>
#include<stdlib.h>

int main()
{

	int int_var;
	char *char_ptr = NULL;
	
	int_var = 1;
	char_ptr = (char *)&int_var;

	 if(*char_ptr == 1)
		printf("little endian\n");
	 else
		printf("big endian\n");


}
