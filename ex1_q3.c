#include "types.h"
#include "stat.h"
#include "user.h"

#define N 3

int main(int argc, char *arg[]){

	int i,pid,status;

	for(i=1; i<=N; i++)
	{
		pid = fork();
		if (pid < 0) 
		{
			printf(2,"Error: Fork failed on child process #%d\n",i);
			return -1;
		}
		
		if (pid == 0)
		{
			printf(1,"my pid is %d going to exit(%d)\n", getpid(), i);
			exit2(i);
		}
	}
	
	for (i=1; i<=N; i++)
	{
		pid = wait2(&status);
		printf(1,"son %d exited with status %d\n", pid, status);
		//exit2(i);
	}
	
	exit();
	return 0;
}