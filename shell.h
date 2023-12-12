#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_CMD_LEN 100
#define DELIM " \t\n"
extern char **environ;
char *read_user_input(void);
char **tokenizer(char *line);
int _execute(char **command, char **argv)


char *_strdup( const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void freearray2D(char **arr);

#endif /* SHELL_H */
