#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_ARGS 10
extern char **environ;

char *_getenv(const char *name);
int tokenize_input(char *input, char *args[]);
int _strlen(const char *str);
void _strcpy(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
void _strcat(char *dest, const char *src);

#endif
