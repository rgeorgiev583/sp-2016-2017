#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> // removes warnings when using fork()
#include <fcntl.h>
#include <stdbool.h>

//BONUS 2
//DanielDelchev 81211

int main(int argc,const char** argv)
{


    int count = argc - 1;
    int pid = -1;
    for (int i=0;i<count;i++){
        if( (pid = fork())<0){
            perror("could not fork!\n");
        }
        if(pid==0){
            const char* arguments[]={"pkill",*(argv+i),NULL};
            execv("/usr/bin/pkill",(char* const*)arguments);
            perror("could not execv!\n");
        }
    }

    int status=0;
    if (pid){
        for (int i=0;i<count;i++){
            wait(&status);
        }
    }

    return 0;
}
