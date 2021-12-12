/* sig7-1.c */
/* sigaction example */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signo);
int main()
{
	struct sigaction act;
	int i = 0;
	act.sa_handler = handler; // 시그널 오면 handler를 실행하도록 설정
	sigfillset(&(act.sa_mask)); // 모든 시그널은 시그널을 처리하는 동안 블록되도록 설정
	sigaction(SIGINT, &act, NULL); // SIGINT에 대해 act 행동을 하도록 설정
	printf("SIGINT on\n");
	while(1) {
		sleep(1);
		printf("sleep for %d sec(s).\n", ++i);
	}
}

void handler(int signo)
{
	printf("handler: signo=%d\n", signo);
}
