#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    if (argc != 3)
        exit(-1);

    int n = atoi(argv[1]);
    char* firstFilePath = argv[2];
    char* secondFilePath = argv[3];

    pid1 = open(firstFilePath, O_WRONLY | O_APPEND);
    pid2 = open(secondFilePath, O_RDONLY);

    char* readBuf;
    lseek(pid1,n,SEEK_END);

    while(read(pid2,readBuf,100) > 0)
        write(pid1,readBuf,100);

    return 0;
}
