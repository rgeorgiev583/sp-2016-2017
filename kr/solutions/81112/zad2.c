#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char **argv){
    int file = open(argv[3], O_RDONLY);
    int dest = open(argv[4],O_WRONLY);

    dup2(file, 0);
    dup2(dest, 1);
    execlp("tr", "tr", argv[1], argv[2], NULL);
    return 0;
}
