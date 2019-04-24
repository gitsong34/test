#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	if(( pid = fork()) < 0)
	{
		printf("fork error");
	} 
	else if(pid == 0)
	{
		if((pid = fork()) < 0)
		{
			printf("fork error");
		}
		else if(pid > 0)
		{
			exit(EXIT_SUCCESS);
		}
		sleep(2);
		printf("2nd child , parent pid = %d\n" , getppid());
		exit(EXIT_SUCCESS);
	}

	if(waitpid(pid , NULL, 0) != pid)
	{
		printf("waitpid error");
		exit(EXIT_SUCCESS);
	}
}
