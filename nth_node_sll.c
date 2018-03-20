#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node *next;
}*head;
 
 
 
void append(int num)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    right=(struct node *)head;
    while(right->next != NULL)
    right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}


void delete_position( int pos)
{

    struct node *temp, *prev;
    temp=head;
    int count = 0;
    if(pos == 0)
    {
	head = temp->next;
	free(temp);
        return;
    }
    while(count < pos )
    {	
       prev = temp; 	     
       temp = temp->next;
       count++;  	
    }
      
    prev->next = temp->next;
    free(temp);

}
 
int swap(int node1_data, int node2_data) 
{

     struct node *node1=NULL; 
     struct node *prev1=NULL;
     struct node *node2=NULL;
     struct node *prev2=NULL;
     struct node *temp=NULL;
     struct node *prev=NULL;
     temp=head;			
    
     while(temp)
     {
	if(temp->data == node1_data || temp->data == node2_data)
	{
	        if(temp->data == node1_data)
		{
	     		node1 = temp;
        		prev1 = prev;
		}
		if(temp->data == node2_data)
                {
                        node2 = temp;
                        prev2 = prev;
                }
		if((node1 != NULL) && (node2 != NULL))
		{
			break;
		}
	     	
	}
	prev = temp;
	temp = temp->next;
     }		

     if((node1 == NULL) || (node2 == NULL))
		return 0;


     if(prev1 != NULL)		
     	prev1->next = node2;
     else
	head = node2;	
     if(prev2 != NULL)
    	 prev2->next = node1;		
     else
	 head = node1;	

     temp = node1->next;
     node1->next = node2->next;
     node2->next = temp;
} 

int nth_node(n)
{

     struct node *main_ptr,*ref_ptr;
     main_ptr = head;		
     ref_ptr = head;	
     int count = 0;	

     if(head != NULL)
     {

	     while(count < n)
	     {

		     ref_ptr = ref_ptr->next;
		     count++;
	     }			

	     while(ref_ptr)
	     {

		     main_ptr = main_ptr->next;
		     ref_ptr  = ref_ptr->next;
	     }	

	     printf("Node no. %d from last is %d ", 
			     n, main_ptr->data);
     }	
     return 1;		
}


void add( int num )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    if (head== NULL)
    {
    head=temp;
    head->next=NULL;
    }
    else
    {
    temp->next=head;
    head=temp;
    }
}
void addafter(int num, int loc)
{
    int i;
    struct node *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
    left=right;
    right=right->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    left->next=temp;
    left=temp;
    left->next=right;
    return;
}
 
 
 
void insert(int num)
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
    add(num);
    }
    else
    {
    while(temp!=NULL)
    {
        if(temp->data<num)
        c++;
        temp=temp->next;
    }
    if(c==0)
        add(num);
    else if(c<count())
        addafter(num,++c);
    else
        append(num);
    }
}
 
 
 
int delete(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
    if(temp->data==num)
    {
        if(temp==head)
        {
        head=temp->next;
        free(temp);
        return 1;
        }
        else
        {
        prev->next=temp->next;
        free(temp);
        return 1;
        }
    }
    else
    {
        prev=temp;
        temp= temp->next;
    }
    }
    return 0;
}
 
 
void  display(struct node *r)
{
    r=head;
    if(r==NULL)
    {
    return;
    }
    while(r!=NULL)
    {
    printf("%d ",r->data);
    r=r->next;
    }
    printf("\n");
}
 
 
int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
    n=n->next;
    c++;
    }
    return c;
}
 
 
int  main()
{
    int i,num,pos;
    struct node *n;
    int n1_data,n2_data;	 
    head=NULL;
    while(1)
    {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("1.Insert\n");
    printf("2.Display\n");
    printf("3.Size\n");
    printf("4.Delete based on data of node\n");
    printf("5.Delete based on position of node\n");
    printf("6.Swap nodes\n"); 
    printf("7.nth node from end\n");  
    printf("7.Exit\n");
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert(num);
                 break;
        case 2: if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                printf("Element(s) in the list are : ");
                }
                display(n);
                break;
        case 3:     printf("Size of the list is %d\n",count());
                break;
        case 4:     if(head==NULL)
                printf("List is Empty\n");
                else{
                printf("Enter the number to delete : ");
                scanf("%d",&num);
                if(delete(num))
                    printf("%d deleted successfully\n",num);
                else
                    printf("%d not found in the list\n",num);
                }
                break;

        case 5: if(head==NULL)
		{
                	printf("List is Empty\n");
		        break;
		}
		printf("enter position : ");
		scanf("%d",&pos);
		if (pos >= count())
		{
			printf("invalid position");
			break;
		}
		else
		{
			delete_position(pos);
		}
		break;

	case 6: if(head==NULL)
                {
                        printf("List is Empty\n");
			break;
                }
		printf("enter node1 data : ");
                scanf("%d",&n1_data);
		printf("enter node2 data : ");
                scanf("%d",&n2_data);
		if(swap(n1_data,n2_data))
                    printf("swapped successfully\n");
                else
                    printf("data not found in the list\n");
		break;
	case 7: printf("enter the nth node to find from end : ");
		scanf("%d",&n);
		nth_node(n);
		break;
	
        case 8:     return 0;
        
        default:    printf("Invalid option\n");
        
	}
    }
    }
    return 0;
}
