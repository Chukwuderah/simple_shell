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

		char input[400];

		ssize_t input_length = read(STDIN_FILENO, input, sizeof(input));
		if (input_length <= 0)
			break;

		if (input_length > 0 && input[input_length - 1] == '\n')
			input[input_length - 1] = '\0';

		char *command = strtok(input, " ");

		if (command == NULL)
			continue;

		pid_t pid = fork();

		if (pid == 0)
		{
			char *args[] = {command, NULL};

			execve(command, args, NULL);

			write(STDERR_FILENO, "PaShell: ", 9);
			char *cmd_ptr = command;
			while (*cmd_ptr != '\0')
			{
				write(STDERR_FILENO, cmd_ptr, 1);
				cmd_ptr++;
			}
			write(STDERR_FILENO, ": ", 2);
			perror("");
			_exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("PaShell");
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
