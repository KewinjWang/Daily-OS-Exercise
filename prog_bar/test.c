#include "test.h"
void count()
{
	int i = 10;
	while(i)
	{
		printf("%-2d\r",i);
		fflush(stdout);
		sleep(1);
		i--;
	}
}
void prog_bar()
{
	int i = 0;
	char prog[101] = {0};
	memset(prog,'\0',sizeof(prog));
	t
	const char lable[] = {"|/-\\"};
	while(i<=100)
	{
		printf("[%-100s][%d%%][%c]\r",prog,i,lable[i%4]);
		fflush(stdout);
		usleep(200000);
		prog[i] = '#';
		i++;
	}
	printf("\n");
}
