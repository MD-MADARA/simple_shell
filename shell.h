#ifndef SHELL_H
#define SHELL_H

/* headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/* macros */
#define DELIM " \n\t"
#define PROMPT "$ "

/* global variable */
extern char **environ;

/**
 * struct list_dir - singly linked list.
 * @dir: directorie name.
 * @next: points to the next node.
 * Description: singly linked list node structure.
 */
typedef struct list_dir
{
	char *dir;
	struct list_dir *next;
} list_dir;

/**
 * struct builtins - bultin and its function.
 * @builtin: the builtin name.
 * @f: function to handle the builtin.
 * Description: shell builtins.
 */
typedef struct builtins
{
	char *builtin;
	void (*f)(char **, char **, int*, int);
} builtins;

/* ========== 02-getline.c ========== */
char *_getline(void);

/* ========== 03-split_line.c ========== */
char **split_line(char *line);

/* ========== 04-execute.c ========== */
int _execute(char **command, char **argv, int idx);

/* ========== 05-getenv.c ========== */
char *_getenv(char *variable);

/* ========== 06-getpath.c ========== */
list_dir *build_dir_list(void);
char *_getpath(char *command);

/* ========== 07-bultins.c ========== */
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, char **argv, int *status, int idx);


/* ========== 10-linked_list.c ========== */
list_dir *add_node_end(list_dir **head, const char *str);
void free_list_dir(list_dir *head);

/* ========== 11-string.c ========== */
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* ========== 12-tools.c ========== */
void free2Darray(char **array);
void print_error(char *name, int idx, char *cmd);
void print_syntax_error(char *name, int idx);

/* ========== 13-tools2.c ========== */
char *_itoa(int n);
void reverse_string(char *str, int len);
int is_positive_number(char *str);
int _atoi(char *str);

char ***separator(char **command, char **argv, int *status, int idx);

void _setenv(char **command, char **argv, int *status, int idx);
void _unsetenv(char **command, char **argv, int *status, int idx);

#endif