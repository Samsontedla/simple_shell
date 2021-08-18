#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **ar)
{
	size_t line = 50;
	char *str = (char *)malloc(line * sizeof(char));
	ssize_t linelen;

	while(1)
	{
                printf("%s", "$ ");
                linelen = getline(&str , &line, stdin);
                printf("%s", str);
        }
        return(0);
}
