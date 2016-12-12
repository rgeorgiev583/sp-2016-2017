#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 1024
#define MAXARGS 100

size_t readline(char* buf, size_t len)
{
    size_t pos = 0;
    while (pos < len && read(0, &buf[pos], 1) && buf[pos] != '\n')
        pos++;
    if (pos < len)
        buf[pos] = '\0';
    return pos;
}

int main(int argc, char** argv)
{
    do
    {
        write(1, "$ ", 2);

        char cmd[BUFSIZE];
        readline(cmd, BUFSIZE);

        char* cmd_argv[MAXARGS];
        size_t cmd_pos = 0;
        cmd_argv[cmd_pos++] = strtok(cmd, " ");
        do
            cmd_argv[cmd_pos] = strtok(NULL, " ");
        while (cmd_argv[cmd_pos++]);

        if (!strcmp(cmd_argv[0], "exit") || !strcmp(cmd_argv[0], "quit"))
            exit(0);

        pid_t pid = fork();
        if (!pid)
            execvp(cmd_argv[0], cmd_argv);
        else
        {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status))
                printf("%d\n", WEXITSTATUS(status));
        }
    }
    while (1);

    return 0;
}
