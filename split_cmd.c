#include "shell.h"
/**
 * split_cmd - Splits a command into tokens using strtok
 * @str: given string
 * Return: Double pointer to an array of tokens
*/
char **split_cmd(char *str)
{
	char **argv;
	char *delim = " \t\n";
	char *string;
	int j = 0;

	argv = malloc(sizeof(char *) * (_strlen(str)));
	if (argv == NULL)
	{
		perror("Can't Allocate memory for arguments");
		return (NULL);
	}

	string = strtok(str, delim);
	while (string != NULL)
	{
		argv[j] = string;
		string = strtok(NULL, delim);
		j++;
	}
	argv[j] = NULL;

	return (argv);
}
