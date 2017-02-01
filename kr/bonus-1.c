#include <unistd.h>
#include <signal.h>
#include <stdio.h>


int main(int argc, char** argv)
{
    int fds[2];
    pipe(fds);

    if (!fork())
    {
        close(fds[0]);
        close(1);
        dup(fds[1]);

        execlp("pgrep", "pgrep", argv[1], NULL);
    }

    close(fds[1]);
    close(0);
    dup(fds[0]);

    int pid;
    while (scanf("%d", &pid) != EOF)
        kill(pid, SIGTERM);

    return 0;
}
