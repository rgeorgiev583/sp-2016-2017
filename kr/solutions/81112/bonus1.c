#include <unistd.h>
#include <signal.h>
#include <stdio.h>


int main(int argc, char **argv){
    for(int i = 1; i < argc ; i++){
        kill(atoi(argv[i]), SIGTERM);
    }
}
