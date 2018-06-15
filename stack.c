#include<stdio.h>
#include<stdlib.h>


struct stack_node
{

	int data;
	struct stack_node *next;

};

struct stack_node *top=NULL;


void display_stack()
{

	struct stack_node *temp=top;

	while(temp)
	{

		printf("|_%d_|\n",temp->data);
		temp=temp->next;
	}  

}

void push(int data)
{

	struct stack_node * new_node;
	new_node = (struct stack_node *) malloc(sizeof(struct stack_node)); 

	new_node->data = data;
	new_node->next=top;
	top = new_node;

}


int pop()
{

	struct stack_node *temp;
	int data_poped;

	data_poped = top->data;
	temp=top; 
	top=top->next;
	free(temp);

	return data_poped;
}


int main()
{

   
  int pop_val;

  push(1);  
  push(2);  
  push(3);  
  push(4);  
  push(5);  
  display_stack();
  pop_val = pop();
  printf("pop value:%d\n",pop_val);
  pop_val = pop();
  printf("pop value:%d\n",pop_val);
  display_stack(); 

  return 0;
}
