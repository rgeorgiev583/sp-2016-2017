#define _POSIX_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char* argv[]) {
    int f, d;
    f = open(argv[3], O_RDONLY);
    d = open(argv[4], O_WRONLY | O_CREAT, 0666);

    close(0);
    dup(f);
    close(1);
    dup(d);

    execlp("tr", "tr", argv[1], argv[2], NULL);

    return 0;
}
