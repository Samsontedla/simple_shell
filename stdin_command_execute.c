#include "header.h"

/**
 * handle_builtin - Handles predefined built in commands
 * @cmd: Array of parsed command strings
 * @er: Status of last execution
 * Return: -1 Failure 0 Success
 */

int handle_builtin(char **cmd, int er)
{
	 builtin built_in[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->command)
	{
		if (_strcmp(cmd[0], (built_in + i)->command) == 0)
		{
			return ((built_in + i)->function(cmd, er));
		}
		i++;
	}
	return (-1);
}
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
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
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
