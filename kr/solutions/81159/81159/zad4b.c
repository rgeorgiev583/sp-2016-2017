#include <unistd.h>

int main(int argc, char** argv)
{
    int fd[2];
    pipe(fd);

    if (!fork())
    {
        close(1);
        close(fd[0]);
        dup(fd[1]);
        execvp(argv[1], argv[2]);
    }
    else
    {
        int fd2[2];
        pipe(fd2);

        if (!fork())
        {
          close(0);
          close(fd2[1]);
          dup(fd2);
          execvp(argv[3], argv[4]);
        }

        close(0);
        close(fd[1]);
        dup(fd[0]);
        execlp(argv, NULL);
    }

    return 0;
}
