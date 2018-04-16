#include<stdio.h>
#include<stdlib.h>



int main()
{

	int i,x=10;
	int bit_pos = 23;
	unsigned int set_var = 0xFFFFFFFF;	


	for(i=0;i<32;i++)
		printf("%d",(1&(x>>i)));
	printf("\n");
	

 	int diff = 31-bit_pos;

	set_var = set_var>>diff;
	x=x^(set_var);

	for(i=0;i<32;i++)
                printf("%d",(1&(x>>i)));

	printf("\n");

}
