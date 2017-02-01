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
    int i;
    for (i = 1; i < argc; ++i)
        kill(atoi(argv[i]), SIGKILL);

    return 0;
}
