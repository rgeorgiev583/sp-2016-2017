#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFSIZE 1000

void catwc(const char* arg)
{
    pid_t pid = fork();

    if (!pid)
        execlp("cat", "cat", arg, NULL);
    else
    {
        int status;
        waitpid(pid, &status, 0);
        execlp("wc", "wc", arg, NULL);
    }
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        char buf[BUFSIZE];
        int fd = open("/tmp/catwc", O_WRONLY | O_CREAT | O_TRUNC, 0x644);
        ssize_t len;

        while (len = read(0, buf, BUFSIZE))
            write(fd, buf, len);

        close(fd);
        catwc("/tmp/catwc");
        exit(0);
    }

    for (int i = 1; i < argc; i++)
        if (!fork())
            catwc(argv[i]);

    for (int i = 1; i < argc; i++)
    {
        int status;
        wait(&status);
    }

    return 0;
}
