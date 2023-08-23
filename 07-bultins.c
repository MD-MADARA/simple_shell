#include "shell.h"

/**
 * is_builtin - check if a command is builtin.
 * @command: the command to check.
 * Return: 1 if the command is builtin otherwise 0.
*/
int is_builtin(char *command)
{
	int i;
	char *builtins[] = {
		"exit", "env","setenv", "unsetenv",
		NULL
	};

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - handle builtin.
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * Return: 1 if the command is builtin otherwise 0.
*/
void handle_builtin(char **command, char **argv, int *status, int idx)
{
	int i;
	builtins B[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; B[i].builtin; i++)
	{
		if (_strcmp(B[i].builtin, command[0]) == 0)
		{
			B[i].f(command, argv, status, idx);
			break;
		}
	}
}

/**
 * exit_shell - exit builtin
 * this function exits the shell whith status
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * Return: (void)
*/
void exit_shell(char **command, char **argv, int *status, int idx)
{
	int exit_status = (*status);
	char *index, mssg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (!is_positive_number(command[1]))
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			free2Darray(command);
			(*status) = 2;
			return;
		}
		else
			exit_status = _atoi(command[1]);
	}
	free2Darray(command);
	exit(exit_status);
}

/**
 * print_env - print environement variables
 * @command: the builtin command.
 * @argv: arguments.
 * @status: exit status.
 * @idx: index of the command.
 * Return: (void)
*/
void print_env(char **command, char **argv, int *status, int idx)
{
	int i;
	(void) argv;
	(void) idx;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(*status) = 0;
	free2Darray(command);
}