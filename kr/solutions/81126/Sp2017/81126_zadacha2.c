#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv){
    if (argc < 5){
        return 1;
    }

    if (!fork()){
        close(0);
        open(argv[3], O_RDONLY);
        close(1);
        open(argv[4], O_WRONLY | O_CREAT);
        execlp("tr", argv[1], argv[2], NULL);
    }

    int status;
    wait(&status);

    return 0;
}
