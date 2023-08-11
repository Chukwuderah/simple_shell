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

		char *args[MAX_ARGS];
		int arg_count = tokenize_input(input, args);

		if (arg_count == 0)
			continue;

		pid_t pid = fork();

		if (pid == 0)
		{
			execvp(args[0], args);

			perror("PaShell");
			_exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			write(STDERR_FILENO, "PaShell: Unable to launch sibling process\n", 43);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
