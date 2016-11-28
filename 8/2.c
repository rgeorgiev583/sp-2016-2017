#include <unistd.h>

int main(int argc, char** argv)
{
    int fd[2];
    pipe(fd);

    if (!fork())
    {
        close(0);
        close(fd[1]);
        dup(fd[0]);
        execlp("wc", "wc", "-l", NULL);
    }
    else
    {
        close(1);
        close(fd[0]);
        dup(fd[1]);
        argv[0] = "grep";
        execvp("grep", argv);
    }

    return 0;
}
