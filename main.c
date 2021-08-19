#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/wait.h>

int main(void)
{
        size_t line = 50;
        char *str;
        str = malloc(line * sizeof(char));
        ssize_t linelen;

        do{
                printf("%s", "$ ");
                if (stdin == NULL)
                        break;
                linelen = getline(&str , &line, stdin);

                if (linelen == '\0')
                        return(0);
                int i;
                char stri[50];

                for(i = 0; i < linelen - 1; i++)
                {
                        stri[i] = str[i];
                }
                stri[i++] = '\0';

                char *argv[] = {stri, NULL};
                int pid = fork();

                if (pid == 0)
                {
                        execve(argv[0], argv, NULL);
                        perror("Error");
                }else {
                        wait(NULL);
                }
        }while(1);
        return(0);
}
