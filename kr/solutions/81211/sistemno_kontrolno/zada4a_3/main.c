#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> // removes warnings when using fork()
#include <fcntl.h>
#include <stdbool.h>

//zada4a_3
//DanielDelchev 81211

int main(int argc,const char** argv)
{

    if (argc<4){
        perror("not enough arugments!Usage 'zada4a_3 ab cd FILE1 FILE2 FILE3...'\n");
        return -1;
    }

    //1 for filename of exe file,1 for letters to replace, 1 for letters to replace with,
    int count = argc - 3;
    int pid = -1;
    for (int i=0;i<count;i++){
        if( (pid = fork())<0){
            perror("could not fork!\n");
        }
        if(pid==0){
            //redirecting stanart input to the file
            int fd = open(*(argv+3+i),O_RDONLY);
            dup2(fd,0);

            const char* arguments[]={"tr",*(argv+1),*(argv+2),NULL};
            execv("/usr/bin/tr",(char* const*)arguments);
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
