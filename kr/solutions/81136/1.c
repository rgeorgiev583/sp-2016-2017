#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc,char** argv){
    char myBuf[100];
    int bytes = 1;

    if (argc < 4)
        return 1;

    int fd1=open(argv[2],O_RDWR);
    int fd2=open(argv[3],O_RDONLY);

    lseek(fd1, atoi(argv[1]), SEEK_END);

    while(bytes>0){
        bytes = read(fd2,myBuf,100);
        write(fd1,myBuf,bytes);
    }

    return 0;
}
