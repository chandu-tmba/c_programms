#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int find_count(const char* a, int len)
{
  int i,j,count=0;   
  for (i = 0; i < len; i++) 
  {
    for (j = 0; j < len ; j++) 
    {
      if(i == j)
        continue;    
      if (a[i] == a[j])
      {
        count++;  
        break;
      }    
    }
    if(j==len)
        count++;
  }
  return count;
}*/

/*int find_count(const char* a, int len)
{
  int i,j,repeat=0;
  char *ptr1=NULL;
  char *ptr2=NULL;
 
  
  for (i = 0; i < len; i++) 
  {
      
      ptr1 = strchr(a,a[i]);
      ptr2 = strrchr(a,a[i]);
   
      if(ptr1 != ptr2)
          repeat++;
      
  }
  return len-repeat;
}*/

int find_count(const char *a, int len) 
{

  int i, j, count = 0;
  char * d = calloc(1, len);

  strcpy(d, a);
  
  //printf("\n %s \n",a);
  //printf("\n %s \n",d);
  //printf("\n after sorting \n");
  printf("\n before sorting :%s \n", d);
  
  for (i = 0; i < strlen(d); i++) 
  {
    for (j = 0; j < strlen(d); j++)
    {
        if ((i != j) && (d[i] == d[j]) )
        {
            memmove(d+j,d+j+1,strlen(d+j+1));
            *(d+(strlen(d)-1)) = '\0';
        }    
    }
    
    printf("\n %s \n",d); 

  }

  printf("\n after sorting :%s \n", d);
  count = strlen(d);
  free(d);
  return count;
  
}


int main()
{
   char arr[50]="wzkhoqomhulpuuivxvglmcgcdgvdhflffvmvnckwwxm";
   int res;
   res = find_count(arr,strlen(arr));
   printf("res:%d \n",res);
}
