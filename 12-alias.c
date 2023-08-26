#include "shell.h"

/**
 * set_alias - alias builtin
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * @new_env: new_environment variable.
 * @alias: alias.
 * Return: (void)
*/
void set_alias(char **command, char **argv, int *status, int idx,
char **new_env, char **alias)
{
	int i;
	(void) argv;
	(void) idx;
	(void) new_env;

	if (!command[1])
	{
		if (_strlen(*alias))
			write(STDOUT_FILENO, *alias, _strlen(*alias));
		else
			write(STDOUT_FILENO, "\n", 1);
	}
	for (i = 1; command[i]; i++)
	{
		if (!_strlen(*alias))
			_strcpy(*alias, command[i]);
		else
			_strcat(*alias, command[i]);
		_strcat(*alias, "\n");
	}
	*status = 0;
	free2Darray(command);
}
