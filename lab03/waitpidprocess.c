/* waitpid를 사용하여 자식의 퇴장 상태를 어떻게 알아내는지 보여준다 */
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	pid_t pid;
	int status;
	int exit_status;
	
	if ((pid=fork())<0)
		perror("fork failed");
	if (pid==0)
	{
		sleep(4);
		exit(5);
	}
	
	while (waitpid (pid, &status, WNOHANG)==0){
		printf ("still waiting... \n");
		sleep(1);
	}
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		printf("Exit status from %d was %d\n",pid, exit_status);
	}
	exit(0);
} 
