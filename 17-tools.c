#include "shell.h"
/**
 * free2Darray - a function that frees an array of strings.
 * @array: the array to free.
 * Return: (void).
*/
void free2Darray(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array), array = NULL;
}
/**
 * print_error - a function that prints error
 * if command doesn't exist.
 * @name: shell name.
 * @idx: the command index.
 * @cmd: the command.
 * Return: (void).
*/
void print_error(char *name, int idx, char *cmd)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, _strlen(mssg));
	free(index);
}
