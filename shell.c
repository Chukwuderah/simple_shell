#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Simple UNIX command line interpreter
 *
 * Description:
 * Displays a prompt, waits for user input,
 * and executes simple one-word commands.
 * The prompt is redisplayed after each command.
 *
 * Return: Always 0.
 */

int main(void)
{
	while (1)
	{
		printf("PaShell $ ");

		/* Read user input */
		char command[100];

		if (fgets(command, sizeof(command), stdin) == NULL)
			break; /* End of file (Ctrl+D) detected */

		command[strcspn(command, "\n")] = '\0';

		/* Create a child process */
		pid_t pid = fork();

		if (pid == 0) /* We're the child process */
		{
			/* Execute the command using execve */
			char *args[] = {command, NULL};

			execve(command, args, NULL);

			/* If we're here, something went wrong */
			perror("simple_shell");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0) /* Forking didn't go as planned */
		{
			perror("simple_shell");
		}
		else /* We're the parent process */
		{
			wait(NULL); /* Wait for the child to finish its business */
		}
	}

	return (0);
}
