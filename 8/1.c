#include <unistd.h>

int main()
{
    int fd[2];
    pipe(fd);

    if (!fork())
    {
        close(1);
        close(fd[0]);
        dup(fd[1]);
        execlp("ls", "ls", NULL);
    }
    else
    {
        close(0);
        close(fd[1]);
        dup(fd[0]);
        execlp("wc", "wc", "-l", NULL);
    }

    return 0;
}
