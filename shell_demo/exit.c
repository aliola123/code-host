#include "shell.h"
/**
 * my_exit - exit a process
 * @command_cache: the command entered
 * Return: nothing
 */
void my_exit(char *command_cache, int status)
{
        char error_msg[20];

        cleanup(command_cache);

        if (command_cache != NULL && command_cache[0] != '\0')
        {
                status = _atoi(command_cache);

                if (status == 0 && command_cache[0] != '0')
                {
                        _strcpy(error_msg, "Exit with error: ");
                        write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
                        write(STDERR_FILENO, command_cache, _strlen(command_cache));
                        write(STDERR_FILENO, "\n", 1);
                        exit(1);
                }
                exit(status);
        }
        exit(0);
}


/**
 * check_builtin - checks for builtin command
 * @args: the argument count
 * @command_cache: the command entered
 * Return: 1 if it's built-in, 0 otherwise
 */
int check_builtin(char *args[], char *command_cache)
{
        int status;

        if (_strcmp(args[0], "exit") == 0)
        {
                status = (args[1] != NULL && args[1][0] != '\0');
                my_exit(command_cache, status);
                return (1);
        }

        return (0);
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
        int i;

        i = 0;
        while (s1[i] != '\0' && s2[i] != '\0')
        {
                if (s1[i] != s2[i])
                {
                        return (s1[i] - s2[i]);
                }
                i++;
        }
        return (0);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 * Return: A integer
 */
int _atoi(char *s)
{

        int c = 0;
        unsigned int ni = 0;
        int min = 1;
        int isi = 0;

        while (s[c])
        {
        if (s[c] == 45)
        {
        min *= -1;
        }
        while (s[c] >= 48 && s[c] <= 57)
        {
        isi = 1;
        ni = (ni * 10) + (s[c] - '0');
        c++;
        }
        if (isi == 1)
        {
        break;
        }
        c++;
        }
        ni *= min;
        return (ni);
}

/**
 *   _strcpy - Copy a string
 *   @dest: Destination value
 *   @src: Source value
 *   Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
        int i;

        for (i = 0; src[i] != '\0'; i++)
        {
                dest[i] = src[i];
        }
        dest[i++] = '\0';
        return (dest);
}
