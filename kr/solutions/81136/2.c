#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    if (argc != 5)
        return 1;

    int fd1 = open(argv[3], O_RDONLY);
    int fd2 = open(argv[4],O_WRONLY);

    dup2(fd1, 0);
    dup2(fd2, 1);
    execlp("tr", argv[1], argv[2], NULL)

    return 0;
}
