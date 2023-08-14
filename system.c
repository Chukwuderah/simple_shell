#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

char _getenv(const char *name)
{
        char **env = environ;

        while (*env != NULL)
        {
                if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
                {
                        return (&((*env)[strlen(name) + 1]));
                }

                env++;
        }

        return (NULL);
}
