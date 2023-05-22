#include "shell.h"
/**
 * _strcat - To concatenates two strings
 * @dest: First string
 * @src: Second string
 * Return: Two strings concatenated
 */
char *_strcat(char *dest, char *src)
{
	int l;
	int i;

	for (l = 0 ; dest[l] != '\0' ;)
		l++;
	for (i = 0 ; src[i] != '\0' ;)
	{
		dest[l] = src[i];
		l++;
		i++;
	}
	dest[l] = '\0';
	return (dest);
}

/**
 * _strlen - To calculate the lenght of a string
 * @s: Our tring parameter
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int l;

	for (l = 0 ; s[l] != '\0';)
		l++;
	return (l);
}

/**
 * _strcmp - Compares two string
 * @s1: First string
 * @s2: Second string
 * Return: 0 if they are equal, else if there're not
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}

	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);

	return (0);
}

/**
 * _strcpy - Copy the string printed by src to dest
 * @dest: Parameter char to check
 * @src: Second parameter char to check
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strncmp - Compares two strings depending on their length
 * @s1: first string
 * @s2: second string
 * @n: length to be compared with
 * Return: Difference between two strings
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	if (i == n)
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}
