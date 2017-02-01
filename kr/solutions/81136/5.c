#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    if (argc < 2){
        return 1;
    }

    for (int i = 2; i < argc; i++){
        kill(atoi(argv[i]), SIGTERM);
    }


    return 0;
}
