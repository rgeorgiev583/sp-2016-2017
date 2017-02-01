#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int fd[2];
    pipe(fd);
    if (!fork())
    {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        execlp("pgrep", "pgrep", argv[1], NULL);
    }
    else
    {
        close(fd[1]);
        close(0);
        dup(fd[0]);

        int pid;
        while (scanf("%d", &pid) != EOF)
            kill(pid, SIGTERM);
    }

    return 0;
}
