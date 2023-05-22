#include "shell.h"
/**
 * _getenv - Gets environment of a variable
 * @name: name of the variable
 * Return: Pointer to the environment of the variable
*/

char *_getenv(const char *name)
{
	char **cnrt_env = environ;
	size_t n = _strlen(name); /* Length of the env variable name */
	int i;

	for (i = 0; cnrt_env[i] != NULL; i++)
	{
		if (_strncmp(cnrt_env[i], name, n) == 0 && cnrt_env[i][n] == '=')
		{
			return (&cnrt_env[i][n + 1]);
		}
	}
	return (NULL);
}
