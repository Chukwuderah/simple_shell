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
