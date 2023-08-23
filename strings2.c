#include "functions.h"
#include <stddef.h>

/**
 * _strchr - checks if char exists in string
 * @string: parameter
 * @character: parameter
 * Return: Always 0 (Success)
 */

char *_strchr(char *string, char character)
{
	int i = 0;

	for (; string[i] >= '\0'; i++)
	{
		if (string[i] == character)
			return (&string[i]);
	}
	return (0);
}

/**
 * _strcat - Custom string concatenation function that appends the contents of
 * the source string to the end of the destination string.
 *
 * @dest: The destination string.
 * @src: The source string.
 */

void _strcat(char *dest, const char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
