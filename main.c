#include "header.h"
/**
 * main - simple shell programm, main function;
 * @ac: number of arg
 * @av: argument vector
 * Return: always 0
 *
 */
int main(int ac, char **av)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, index = 0;
	(void)ac;

	while (1)
	{

		line = read_command();
		if (line == NULL) /*handeling EOF crtl+D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;

		command = tokenize(line);
		if (!command)
			continue;

		status = execute_command(command, av, index);
	}

	return (0);
}
