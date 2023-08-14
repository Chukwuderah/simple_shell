#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ARGS 10
extern char **environ;

char *_getenv(const char *name);
int tokenize_input(char *input, char *args[]);

#endif
