#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) 
{
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b,a);
}

int find_count(const char* a, int len)
{
  int i,j,count=0;   
  for (i =0; i < len; i++) 
  {
    for (j = 0; (j < len && j != i); j++) 
    {
      if (a[i] == a[j]) 
        continue;
      else 
        count++;
    }
  }
  return count;
}


int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    int len1=strlen(a);
    int count1,count2;

    count1 = find_count(a,len1);
    len1=strlen(b);

    count2 = find_count(b,len1); 

    if (count1 > count2)
        return -1;
    else if(count2 > count1)
        return 1;
    else 
        return 0;

}

int sort_by_length(const char* a, const char* b) 
{
    int len1=strlen(a);
    int len2=strlen(b);

    if (len1 > len2)
      return -1;
    else if ( len2 > len1)
      return 1;
    else
      return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    int i,j;
    char *temp_ptr=NULL;

    if (*cmp_func == lexicographic_sort)
    {
      for (j = 0; j < len-1; j++)
       {
        for (i = j + 1; i < len; i++) {
          if (lexicographic_sort(arr[j], arr[i]) > 0) 
          {
            temp_ptr = arr[j];
            arr[j] = arr[i];
            arr[i] = temp_ptr;
          }
        }
      }
    }

    else if (*cmp_func == lexicographic_sort_reverse) 
    {
      for (j = 0; j < len - 1; j++)
      {
        for (i = j + 1; i < len; i++) 
        {
          if (lexicographic_sort_reverse(arr[j], arr[i]) > 0) {
            temp_ptr = arr[j];
            arr[j] = arr[i];
            arr[i] = temp_ptr;
          }
        }
      }
    }

    else if (*cmp_func == sort_by_number_of_distinct_characters)
    {
      for (j = 0; j < len - 1; j++) 
      {
        for (i = j + 1; i < len; i++)
        {
          if (sort_by_number_of_distinct_characters(arr[j], arr[i]) > 0)
          {
            temp_ptr = arr[j];
            arr[j] = arr[i];
            arr[i] = temp_ptr;
          }
         
        }
      }

    }
    else 
    {
      for (j = 0; j < len - 1; j++) {
        for (i = j + 1; i < len; i++) {
          if (sort_by_length(arr[j], arr[i]) > 0) {
            temp_ptr = arr[j];
            arr[j] = arr[i];
            arr[i] = temp_ptr;
          }
        }
      }
    }


}

