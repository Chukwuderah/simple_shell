#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "functions.h"

/**
 * execute_command - Execute command
 * @args: list of command line argument
 */

void execute_command(char *args[])
{
execute(args, environ);
}

/**
 * execute_path - Execute path
 * @args: list of command line argument
 */

void execute_path(char *args[])
{
execute(args, environ);
}

/**
 * execute - Function that executes command line argument
 * @args: The list of command line arguments
 * @envp: The environment variables to search through
 */

void execute(char *args[], char *envp[])
{
pid_t pid = fork();

if (pid == 0)
{
execve(args[0], args, envp);
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
