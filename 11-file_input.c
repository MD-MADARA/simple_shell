#include "shell.h"
/**
 * get_file_input - get input from file.
 * @argv: arguments.
 * Return: a struct file_input contains datas of input.
*/
file_input get_file_input(char **argv)
{
	int fd, r, i = 0;
	char buffer[4096], *line = NULL;
	char mssg1[] = ": 0: cannot open ", mssg2[] = ": No such file\n";
	file_input data;

	data.len = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, mssg1, _strlen(mssg1));
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, mssg2, _strlen(mssg2));
		exit(2);
	}
	r = read(fd, buffer, 4095);
	if (r <= 0)
		return (data);
	buffer[r] = '\0';

	line = strtok(buffer, "\n");
	while (line)
	{
		data.lines[i] = _strdup(line);
		line = strtok(NULL, "\n");
		i++;
		data.len++;
	}
	close(fd);
	return (data);
}
