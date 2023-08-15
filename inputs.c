#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "functions.h"
#include <stdbool.h>


/**
 * tokenize_input - Tokenize the input string into arguments.
 * @input: The input string to tokenize.
 * @args: An array to store the tokenized arguments.
 *
 * Return: The number of arguments.
 */

int tokenize_input(char *input, char *args[])
{
	int arg_count = 0;
	char *token = strtok(input, " ");

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	return (arg_count);
}
/**
 * find_command - checks path for command
 * @command: command to be entered
 * Return: True if command was foun, false if not
 */

bool find_command(char *command)
{
	char *path = _getenv("PATH");

	if (path != NULL)
	{
		char *dir = strtok(path, ":");

		while (dir != NULL)
		{
			char executable_path[256];

			_strcpy(executable_path, dir);
			_strcat(executable_path, "/");
			_strcat(executable_path, command);

			if (access(executable_path, X_OK) == 0)
				return (true);

			dir = strtok(NULL, ":");
		}
	}

	return (false);
}
