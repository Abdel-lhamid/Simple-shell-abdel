#include "header.h"
/**
 * free2dar - free a 2d array of strings
 * @array: 2d array of string to free
 */

void free2dar(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

/**
 * print_error - print error on exec failiure
 * @sh_name: name of shell
 * @command: the command
 * @index: index of the command
*/
void print_error(char *sh_name, char *command, int index)
{
	char *ind;

	ind = int_to_string(index);
	write(STDERR_FILENO, sh_name, _strlen(sh_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ind, _strlen(ind));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
	free(ind);
}
