#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ARGS 10

extern char **environ;

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void _strncpy(char *dest, const char *src, size_t n);
void free_tokens(char **tokens);
void free_dir_tokens(char **dirs, int num_tokens);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);
void free_tokens(char **tokens);
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

