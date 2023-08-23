#include "shell.h"
/**
 * _setenv - Initialize a new environment variable,
 * or modify an existing one.
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * Return: (void)
*/
void _setenv(char **command, char **argv, int *status, int idx)
{
	int i;
	char *key, *variable, *tmp, *new_var;
	(void) idx;
	(void) argv;

	if (!command[1] || !command[2])
	{
		(*status) = 0;
		free2Darray(command);
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, command[1]) == 0)
		{
			variable = strtok(NULL, "\n");
			if (_strcmp(variable, command[2]) == 0)
			{
				free(tmp);
				(*status) = 0;
				free2Darray(command);
				return;
			}
			_strcpy(environ[i], command[1]);
			_strcat(environ[i], "=");
			_strcat(environ[i], command[2]);
			free(tmp);
			(*status) = 0;
			free2Darray(command);
			return;
		}
		free(tmp), tmp = NULL;
	}
	new_var = malloc(_strlen(command[1]) + _strlen(command[2]) + 2);
	_strcpy(new_var, command[1]);
	_strcat(new_var, "=");
	_strcat(new_var, command[2]);
	environ[i] = new_var;
	environ[i + 1] = NULL;
	(*status) = 0;
	free2Darray(command);
}
/**
 * _unsetenv - Remove an environment variable.
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * Return: (void)
*/
void _unsetenv(char **command, char **argv, int *status, int idx)
{
	int i;
	char *tmp, *key;
	(void) idx;
	(void) argv;

	if (command[1])
	{
		for (i = 0; environ[i]; i++)
		{
			tmp = _strdup(environ[i]);
			key = strtok(tmp, "=");
			if (_strcmp(command[1], key) == 0)
			{
				free(tmp), tmp = NULL;
				break;
			}	
			free(tmp), tmp = NULL;
		}
		while (environ[i])
		{
			environ[i] = environ[i + 1];
			i++;
		}
	}
	(*status) = 0;
	free2Darray(command);
}
