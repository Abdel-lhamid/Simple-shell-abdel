#include "header.h"

/**
 * read_command - read a command from user input
 * Return: command typed by user
*/

char *read_command(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t l;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "shs$ ", 5);
	l = getline(&command, &len, stdin);

	if (l == -1)
	{
		free(command);
		return (NULL);
	}
	return (command);
}
