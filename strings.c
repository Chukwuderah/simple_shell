#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

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
 * _strncmp - Replacement strncmp function
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
