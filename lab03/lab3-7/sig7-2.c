/* sig7-2.c */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	struct sigaction act;
	int i = 0;
	act.sa_handler = SIG_IGN; // 시그널을 무시하도록 하는 SIG_IGN을 설정
	sigfillset(&(act.sa_mask)); // 시그널 집합을 비웠으므로 모든 시그널은 블록되지 않음
	sigaction(SIGINT, &act, NULL); // SIGINT에 대해 act 행동을 하도록 설정
	printf("SIGINT off\n");
	
	while(1){
		sleep(1);
		printf("sleep for %d sec(s).\n", ++i);
	}
}
