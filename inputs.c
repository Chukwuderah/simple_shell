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
	char **token;

	token = _strtok(input, " ");

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count++] = *token;
		token = _strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	return (arg_count);
}
/**
 * find_command - checks path for command
 * @command: command to be entered
 * Return: True if command was foun, false if not
 */

bool find_command(const char *command)
{
	if (access(command, X_OK) == 0)
	{
		return (true);
	}

	char *path = _getenv("PATH");

	if (path != NULL)
	{
		int num_tokens = 0;
		char **dirs = _strtok(path, ":");
		char executable_path[256] = "";

		for (int i = 0; dirs[i] != NULL; i++)
		{
			num_tokens++;
		}

		for (int i = 0; i < num_tokens; i++)
		{
			_strcpy(executable_path, dirs[i]);
			_strcat(executable_path, "/");
			_strcat(executable_path, command);

			if (access(executable_path, X_OK) == 0)
			{
				free_dir_tokens(dirs, num_tokens);
				return (true);
			}
		}

		free_dir_tokens(dirs, num_tokens);
	}

	return (false);
}

/**
 * free_dir_tokens - Frees the strtok tokens
 * @dirs: The list of tokens
 * @num_tokens: The number of tokens to be freed
 */

void free_dir_tokens(char **dirs, int num_tokens)
{
	free_tokens(dirs);
}
