#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "functions.h"

void execute_command(char *args[])
{
    execute(args, environ);
}

void execute_path(char *args[])
{
    execute(args, environ);
}

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
