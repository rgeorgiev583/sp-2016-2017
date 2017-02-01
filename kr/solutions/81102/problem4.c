#include <unistd.h>

int main(int argc, char** argv){
    int fd[2];
    pipe(fd);

    if (!fork())
    {
        close(1);
        close(fd[0]);
        dup(fd[1]);
        execvp("grep", argv);
    }
    else
    {
        int fd2[2];
        pipe(fd2);

        if (!fork())
        {
            close(0);
            close(fd2[1]);
            dup(fd2[0]);
            close(1);
            dup(fd2[1]);
            execlp("sort", "sort", NULL);
        }

        else {
            int fd3[2];
            pipe(fd3);

            if (!fork())
            {
                close(0);
                close(fd3[1]);
                dup(fd2[0]);
                close(1);
                dup(fd3[1]);
                execlp("uniq", "uniq", NULL);
            }
            close(0);
            close(fd3[1]);
            dup(fd3[0]);
            execlp("wc", "wc", "-l", NULL);
        }
    }

return 0;
}
