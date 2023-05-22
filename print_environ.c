#include "shell.h"
/**
 * print_environ - prints current environment
 * Return: Nothing
*/
void print_environ(void)
{
	char **crnt_env = environ;
	int j = 0;

	while (crnt_env[j] != NULL)
	{
		write(STDOUT_FILENO, crnt_env[j], _strlen(crnt_env[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}
