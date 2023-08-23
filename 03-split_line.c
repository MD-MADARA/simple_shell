#include "shell.h"

/**
 * split_line - a functin that splits a string into tokens.
 * @line: the string to split.
 * Return: a null terminating array of strings, containing each word of line
 * or null if line is only delimiters.
*/
char **split_line(char *line)
{
	int i = 0, j = 0;
	char *token, *tmp, **array = NULL;

	if (line == NULL)
		return (NULL);

	tmp = _strdup(line); /* Creat a copy of the original line */
	token = strtok(tmp, DELIM); /* Try get the first token */
	if (!token) /* If there are no tokens, return NULL */
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token) /* Count the number of tokens */
	{
		j++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	/* Allocate memory for tokens array */
	array = malloc(sizeof(char *) * (j + 1));
	if (!array)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		array[i++] = _strdup(token); /* Fill the array with tokens */
		token = strtok(NULL, DELIM); /* Get the next token*/
	}
	array[i] = NULL; /* terminate the array with NULL*/
	free(line), line = NULL;

	return (array);
}
