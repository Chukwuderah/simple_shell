#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ARGS 10

extern char **environ;

#include <unistd.h>
#include <stdbool.h>

char **_strtok(const char *str, char delimiter, int *num_tokens);
void free_dir_tokens(char **dirs, int num_tokens);
int _strlen(const char *str);
void execute_command(char *args[]);
void execute_path(char *args[]);
void execute(char *args[], char *envp[]);
int _strncmp(const char *s1, const char *s2, size_t n);
int tokenize_input(char *input, char *args[]);
void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
bool find_command(const char *command);
char *_getenv(const char *name);

#endif

