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
    int pd1[2], pd2[2], pd3[2];
    pipe(pd1);
    if (!fork()) {
        close(1);
        dup(pd1[1]);
        close(pd1[0]);
        close(pd1[1]);
        execlp("grep", argv[1]);
    } else {
        pipe(pd2);
        if (!fork()) {
            close(0);
            dup(pd1[0]);
            close(1);
            dup(pd2[0]);
            close(pd1[0]);
            close(pd1[1]);
            close(pd2[0]);
            close(pd2[1]);
            execlp("sort", "sort", (char*)NULL);
        } else {
            pipe(pd3);
            if (!fork()) {
                close(0);
                dup(pd2[0]);
                close(1);
                dup(pd3[1]);
                close(pd1[0]);
                close(pd1[1]);
                close(pd2[0]);
                close(pd2[1]);
                close(pd3[0]);
                close(pd3[1]);
                execlp("uniq", "uniq", (char*)NULL);
            } else {
                close(0);
                dup(pd3[0]);
                close(pd1[0]);
                close(pd1[1]);
                close(pd2[0]);
                close(pd2[1]);
                close(pd3[0]);
                close(pd3[1]);
                execlp("wc", "wc", "-l", (char*)NULL);
            }
        }
    }

    return 0;
}

