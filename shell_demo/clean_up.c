#include "shell.h"

/**
 * cleanup - cleans up the memory allocated
 * @command_cache: the memory to free
 * Return: nothing
 */
void cleanup(char *command_cache)
{
        free(command_cache);
}
