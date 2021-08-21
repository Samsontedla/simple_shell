#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
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
		prompt();
		linelen = getline(&str , &line, stdin);
		if (linelen == EOF)/* used for infinite loop on echo piped input*/
                        exit(1);
		if (strcmp(str, "exit\n") == 0)
			exit(2);

//		printf("%s : %ld", str, strlen(str));

                int i = 0;
                char *sep = " \n";

                char *argv[5];

                char *cmd;
                cmd = malloc(sizeof(char)*80);

                int j;
                char *path = "/bin/";
                char progpath[20];
		for (cmd = strtok(str, " "); cmd != NULL; cmd = strtok(NULL, sep))
                {
                        j = strlen(cmd);
                        cmd[j] = '\0';
                        argv[i] = cmd;
                        //printf("%s%ld\n", argv[i], strlen(argv[i]));
                        i++;
                }
                argv[i] = NULL;

		if (strncmp(path, argv[0], 5) != 0)
		{
			strcpy(progpath, path);
			strcat(progpath, argv[0]);
		}
		else if (strncmp(argv[0], path, 5) == 0)
		{
			strcpy(progpath, argv[0]);
		}

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
			if (argv[0] == NULL || strlen(argv[0]) == 1)
			{
				exit(3);
			}
			if (strcmp(argv[0],"env") == 0)
			{
				while(environ[a] != NULL)
				{
					printf("%s\n", environ[a]);
					a++;
				}
				exit(4);
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
