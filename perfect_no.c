#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int power(int x, int y)
{

  int acc;
  acc=x;

  while(y!=1)
  {

     x=x*acc;
     y--;
 
  }

  return x;

}


int main()
{

  int i,j,n;


  printf("enter n val:");
  scanf("%d",&n);
  printf("\n");
  printf("sqrt:%d\n",sqrt(n));

  for(i=2;i<(n/2);i++)
  {

       //printf("in loop i val:%d\n",i);
       for(j=2;power(i,j)<=n;j++)
       {

          //printf("in loop j:%d\n",j);
	  if(power(i,j) == n)
	  {

		printf("perfect number\n");
          }	

       }
	

  }



}
