#include "shell.h"
/**
 * _strdup - Allocates memory for a copy of a string
 * @str: string to be copied
 * Return: Pointer to the new allocated copy
*/
char *_strdup(char *str)
{
	char *p;
	size_t j = 0, i = 0;

	if (str == NULL)
		return (NULL);

	while (str[j] != '\0')
		++j;

	p = malloc(sizeof(char) * j + 1);
	if (p == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';

	return (p);
}
