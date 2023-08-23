#include "shell.h"

/**
 * build_dir_list - a function that builds a linked list
 * of the PATH directories.
 * Return: a linked list of the PATH directories.
*/
list_dir *build_dir_list(void)
{
	list_dir *head = NULL;
	char *path_env, *token;

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	token = strtok(path_env, ":");
	while (token)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	free(path_env);
	return (head);
}

/**
 * _getpath - a function that handle the path of a command.
 * @command: the command to handle.
 * Return: the full path of the command.
*/
char *_getpath(char *command)
{
	list_dir *ld, *tmp;
	char *path;
	struct stat st;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/') /* Check if command is already a path */
		{
			if (stat(command, &st) == 0) /* If the path is valid, return it */
				return (_strdup(command));
			return (NULL);
		}
	}
	ld = build_dir_list(); /* Build list of path directories */
	tmp = ld;
	while (tmp)
	{
		/* size = len(directory) + len(command) + 2 ('/' and '\0') */
		path = malloc(_strlen(tmp->dir) + _strlen(command) + 2);
		if (!path)
		{
			free_list_dir(ld);
			return (NULL);
		}
		_strcpy(path, tmp->dir);
		_strcat(path, "/");
		_strcat(path, command);
		if (stat(path, &st) == 0) /* If the path is valid return it */
		{
			free_list_dir(ld);
			return (path);
		}
		free(path), path = NULL;
		tmp = tmp->next;
	}
	free_list_dir(ld);
	return (NULL);
}
