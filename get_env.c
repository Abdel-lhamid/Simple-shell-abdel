#include "header.h"
/**
 * get_env - get envirement of the variable
 * @var: envirement variable
 * Return: envirement
 */
char *get_env(char *var)
{
	char *temp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		key = strtok(temp, "=");
		if (_strcmp(key, var) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(temp);
			return (env);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}

/**
 * get_path - get a path of the command
 * @command: the command
 * Return: the full path of the command
*/

char *get_path(char *command)
{
	char *env_path, *full_command, *path;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}

	}
	env_path = get_env("PATH");
	if (!env_path)
		return (NULL);
	path = strtok(env_path, ":");
	while (path)
	{
		full_command = malloc(_strlen(path) + _strlen(command) + 2);
		if (full_command)
		{
			_strcpy(full_command, path);
			_strcat(full_command, "/");
			_strcat(full_command, command);
			if (stat(full_command, &st) == 0)
			{
				free(env_path);
				return (full_command);
			}
			free(full_command), full_command = NULL;
			path = strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}
