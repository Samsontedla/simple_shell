#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>
#include <string.h>
#include "head.h"

int main(void)
{
        size_t line = 50;
        char *str;
        str = malloc(line * sizeof(char));
        ssize_t linelen;
        extern char **environ;
        do{
                printf("%s", "$ ");
                linelen = _getline(&str , &line, stdin);
                if (linelen == EOF)
                        return(0);
		if (strcmp(str, "exit\n") == 0)
			exit(0);

                int i = 0;
                char *sep = " \n";

                char *argv[5];

                char *cmd;
                cmd = malloc(sizeof(char)*80);

                int j;
                char *path = "/bin/";
                char progpath[20];
		for (cmd = strtok(str, sep); cmd != NULL; cmd = strtok(NULL, sep))
                {
                        j = strlen(cmd);
                        cmd[j] = '\0';
                        argv[i] = cmd;
                        //printf("%s%ld\n", argv[i], strlen(argv[i]));
                        i++;
                }
                argv[i] = NULL;
		strcpy(progpath, path);
		strcat(progpath, argv[0]);

		for(i = 0; i < strlen(progpath); i++)
		{
			if(progpath[i] == '\n')
			{
				progpath[i] = '\0';
			}
		}
                int pid = fork();

                if (pid == 0)
                {
			int a = 0;
			if (strcmp(argv[0],"env") == 0)
			{
				while(environ[a] != NULL)
				{
					printf("%s\n", environ[a]);
					a++;
				}
				exit(0);
			}
			else
			{
				execve(progpath, argv, NULL);
				perror("Error");
			}
		}else {
                        wait(NULL);
                }
        }while(1);
        return(0);
}
