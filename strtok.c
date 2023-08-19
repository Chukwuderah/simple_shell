#include "functions.h"

/**
 * token_len - Locates the delimiter index marking the end
 *             of the first token contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the initial token pointed to by str.
 */
int token_len(char *str, char *delim)
{
    int len = 0;

    while (*str && *str != *delim)
    {
        len++;
        str++;
    }

    return len;
}

void free_tokens(char **tokens) {
    if (tokens != NULL) {
        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
}

/**
 * allocate_and_copy - Allocates memory and copies a substring.
 * @line: The source string.
 * @start: Pointer to the start of the substring.
 * @length: Length of the substring.
 *
 * Return: Pointer to the newly allocated and copied substring.
 */
char *allocate_and_copy(char *line, char *start, int length)
{
    char *substring = malloc(length + 1);
    if (!substring)
        return NULL;

    _strncpy(substring, start, length);
    substring[length] = '\0';

    return substring;
}

/**
 * _strtok - Tokenizes a string.
 * @line: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 *         NULL on failure.
 */
char **_strtok(char *line, char *delim)
{
    char **ptr = NULL;
    int tokens, t, letters, l;
    char *start = line;

    tokens = count_tokens(line, delim);
    if (tokens == 0)
        return NULL;

    ptr = malloc(sizeof(char *) * (tokens + 1));
    if (!ptr)
        return NULL;

    for (t = 0; t < tokens; t++)
    {
        while (*line == *delim)
            line++;

        letters = token_len(line, delim);
        ptr[t] = allocate_and_copy(line, start, letters);
        if (!ptr[t])
        {
            for (t--; t >= 0; t--)
                free(ptr[t]);
            free(ptr);
            return NULL;
        }

        line += letters;
    }
    ptr[t] = NULL;

    return ptr;
}

/**
 * count_tokens - Counts the number of delimited
 *                words contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */
int count_tokens(char *str, char *delim)
{
    int tokens = 0;
    int in_token = 0;

    while (*str)
    {
        if (*str == *delim)
        {
            in_token = 0;
        }
        else if (!in_token)
        {
            in_token = 1;
            tokens++;
        }

        str++;
    }

    return tokens;
}
