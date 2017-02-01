#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv) {

    if(argc < 3) {
        write(2,"Error!",6)'
        exit(0);
    }

    int n = atoi(argv[1]);
    int writeF = open(argv[2], O_WRONLY| O_APPEND);
    int readF = open(argv[3], O_RDONLY);

    lseek(writeF,n,SEEK_END);
    int nBytes;
    char* buff;
    if((nBytes = read(readF, buff, 100)) > 0) {
        write(writeF, buff, nBytes);
    }

    return 0;

}
