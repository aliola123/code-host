#include "shell.h"

/**
 * read_command - reads command given
 * @command_cache: the memory
 * @command_bytes: the memory size
 * Return: pointer
 */

ssize_t read_command(char **command_cache, size_t *command_bytes)
{
        ssize_t command = getline(command_cache, command_bytes, stdin);

        return (command);
}
