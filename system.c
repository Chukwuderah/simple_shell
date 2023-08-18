#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

/**
 * _getenv - Replacement for the getenv function
 * @name: name of the environment variable to find
 * Return: The environment variables
 */

char *_getenv(const char *name)
{
	char **env = environ;
	int i;

	printf("Getting environment variable: %s\n", name);

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], name, _strlen(name)) == 0)
		{
			return (&(env[i][strlen(name) + 1]));
		}

		env++;
	}
	printf("Environment variable %s not found. Returning Null.\n", name);
	return (NULL);
}
