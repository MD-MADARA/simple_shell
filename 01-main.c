#include "shell.h"

/**
 * main - Simple Shell main function.
 * @argc: argumnents counter.
 * @argv: Arguments.
 * Return: the status of last execute.
 */

int main(int argc, char **argv)
{
	int status = 0, idx = 0;
	char *line = NULL, **command = NULL, *new_env = NULL;
	(void) argc;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(new_env);
			return (status);
		}
		idx++;
		command = split_line(line);
		if (!command)
			continue;
		if (is_builtin(command[0]))
		{
			handle_builtin(command, argv, &status, idx, &new_env);
			continue;
		}
		else
		{
			status = _execute(command, argv, idx);
		}
	}
}
