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

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], name, _strlen(name)) == 0)
		{
			return (&(env[i][strlen(name) + 1]));
		}

		env++;
	}

	return (NULL);
}

/**
 * exit_shell - Exit the shell.
 * This function implements the built-in 'exit' command to exit the shell.
 */

void exit_shell(void)
{
	exit(0);
}

/**
 * print_environment - Prints the current environment variables.
 */

void print_environment(void)
{
	char **env = environ;
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
