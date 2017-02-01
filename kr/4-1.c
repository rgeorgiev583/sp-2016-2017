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

        argv[0] = "grep";
        execvp(argv[0], argv);
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

        execlp("sort", "sort", NULL);
    }

    close(fds1[0]);
    close(fds2[1]);

    int fds3[2];
    pipe(fds3);

    if (!fork())
    {
        close(fds3[0]);

        close(0);
        dup(fds2[0]);
        close(1);
        dup(fds3[1]);

        execlp("uniq", "uniq", NULL);
    }

    close(fds3[1]);

    close(0);
    dup(fds3[0]);

    execlp("wc", "wc", "-l", NULL);
}
