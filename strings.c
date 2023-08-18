#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

/**
 * _strlen - Replacement strlen function
 * @str: string with characters to count
 * Return: the string length
 */

int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strcpy - Replacement strcpy function
 * @dest: The string to copy to
 * @src: The string to be copied
 */

void _strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

/**
 * _strcmp - Replacement strcmp function
 * @str1: A string to compare
 * @str2: A string to compare
 * Return: 0 if the strings are the same
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return ((unsigned char)*str1 - (unsigned char)*str2);
}

/**
 * _strncmp - Custom string comparison function
 * that emulates the behavior of strncmp.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}

	return (0);
}

/**
 * _strcat - Custom string concatenation function that appends the contents of
 * the source string to the end of the destination string.
 *
 * @dest: The destination string.
 * @src: The source string.
 */

void _strcat(char *dest, const char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

char **_strtok(const char *str, char delimiter, int *num_tokens) {
    int token_count = 0;
    char **tokens = NULL;
    const char *start = str;
    const char *end = str;


    while (*end) {
        if (*end == delimiter) {
            if (end > start) {
                token_count++;
            }
            start = end + 1;
        }
        end++;
    }

    if (end > start) {
        token_count++;
    }

    *num_tokens = token_count;

    if (token_count == 0) {
        return NULL;
    }

    tokens = (char **)malloc(token_count * sizeof(char *));
    if (tokens == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }


    token_count = 0;
    start = str;
    end = str;

    while (*end) {
        if (*end == delimiter) {
            if (end > start) {
                int token_length = end - start;
                tokens[token_count] = (char *)malloc((token_length + 1) * sizeof(char));
                if (tokens[token_count] == NULL) {
                    perror("Memory allocation error");
                    exit(EXIT_FAILURE);
                }
                _strcpy(tokens[token_count], start);
                token_count++;
            }
            start = end + 1;
        }
        end++;
    }

    if (end > start) {
        int token_length = end - start;
        tokens[token_count] = (char *)malloc((token_length + 1) * sizeof(char));
        if (tokens[token_count] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        _strcpy(tokens[token_count], start);
    }

    return tokens;
}
