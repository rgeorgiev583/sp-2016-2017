#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    char* firstFilePath = argv[2];
    char* secondFilePath = argv[3];

    int pid1 = open(firstFilePath, O_WRONLY | O_APPEND);
    int pid2 = open(secondFilePath, O_RDONLY);

    char readBuf[100];
    int len;
    lseek(pid1,n,SEEK_END);

    while(len = read(pid2,readBuf,100))
        write(pid1,readBuf,len);

    return 0;
}
