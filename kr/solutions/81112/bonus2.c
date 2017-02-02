#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int fd[2];
    pipe(fd);
    for(int i = 1 ; i < argc; i++)
    {

        if (!fork())
        {
            close(fd[0]);
            dup2(fd[1],1);

            execlp("pgrep", "pgrep", argv[i], NULL);
        }
        else
        {
            close(fd[1]);
            dup2(fd[0],0);

            int pid;
            while (scanf("%d", &pid) != EOF)
                kill(pid, SIGTERM);
        }
    }


    return 0;
}
