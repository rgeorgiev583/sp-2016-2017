#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFSIZE 1024
#define MAXARGS 100


size_t readline(int fd, char* buf, size_t len)
{
    size_t pos = 0;
    while (pos < len && read(fd, &buf[pos], 1) && buf[pos] != '\n')
        pos++;
    if (pos < len)
        buf[pos] = '\0';
    return pos;
}

size_t execline(int fd)
{
    char cmd[BUFSIZE];
    size_t cmd_len = readline(fd, cmd, BUFSIZE);

    char* cmd_argv[MAXARGS];
    size_t cmd_pos = 0;
    cmd_argv[cmd_pos++] = strtok(cmd, " ");
    do
        cmd_argv[cmd_pos] = strtok(NULL, " ");
    while (cmd_argv[cmd_pos++]);

    if (!strcmp(cmd_argv[0], "exit") || !strcmp(cmd_argv[0], "quit"))
        exit(0);

    pid_t pid = fork();
    if (!pid && execvp(cmd_argv[0], cmd_argv) < 0)
    {
        printf("error: command `%s` does not exist\n", cmd_argv[0]);
        exit(0);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char** argv)
{
    if (argc == 1)
        do
        {
            write(1, "$ ", 2);
            execline(0);
        }
        while (1);
    else
        for (size_t i = 1; i < argc; i++)
        {
            int fd = open(argv[i], O_RDONLY);
            execline(fd);
        }

    return 0;
}
