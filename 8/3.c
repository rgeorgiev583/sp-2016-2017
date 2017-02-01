#include <unistd.h>


int main(int argc, char** argv)
{
    int fds1[2];
    pipe(fds1);

    if (!fork())
    {
        close(fds1[0]);

        close(1);
        dup(fds1[1]);

        argv[2] = argv[1];
        argv[1] = "head";
        execvp(argv[1], argv + 1);
    }

    close(fds1[1]);

    int fds2[2];
    pipe(fds2);

    if (!fork())
    {
        close(fds2[0]);

        close(0);
        dup(fds1[0]);
        close(1);
        dup(fds2[1]);

        execlp("grep", "grep", argv[2], NULL);
    }

    close(fds1[0]);

    close(fds2[1]);

    close(0);
    dup(fds2[0]);

    execlp("wc", "wc", "-l", NULL);
}
