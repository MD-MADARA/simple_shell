#include "shell.h"

/**
 * main - Simple Shell main function.
 * @argc: argumnents counter.
 * @argv: Arguments.
 * Return: the status of last execute.
 */

int main(int argc, char **argv)
{
	int status = 0, idx = 0, loop = 1, i = 0;
	char *line = NULL, **command = NULL, *new_env = NULL;
	file_input data;

	if (argc == 2)
	{
		data = get_file_input(argv);
		loop = data.len;
	}
	while (loop)
	{
		if (argc == 2)
		{
			loop--;
			line = data.lines[i++];
		}
		else
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
		comments_handler(&command);
		if (!command)
			continue;
		replace_variable(command, status);

		if (is_builtin(command[0]))
			handle_builtin(command, argv, &status, idx, &new_env);
		else
			status = _execute(command, argv, idx);
	}
	return (0);
}
