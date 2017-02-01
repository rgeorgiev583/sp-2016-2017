#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define bs 1000
char buff[bs+1];
void writefile(int inputfd, int outputfd){
    int bytes = 1;
    while(bytes>0){
        bytes = read(inputfd, buff, bs);
        write(outputfd, buff, bytes);
    }
}

int main(int argc, char **argv){
    int i2 = open(argv[3], O_RDONLY);
    int output = open(argv[2], O_WRONLY);
    int n = atoi(argv[1]);
    lseek(output, n,SEEK_END);
    writefile(i2, output);
    return 0;
}
