#include "header.h"

/**
 * check_cmd - Excutes commands found in predefined path
 * @cmd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @c:Shell Excution Time Case of Command Not Found
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */

int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status, ex;
	pid_t pid;

	if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		path_cmd(cmd);
	if (access(cmd[0], R_OK) != 0)
	{
		print_error(cmd[0], c, argv);
		free(input);
		free(cmd);
		exit(127);
	}
	if (*cmd == NULL)
		return (127);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		ex = execve(*cmd, cmd, environ);
		if (ex == -1)
		{
			return (-1);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	if (WEXITSTATUS(status) != 0)
	{
		free(cmd);
		free(input);
		exit(2);
	}
	return (0);
}

/**
 * signal_to_handle - Configures ^C not to terminate our shell
 * @sig: Incoming Signal
 */

void signal_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n$ ");
	}
}
