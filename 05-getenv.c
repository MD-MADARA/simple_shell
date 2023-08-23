#include "shell.h"

/**
 * _getenv - a function that gets an environment variable.
 * @variable: the variable name.
 * Return: the environment variable.
*/
char *_getenv(char *variable)
{
	char *key, *tmp, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			env = _strdup(strtok(NULL, "\n"));
			free(tmp);
			return (env);
		}
		free(tmp);
	}

	return (NULL);
}
