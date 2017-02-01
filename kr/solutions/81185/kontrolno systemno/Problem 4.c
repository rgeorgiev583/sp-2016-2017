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
        argv[1] = "grep";
        execvp("grep", argv + 1);
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
            execlp("sort", "sort", NULL);

        }
        else {
            close(1);
            close(fd2[0]);
            dup(fd2);
            execvp("uniq","uniq",NULL);
        }

        close(0);
        close(fd[1]);
        dup(fd[0]);
        execlp("wc", "wc", "-l", NULL);
    }

    return 0;
}