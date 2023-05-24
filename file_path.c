#include "shell.h"
/**
 * file_path - Checks if the file exists and it's path
 * @filename: name of the given file
 * Return: Pointer to the file's full path
*/
char *file_path(char *filename)
{
	char *path_env = _getenv("PATH");
	char *path_env_copy = _strdup(path_env);
	char *string;
	char *delim = ":";
	char *full_path;

	if (path_env == NULL || path_env_copy == NULL || filename == NULL)
		return (NULL);
	if (access(filename, F_OK) == 0)
	{
		free(path_env_copy);
		return (_strdup(filename));
	}
	string = strtok(path_env_copy, delim);
	while (string != NULL)
	{
		full_path = malloc(_strlen(string) + _strlen(filename) + 2);
		if (full_path == NULL)
		{
			perror("Can't allocate memory");
			return (NULL);
		}
		_strcpy(full_path, string);
		_strcat(full_path, "/");
		_strcat(full_path, filename);
		if (access(full_path, F_OK) == 0)
		{
			free(path_env_copy);
			return (full_path);
		}
		else
		{
			free(full_path);
			string = strtok(NULL, delim);
		}
	free(path_env_copy);
	return (NULL);
}
