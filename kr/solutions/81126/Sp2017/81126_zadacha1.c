#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char** argv)
{
    char buf[BUF_SIZE];
    int lenght,fd,fd2;

    if(argc<4)
        return 1;

    fd=open(argv[2], O_WRONLY);
    fd2=open(argv[3], O_RDONLY);

    lseek(fd, atoi(argv[1]), SEEK_END);

    while((lenght=read(fd2,buf,BUF_SIZE))>0)
    {
        if(write(fd,buf,lenght)!= lenght)
            return 1;
    }
    return 0;

}
