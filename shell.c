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

		if (fgets(input, sizeof(input), stdin) == NULL)
			break;

		input[strcspn(input, "\n")] = '\0';

		char *command = strtok(input, " ");

		if (command == NULL)
			continue;

		pid_t pid = fork();

		if (pid == 0)
		{
			char *args[] = {command, NULL};

			execve(command, args, NULL);

			char error_message[400];

			snprintf(error_message, sizeof(error_message), "%s: ", command);
			perror(error_message);
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
