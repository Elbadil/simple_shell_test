#include "shell.h"
/**
 * handle_special_cmds - Handle "exit" and "env"
 * @av: Array of arguments
 * @line: line given by getline
 * Return: if true (1), false (0)
*/

int handle_special_cmds(char **av, char *line)
{
	if (_strncmp(av[0], "exit", 4) == 0)
	{
		free(av);
		free(line);
		exit(EXIT_SUCCESS);
	}

	if (_strcmp(av[0], "env") == 0)
	{
		print_environ();
		free(av);
		return (1);
	}
	return (0);
}
