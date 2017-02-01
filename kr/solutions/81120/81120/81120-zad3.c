#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv) {

    if(argc < 3){
        write(2,"Error!",6);
        exit(0);
    }

     if (argc == 3) {
        if(execlp("tr", argv[1], argv[2], NULL) < 0) {
            printf("cannot execute\n");
            exit(1);
        }
        exit(0);
    }
    int pid;
    for (int i = 3; i < argc; i++) {

        if ((pid=fork())<0) {
            write(2,"Error in fork!", 14);
            exit(0);
        } else if(pid==0) {
            close(0);
            open(argv[i], O_RDONLY);
            if(execlp("tr", argv[1], argv[2], NULL) < 0) {
                printf("cannot execute\n");
                exit(1);
            }
        }
    }

    for (int i = 3; i < argc; i++) {
        int status;
        wait(&status);
    }

    return 0;
}


