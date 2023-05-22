#include "shell.h"
/**
 * empty_line - Checks if the command entered is empty
 * @line: command entered
 * Return: if true (1), false (0)
*/
int empty_line(char *line)
{
	int line_is_mt = 1;
	int i;
	int length = _strlen(line);

	for (i = 0; i < length; i++)
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			line_is_mt = 0;
			break;
		}
	}
	if (line_is_mt)
	{
		return (1);
	}
	return (0);
}
