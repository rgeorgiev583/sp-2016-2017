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
        if (argc != 4) {
                printf("Error: Insufficient parameters.\n");
                return 1;
        }

        int fd1 = open(argv[2], O_RDONLY);
        if(fd1 == -1) {
                printf("Error: couldn't open first file.\n");
                return 1;
        }

        int fd2 = open(argv[3], O_RDWR);
        if(fd2 == -1) {
                printf("Error: couldn't open second file.\n");
                return 1;
        }

        if(lseek(fd2, atoi(argv[1]), SEEK_END) == -1) {
                printf("Seek error\n");
                return 1;
        }

        int n;
        char buff[1024];
        while((n=read(fd1, buff, 1024)) > 0)
                write(fd2, buff, n);

        close(fd1);
        close(fd2);
        printf("Success\n");
        return 0;
}
