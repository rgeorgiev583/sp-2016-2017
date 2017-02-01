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
    int pds[argc / 2 - 1][2];
    int i, j;
    for (i = 0; i < argc/2 - 1; ++i) {
        pipe(pds[i]);
    }
    if (!fork()) {
        close(1);
        dup(pds[0][1]);
        for (j = 0; j < argc/2 - 1; ++j) {
            close(pds[j][0]);
            close(pds[j][1]);
        }
        execlp(argv[0], argv[0], argv[1], (char*)NULL);
    }
    for (i = 1; i < argc/2 - 1; ++i) {
        if (!fork()) {
            close(0);
            dup(pds[i-1][0]);
            close(1);
            dup(pds[i][1]);
            for (j = 0; j < argc/2 - 1; ++j) {
                close(pds[j][0]);
                close(pds[j][1]);
            }
            execlp(argv[2*i+1], argv[2*i+1], argv[2*i+2], (char*)NULL);
        }
    }
    if (!fork()) {
        close(0);
        dup(pds[argc/2-2][0]);
        for (j = 0; j < argc/2 - 1; ++j) {
            close(pds[j][0]);
            close(pds[j][1]);
        }
        execlp(argv[argc-2], argv[argc-2], argv[argc-1], (char*)NULL);
    }
    return 0;
}
