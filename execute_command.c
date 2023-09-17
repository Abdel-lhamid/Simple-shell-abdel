#include "header.h"
/**
 * execute_command - execute a command
 * @command: command provided by the user
 * @av: argument vector in main
 * @index: the number of commandes
 * Return: 0 on success
 */

int execute_command(char **command, char **av, int index)
{
	pid_t child_pid;
	int status;
	char *full_command;

	full_command = get_path(command[0]);
	if (!full_command)
	{
		print_error(av[0], command[0], index);
		free2dar(command);
		return (127);
	}

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(full_command, command, environ) == -1)
		{
			free(full_command), full_command = NULL;
			free2dar(command);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free(full_command), full_command = NULL;
		free2dar(command);
	}

	return (WEXITSTATUS(status));
}
