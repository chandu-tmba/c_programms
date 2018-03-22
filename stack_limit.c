#include<stdio.h>
#include<sys/resource.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
	struct rlimit v;
	static int arr[1000000];
	int ret=0;
	const rlim_t kStackSize = 64L*1024L*1024L;
	getrlimit(RLIMIT_STACK,&v);
	printf("cur %u\n",(unsigned int )v.rlim_cur);
	printf("max %u\n",(unsigned int )v.rlim_max);
	v.rlim_cur=kStackSize;	
	ret=setrlimit(RLIMIT_STACK,&v);
	if(ret != 0)
		printf("err:%d",errno);
	printf("ret:%d\n",ret);
	
	getrlimit(RLIMIT_STACK,&v);

	printf("after cur %u\n",(unsigned int )v.rlim_max);
	printf("after max %u\n",(unsigned int )v.rlim_max);




}
