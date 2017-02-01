#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char** argv) {
    int fd[2];
    pipe(fd);

    if (fork()==0) {
        close(fd[0]);
        close(1);
        dup(fd[1]);

        if(execlp("pgrep", "pgrep", argv[1], NULL) < 0) {
            printf("cannot execute\n");
            exit(1);
        }
    } else {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        int pid;
        while (scanf("%d", &pid) != EOF)
            kill(pid, SIGTERM);
    }

    return 0;
}
