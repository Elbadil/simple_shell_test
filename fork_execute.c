#include "shell.h"
/**
 * fork_execute - Forks and execute a command
 * @usr_cmd: User's command
 * @av: Pointer to an array of character pointers that list all arguments
 * @env: Array of character pointers that holds environment variables
 * Return: Nothing
*/
void fork_execute(char *usr_cmd, char **av, char **env)
{
	int stat;
	pid_t prg_pid;

	prg_pid = fork();

	if (prg_pid == -1)
	{
		perror("Fork failed");
		free(av);
		exit(EXIT_SUCCESS);
	}
	if (prg_pid == 0)
	{
		execve(usr_cmd, av, env);
		perror("Cant execute");
		free(av);
	}
	else
	{
		wait(&stat);
	}
	free(usr_cmd);
}
