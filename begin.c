#include <stdio.h>

/**
 * main - Does something
 * Return: 0 if successful
 */
int main(void)
{
	char name[50];

	printf("PaShell $ ");
	scanf("%49s", name);

	printf("%s \n", name);

	return (0);
}
