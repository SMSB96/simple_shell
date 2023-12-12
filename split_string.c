#include "shell.h"

/**
 * _strdup - Duplicate a string.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string or NULL on failure.
*/

char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		len++;
		str++;
	}

	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		ptr[i] = str[i];

	return (ptr);
}

/**
 * _strcmp - Compare two strings.
 *
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: An integer less than, equal to, or greater than zero
 * if s1 is found, respectively, to be less than, to match, or be greater
 * than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
			break;

		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}

	return (cmp);
}

/**
 * _strlen - Calculate the length of a string.
 *
 * @s: The string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcat - Concatenate two strings.
 *
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}

	*p = *src;
	return (dest);
}

/**
 * _strcpy - Copy a string.
 *
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: A pointer to the destination string dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

