#include "header.h"
/**
 * tokenize - tokenize a command
 * @line: the line typed by user
 *
 * Return: 2d array of tokenized command
 */

char **tokenize(char *line)
{
	char *token = NULL, *cp_line = NULL;
	char **command = NULL;
	int i = 0;

	if (!line)
		return (NULL);

	cp_line = _strdup(line);
	token = strtok(cp_line, DELIMITERS);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(cp_line), cp_line = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, DELIMITERS);
	}
	free(cp_line), cp_line = NULL;
	command = malloc(sizeof(char *) * (i + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}
	i = 0;
	token = strtok(line, DELIMITERS);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIMITERS);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
