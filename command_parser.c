#include "header.h"

/**
 * parse_cmd - Parses the command recieved from stdin
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */

char **parse_cmd(char *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	if(input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		perror("hsh");
		return (NULL);
	}
	argument = _strtok(input, "\n ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = _strtok(NULL, "\n ");
	}
	arguments[i] = NULL;

	return (arguments);
}
