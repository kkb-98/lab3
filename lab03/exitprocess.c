/* exitprocess.c */ 
/* exit example */
#include <stdlib.h>
void main()
{
	int exit_status;
	printf("enter exit status: ");
	scanf("%d", &exit_status);
	exit(exit_status);
}
