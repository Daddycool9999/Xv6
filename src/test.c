#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"



int main(int argc,char** argv)
{
	int n=1, pid;

	if(argc>2)
		n=atoi(argv[1]);
	else
		n=1;	//default value
	volatile int x;
	int r,k;
	for(k=0;k<n;k++)
	{
		pid=fork();
		if(pid>0)
		{
			printf(1,"Parent %d created child %d\n",getpid(),pid);
			wait();
		}
		else if(pid<0)
		{
			printf(1,"fork failed\n");
		}
		else
		{
			for(r=0;r<100000000;r++)
			{
				x+=5;
				x*=5.344;
				x/=6.2442;
				x-=3853;
			}
			break;
		}
	}
	exit();
}