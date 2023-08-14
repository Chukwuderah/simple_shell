#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

/**
 * _strlen - Replacement strlen function
 * Return: the string length
 */

int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0') {
		len++;
	}

	return (len);
}

/**
 * _strcpy - Replacement strcpy function
 */

void _strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

/**
 * _strcmp - Replacement strcmp function
 * Returns 0 if the strings are the same
 */

int _strcmp(const char *str1, const char *str2) {
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return ((unsigned char)*str1 - (unsigned char)*str2);
}

/**
 * _strncmp - Custom string comparison function that emulates the behavior of strncmp.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n) 
{
	for (size_t i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i] || s1[i] == '\0') 
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}

	return (0);
}
