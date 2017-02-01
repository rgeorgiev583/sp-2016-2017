#include <unistd.h>


int main()
{
    int fds[2];
    pipe(fds);

    if (!fork())
    {
        close(fds[0]);

        close(1);
        dup(fds[1]);

        execlp("who", "who", NULL);
    }

    close(fds[1]);

    close(0);
    dup(fds[0]);

    execlp("wc", "wc", "-l", NULL);

    return 0;
}
