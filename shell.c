#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
* main - PaShell: Simplified Unix Command Line Interpreter
*
* Description:
* This Simple Shell was built as part of an ALX Project.
*
* Return: 0, if code ran successfully.
*/

int main(void)
{
	while (1)
	{
		write(STDOUT_FILENO, "PaShell $ ", 10);

		char input[100];
		ssize_t input_length = read(STDIN_FILENO, input, sizeof(input));

		if (input_length <= 0)
			break;

		if (input[input_length - 1] == '\n')
			input[--input_length] = '\0';

		char input_copy[100];

		_strcpy(input_copy, input);

		char *args[MAX_ARGS];
		int arg_count = tokenize_input(input_copy, args);

		if (arg_count == 0)
			continue;

		if (_strcmp(args[0], "exit") == 0)
		{
			exit_shell();
		}
		else if (find_command(args[0]) || access(args[0], X_OK) == 0)
		{
			execute_command(args);
		}
		else
		{
			write(STDERR_FILENO, "Command not found.\n", 19);
		}
	}

	return (0);
}
