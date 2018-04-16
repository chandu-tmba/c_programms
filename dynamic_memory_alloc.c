#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int i = 0,count;
	char c;
	char *input[20];

	count =0;
	
	while(count<20)
	{

		i=0;
		input[count] = (char *) malloc(sizeof(char));


		if(input[count] == NULL) {
			printf("Could not allocate memory!");
			exit(1);
		}

		printf("Input a string no %d , press enter when done: ",count+1);

		while((c = getchar()) != '\n') {
			realloc(input[count],(i+1)*(sizeof(char)));
			input[count][i] = c;
			i++;
		}

		input[count][i] = '\0';
	
		printf("\nYou entered the string: %s\n", input[count]);

		count++;

	}
	for(i=0;i<20;i++)
		printf(" name[%d]:%s\n",i,input[i]);
	
	for(i=0;i<20;i++)
		free(input[i]);
	
}
