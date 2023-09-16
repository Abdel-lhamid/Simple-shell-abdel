#include "header.h"
/**
 * _strcat - concatinate two strings
 * @dest: where the content of the will be concatinated
 * @src: the second text that will be added to dest
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to duplicate
 * Return: pointer to the duplicated string
 * Description: returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * On error, return NULL
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	len++;

	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		*(duplicate_str + i) = *(str + i);
		i++;
	}

	return (duplicate_str);
}

/**
 * _strlen - returns the size of string
 * @s: the string we want to calculate the lenght for
 * Return: the lenght of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}

/**
 * *_strcpy - coppit the string src to dest
 * @src: the source string
 * @dest: the destination string
 * Return: the destination string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int len = _strlen(src);

	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
