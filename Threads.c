#include<pthread.h>
#include<stdio.h>

void *mythread1();      //thread prototype
void *mythread2();

static int i;
static int cond =0;

unsigned int shared_data = 0;
pthread_mutex_t mutex;
//pthread_cond_t condition_var = 0;

int main()
{
        pthread_t thread[2];
        //starting the thread
        pthread_create(&thread[0],NULL,mythread1,NULL);
        pthread_create(&thread[1],NULL,mythread2,NULL);
        //waiting for completion
        pthread_join(thread[0],NULL);
        pthread_join(thread[1],NULL);


        return 0;
}

void *mythread1()
{
        int j=3;
        while(j)
        {
                if(cond == 0 || cond ==2)
                {
                        pthread_mutex_lock(&mutex);
                        cond = 1;
                        printf("Thread 1 Running :%d \n",shared_data+1);
                        pthread_mutex_unlock(&mutex);
                        j--;
                }
        }
}
void *mythread2()
{
        int k=3;
        while(k)
        {
                if(cond == 1)
                {
                        pthread_mutex_lock(&mutex);
                        cond = 2;
                        printf("Thread 2 Running :%d \n",shared_data+2);
                        pthread_mutex_unlock(&mutex);
                        k--;
                }
        }
 }         
