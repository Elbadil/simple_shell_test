#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>


/* Functions */
char *file_path(char *filename);
char **split_cmd(char *str);
void print_environ(void);
int empty_line(char *line);
int handle_special_cmds(char **av, char *line);
void fork_execute(char *usr_cmd, char **av, char **env);
extern char **environ;
void own_exit(char **exit_av);

/* Utils */
char *_getenv(const char *name);
int _strlen(const char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

#endif
