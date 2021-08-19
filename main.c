#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>
#include <string.h>

int main(void)
{
        size_t line = 50;
        char *str;
        str = malloc(line * sizeof(char));
        ssize_t linelen;
        extern char **environ;
        do{
                printf("%s", "$ ");
                if (stdin == NULL)
                        return(0);
                linelen = getline(&str , &line, stdin);

                if (linelen == EOF)
                        return(0);

                int i = 0;
                const char sep[2] = " ";

                char *argv[5];

                char *cmd;
                cmd = malloc(sizeof(char)*80);

                int j;
                char *command;
                command = malloc(sizeof(char) * 50);
                for (cmd = strtok(str," \n"); cmd != NULL; cmd = strtok(NULL," \n"))
                {
                        j = strlen(cmd);
                        cmd[j] = '\0';
                        argv[i] = cmd;
                        //printf("%s%ld\n", argv[i], strlen(argv[i]));
                        ++i;
                }
                argv[i] = NULL;

                int pid = fork();

                if (pid == 0)
                {
                        //printf("%s%ld\n", argv[1], strlen(argv[1]));
                        execve(argv[0], argv, NULL);
                        perror("Error");
                }else {
                        wait(NULL);
                }
        }while(1);
        return(0);
}
