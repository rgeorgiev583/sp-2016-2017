#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


//ZADACHA 2
//DANIEL DELCHEV 81211


int main(int argc, const char** argv)
{
    if (argc<5){
        perror("Usage: zada4a_2 SET1 SET2 FILE_FROM FILE_TO");
    }

    int fromFD = open(*(argv+3),O_RDONLY);
    if (fromFD<0){
        perror("Could not open file!\n");
        exit(0);
    }

    int toFD = open(*(argv+4),O_RDWR|O_CREAT);
    if (toFD<0){
        perror("Could not open file!\n");
        exit(0);
    }

    dup2(fromFD,0);
    close(fromFD);

    dup2(toFD,1);
    close(toFD);

    const char* argList[4] = {"/user/bin/tr",*(argv+1),*(argv+2),NULL};
    execv("/usr/bin/tr",(char* const*) argList);

    perror("Unsuccessful execv!\n");

    return 1;
}
