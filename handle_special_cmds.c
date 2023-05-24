#include "shell.h"
/**
 * own_exit - Own Implemetation of exit
 * @exit_av: the arguments to be exited
 * Return: Nothing
 */
void own_exit(char **exit_av)
{
	int stat = EXIT_SUCCESS;

	if (exit_av[1])
		stat = _atoi(exit_av[1]);

	free(exit_av);
	exit(stat);
}

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
		free(line);
		own_exit(av);
	}

	if (_strcmp(av[0], "env") == 0)
	{
		print_environ();
		free(av);
		return (1);
	}
	return (0);
}
