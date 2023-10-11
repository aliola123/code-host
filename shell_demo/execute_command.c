#include "shell.h"
/**
 * execute_child - function that executes the child process
 * @args: pointer to the argument count
 * Return: 0 if successful
 */
int execute_child(char *args[])
{
        char *execut;
        int exec;

        execut = find_exec(args[0]);

        if (execut == NULL)
        {
                perror("Executable not found.\n");
                return (-1);
        }

        exec = execve(execut, args, NULL);
        if (exec == -1)
        {
                perror("Execve failed");
                return (-1);
        }

        return (0);
}

/**
 * execute_parent - function to keep parent process on hold until child execute
 * @pid: the child process id
 * Return: 0 if successful, -1 otherwise
 */
int execute_parent(pid_t pid)
{
        int status;
        int wait_result = waitpid(pid, &status, 0);

        if (wait_result == -1)
        {
                perror("waitpid failed");
                return (-1);
        }

        return (0);
}

/**
 * execute_command - function to execute the command entered
 * @command_cache: command entered by users
 * Return: the pid of the calling process
 */

int execute_command(char *command_cache)
{
        char *args[MAX_ARGUMENTS];
        pid_t pid;

        if (prepare_command_args(command_cache, args) == -1)
                return (-1);
        if (check_builtin(args, command_cache))
        {
                return (0);
        }

        pid = fork();

        if (pid == -1)
        {
                perror("Fork failed");
                return (-1);
        }
        else if (pid == 0)
        {
                return (execute_child(args));
        }
        else
        {
                return (execute_parent(pid));
        }
}
