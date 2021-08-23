#include "head.h"
/**
* _getline - read input from standard input by user
* Return: the input on a buffer
*/
char *_getline()
{
	int i, rd;
	int buffsize = BUFSIZE;
	char c = 0;
	char *buffer;

	buffer = malloc(buffsize);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buffer = _realloc(buffer, buffsize, buffsize + 1);
			if (buffer == NULL)
			{
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	hashtag_handler(buffer);
	return (buffer);
}
/**
 * hashtag_handler - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
