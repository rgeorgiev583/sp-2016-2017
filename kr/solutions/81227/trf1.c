#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    int stin = open(argv[3], O_RDONLY);
    int stout = open(argv[4], O_WRONLY);

    close(0);
    dup(stin);

    close(1);
    dup(stout);

    execlp("tr", "tr", argv[1], argv[2], NULL);

    return 0;
}
