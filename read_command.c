#include "header.h"

/**
 * _getline - reads an entire line from file descriptor
 * @lineptr: pointer to buffer to store the line
 * @n: pointer to store the number of characters read
 * @fd: file descriptor to read from
 *
 * Return: number of characters read, or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static char *ptr;
	static ssize_t bytes_read;
	char *newline_ptr;
	size_t len;

	if (!lineptr || !n || fd < 0)
		return (-1);

	if (bytes_read <= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (-1);
		ptr = buffer;
	}

	newline_ptr = buffer;
	while (newline_ptr < buffer + bytes_read && *newline_ptr != '\n')
		newline_ptr++;

	len = newline_ptr - ptr + 1;
	if (len > *n)
	{
		*lineptr = realloc(*lineptr, len);
		if (!*lineptr)
			return (-1);
		*n = len;
	}

	_strncpy(*lineptr, ptr, len);
	(*lineptr)[len - 1] = '\n';
	(*lineptr)[len] = '\0';

	ptr += len;
	if (ptr >= buffer + bytes_read)
		bytes_read = 0;

	return (len);
}
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
	l = _getline(&command, &len, 0);

	if (l == -1)
	{
		free(command);
		return (NULL);
	}
	return (command);
}
