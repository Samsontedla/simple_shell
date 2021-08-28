#include "header.h"

/**
 * main - Entry point to program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Returns condition
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input;
	char **cmd;
	int count = 0;
	int condition = 1;
	int stat = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handle);

	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
			continue;
		history(input);
		cmd = parse_cmd(input);
		//if (cmd[1][0] == '/')
		//	exit(2);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, count);
		}
		else if (check_builtin(cmd) == 0)
		{
			stat = handle_builtin(cmd, stat);
			free_all(cmd, input);
			continue;
		}
		else
		{
			stat = check_cmd(cmd, input, count, argv);
		}
		free_all(cmd, input);
	}
	return (condition);
}
