#include "shell.h"

/**
 * find_exec - Find the executable part of the command.
 * @command_cache: The command input.
 * Return: Pointer to the executable part of the command.
 */
char *find_exec(char *command_cache)
{
        char *delim = " ";

        return (strtok(command_cache, delim));
}
