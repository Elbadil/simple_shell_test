#include "shell.h"
/**
 * main - Own implematation of the shell that treats user commands
 * @ac: Number of arguments
 * @av: Pointer to an array of character pointers that list all arguments
 * @env: Array of character pointers that holds environment variables
 * Return: Always 0 (success)
*/
int main(int ac, char **av, char **env)
{
	char *line = NULL, *usr_cmd;
	const char *no_file = "sh: 1: ./RUNME: not found";
	size_t line_size = 0;
	ssize_t new_line;
	(void)ac;

	while (1)
	{
		/* Handling the pipe */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		/* Getting the new line where we entering our command */
		new_line = getline(&line, &line_size, stdin);
		if (new_line == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		/* Checking if the line is empty (spaces, tabs, newlines)*/
		if (empty_line(line))
			continue;
		/* Splitting the command given by the user */
		av = split_cmd(line);
		/* Handling exit and env builtin */
		if (handle_special_cmds(av, line))
			continue;
		/* Checking for file path */
		usr_cmd = file_path(av[0]);
		/* If command exists we fork and execute */
		if (usr_cmd != NULL)
			fork_execute(usr_cmd, av, env);
		/* If command doesn't exist we print error message */
		else if (usr_cmd == NULL)
			write(STDOUT_FILENO, no_file, _strlen(no_file));
		free(av);
	}
	free(line);
	return (0);
}
