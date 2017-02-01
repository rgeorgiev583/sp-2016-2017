#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){

    int fd1[2];
	int fd2[2];
	int fd3[2];
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);

    if (!fork()){
        close(1);
        close(fd1[0]);
        dup(fd1[1]);
        argv[0] = "grep";
        execvp("grep", argv);
    }

    if (!fork()){
        close(0);
        close(fd1[1]);
        dup(fd1[0]);
		close(1);
		dup(fd2[1]);
        execlp("sort", "sort", NULL);
    }

	if(!fork()){
		close(0);
        dup(fd2[0]);
		close(1);
		dup(fd3[1]);
        execlp("uniq", "uniq",NULL);
	}else{
		close(0);
        dup(fd3[0]);
        execlp("wc", "wc","-l" NULL);
	}
}
