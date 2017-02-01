#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

//ZADACHA 1
// DANIEL DELCHEV 81211

int main(int argc, const char** argv)
{
    if (argc<4){
        perror("Usage: zada4a_1 GAP_SIZE FROM_FILE TO_FILE");
        exit(0);
    }

    int N = atoi(*(argv+1));

    int fromFD = open(*(argv+2),O_RDONLY);
    if (fromFD<0){
        perror("Could not open file!\n");
        exit(0);
    }
    int toFD = open(*(argv+3),O_RDWR);
    if (fromFD<0){
        perror("Could not open file!\n");
        exit(0);
    }

    lseek(toFD,N,SEEK_END);

    char buffer = '0';
    while(read(fromFD,&buffer,1)){
        write(toFD,&buffer,1);
    }

    close(fromFD);
    close(toFD);

    return 0;
}
