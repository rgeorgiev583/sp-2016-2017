#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> // removes warnings when using fork()
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

//BONUS 3
//Daniel Delchev 81211


int main(int argc,const char** argv)
{
    if (argc == 1){
        char prompt = '$';
        while (true){
            char* buffer = NULL;
            ssize_t read = 0;
            size_t len = 0;
            write(1,&prompt,1);
            read = getline(&buffer,&len,stdin);
            if (read<=0){
                perror("getline failed!\n");
            }
            char delimiter[4] = " \n\t";
            int counter = 0;
            char* argument[64];

            argument[0] = strtok(buffer, delimiter);
            while( argument[counter] != NULL ){
                argument[++counter] = strtok(NULL, delimiter);
            }
            if (counter==0){
                continue;
            }
            argument[++counter] = NULL;

            char name []="/usr/bin/";
            strcat(name,argument[0]);

            pid_t pid = fork();
            if (pid<0){
                perror("could not fork!\n");
                free(buffer);
                exit(1);
            }
            if (pid==0){
                execv(name,(char* const* ) argument);
                perror("Unknown command!\n");

            }
            if (pid>0){
                int status = 0;
                wait(&status);
                free(buffer);
                printf("%d",status);
            }

        }
    }
    return 0;
}
