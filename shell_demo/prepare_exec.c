#include "shell.h"

/**
 * prepare_command_args - prepare the command arguments.
 * @command_cache: command entered
 * @args: array to store command arguments.
 * Return: 0 if successful, -1 if an error occurs.
 */

int prepare_command_args(char *command_cache, char **args)
{
        char *delim = " ";
        char *token;
        int arg_index = 0;

        token = strtok(command_cache, delim);
        while (token != NULL)
        {
                args[arg_index++] = token;
                token = strtok(NULL, delim);

        if (arg_index >= MAX_ARGUMENTS - 1)
        {
                perror("Too many command arguments.\n");
                return (-1);
        }
}
        args[arg_index] = NULL;

        return (0);
}
