#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>

char *_strcpy(char *dest, char *src);
int _atoi(char *s);
ssize_t read_command(char **command_cache, size_t *command_bytes);
int execute_command(char *command_cache);
int execute_child(char *args[]);
int execute_parent(pid_t pid);
int execute_command(char *command_cache);
void cleanup(char *command_cache);
char *find_exec(char *command_cache);
int prepare_command_args(char *command_cache, char **args);
ssize_t _getline(char **_ptr, size_t *num);
int _strlen(char *s);
char *_strchr(const char *s, int ch);
char *_strtok(char *s, const char *del);
int check_builtin(char *args[], char *command_cache);
void my_exit(char *command_cache, int status);
int _strcmp(char *s1, char *s2);
int initialize_buffer(char **_ptr, size_t *_num);
ssize_t read_line(char **_ptr, size_t *_num);

#define PROMPT_SIZE 2
#define MAX_ARGUMENTS 64
#define INIT_BUF_SZ 128

#endif
