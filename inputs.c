#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

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
