#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define LEN 1024
#define NUM 32
int main()
{
	char cmd[LEN];
	char* argv[NUM];
	while(1)
	{
		printf("[myshell]$ ");
		fgets(cmd,LEN,stdin);
		cmd[strlen(cmd)-1] = '\0';
		argv[0] = strtok(cmd," ");
		int i = 1;
		while(argv[i] = strtok(NULL," "))
		{
			i++;
		}
		pid_t pid = fork();
		if(pid == 0)
		{
			//child
			execvp(argv[0],argv);
			exit(-1);
		}
		else if(pid > 0)
		{
			//father
			int status = 0;
			pid_t wpid = waitpid(pid,&status,0);
			if(wpid > 0)
			{
				if(WIFEXITED(status))
				{
					printf("the exit code is %d\n",
							WEXITSTATUS(status)); 
				}
				else
				{
					printf("exit sig\n");
				}
			}
		}
		else 
		{ 
			perror("fork error:"); 
			exit(-1); 
		}
	}
//	char hostname[32];
//	gethostname(hostname,sizeof(hostname));
//	printf("name is %s",hostname);
	return 0;
}
