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
        argv[0] = "grep";
        execvp("grep", argv);
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
