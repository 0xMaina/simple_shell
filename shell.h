#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1

void promp(void);
char *command_line();
char **separate(char *string);
int execute(char **str, char *av, char **en);
int check(char **string, char **env);
size_t len_str(const char *string);
int compare(const char *s, const char *c);
char *str_dup(const char *str);
char *_getline(void);
char **separate1(char *string);
int split(char *s);
int no_line(char *s);
void free_s(char **string);
void free_str(char *string, char **arr, int i);
void conv_str(int num, char *str);
char *handle_path(char *PATH, char **str);
int _atoi(char *s);
int _exitt(char **argv);
#endif
