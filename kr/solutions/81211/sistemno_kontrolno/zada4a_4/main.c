#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

//zada4a 4
//Daniel Delchev 81211

int main(int argc, const char** argv)
{
    if (argc<2){
        perror("usage: zada4a_4 REGEX FILE1 [FILE2] [FILE3] ...");
        exit(0);
    }

    int pipeWC [2];
    pipe(pipeWC);

    int pid1 = fork();
    if (pid1<0){
        perror("could not fork1 !\n");
    }
    if (!pid1){
        int pipeUNIQ [2];
        pipe(pipeUNIQ);
        int pid2 = fork();
        if (pid2<0){
            perror("could not fork1 !\n");
        }
        if(!pid2){//in grand child
            int pipeSORT [2];
            pipe(pipeSORT);

            int pid3 = fork();
            if (pid3<0){
                perror("could not fork3 !\n");
            }
            if (!pid3){ //in grand-grand-child
                //perform grep here
                close(pipeSORT[0]);
                dup2(pipeSORT[1],1); //write into pipeSORT 1 the result of grep
                close(pipeSORT[1]);

                const char* argList[argc+1];
                for (int i=1;i<argc;i++){
                    argList[i] = *(argv+i);
                }
                argList[0] = "/usr/bin/grep";
                argList[argc] = NULL;
                execv("/usr/bin/grep",(char* const*) argList);
                perror("Could not exec grep!\n");
            }
            else{// in grand child
                close(pipeSORT[1]);
                dup2(pipeSORT[0],0); //read the result of grep
                close(pipeSORT[0]);

                close(pipeUNIQ[0]);
                dup2(pipeUNIQ[1],1); //write the following result of SORT into UNIQ pipe
                close(pipeUNIQ[1]);

                const char* argList[2] = {"/usr/bin/sort",NULL};
                execv("/usr/bin/sort",(char* const*) argList);
                perror("Could not exec grep!\n");
            }
        }
        else{//in child
            close(pipeUNIQ[1]);
            dup2(pipeUNIQ[0],0);
            close(pipeUNIQ[0]);

            close(pipeWC[0]);
            dup2(pipeWC[1],1);
            close(pipeWC[1]);

            const char* argList[2] = {"/usr/bin/uniq",NULL};
            execv("/usr/bin/uniq",(char* const*) argList);
            perror("Could not exec grep!\n");
        }

    }
    else{//in father (initial process)
            close(pipeWC[1]);
            dup2(pipeWC[0],0);
            close(pipeWC[0]);

            const char* argList[3]= {"/usr/bin/wc","-l",NULL};
            execv("/usr/bin/wc",(char* const*) argList);
            perror("Could not exec grep!\n");
    }

    return 0;
}
