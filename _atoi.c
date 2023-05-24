#include "shell.h"
/**
 * _atoi - Converts a string into a number (integer)
 * @str: string to be converted
 * Return: converted integer
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int j = 0;

	while (str[j] == ' ')
	{
		j++;
	}

	while (!(str[j] >= '0' && str[j] <= '9'))
	{
		if (str[j] == '-')
		{
			sign *= -1;
		}
		j++;
	}

	while (str[j] >= '0' && str[j] <= '9')
	{
		result = (result * 10) + (str[j] - '0');
		j++;
	}
	result *= sign;
	return (result);
}
