#define _POSIX_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char** argv)
{
    if (argc == 3)
    {
        execlp("tr", argv[1], argv[2], NULL);
        exit(0);
    }

    for (int i = 3; i < argc; i++)
        if (!fork())
        {
            close(0);
            open(argv[i], O_RDONLY);
            execlp("tr", argv[1], argv[2], NULL);
        }

    for (int i = 3; i < argc; i++)
    {
        int status;
        wait(&status);
    }

    return 0;
}
