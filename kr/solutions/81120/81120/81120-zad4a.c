#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv) {

    int fd1[2];
	int fd2[2];
	int fd3[2];
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);

    if (!fork()) {
        close(1);
        close(fd1[0]);
        dup(fd1[1]);
        argv[0] = "grep";
        if(execvp("grep", argv)<0) {
            printf("cannot execute\n");
            exit(1);
        }
    }

    if (!fork()) {
        close(0);
        close(fd1[1]);
        dup(fd1[0]);
		close(1);
		dup(fd2[1]);
        if(execlp("sort", "sort", NULL) < 0) {
            printf("cannot execute\n");
            exit(1);
        }
    }

	if(!fork()) {
		close(0);
        dup(fd2[0]);
		close(1);
		dup(fd3[1]);
        if(execlp("uniq", "uniq",NULL) < 0) {
            printf("cannot execute\n");
            exit(1);
        }
	} else {
		close(0);
        dup(fd3[0]);
        if(execlp("wc", "wc","-l" NULL) < 0) {
            printf("cannot execute\n");
            exit(1);
        }
	}
}
