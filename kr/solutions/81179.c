#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#define BUF_SIZE 1000

int main(int argc, char** argv)
{
    //zad1(argc,argv);
    //zad2(argc,argv);
    //zad3(argc,argv);

    //zad4
    int fd[2];
    pipe(fd);

    if(fork()){
        close(0);
        close(fd[1]);
        dup(fd[0]);

        int fd2[2];
        pipe(fd2);


        if(fork()){
            close(0);
            close(fd2[1]);
            dup(fd2[0]);

            int fd3[2];
            pipe(fd3);

            if(fork()){
                close(0);
                close(fd3[1]);
                dup(fd3[0]);
                execlp("wc","wc","-l",NULL);

            }else{
                close(1);
                dup(fd3[1]);
                close(fd3[0]);
                execvp("uniq", NULL);
            }
        }else{
            close(1);
            dup(fd2[1]);
            close(fd2[0]);
            execvp("sort", NULL);
        }

   }else{
    close(1);
    dup(fd[1]);
    close(fd[0]);
    execvp("grep", argv);
   }

    return 0;
}

int zad3(int argc, char** argv){
    for (int i = 3; i < argc; i++)
        if (!fork())
        {
            close(0);
            open(argv[i], O_RDONLY);
            execlp("tr", argv[1], argv[2], NULL);
        }
    return 0;
}

int zad2(int argc, char** argv){
    close(0);
    open(argv[3], O_RDONLY);
    close(1);
    open(argv[4], O_WRONLY);

    execl("/usr/bin/tr", "tr", argv[1], argv[2], NULL);
    return 0;
}


int zad1(int argc, char** argv){

    int fd1 = open(argv[2], O_WRONLY);
    lseek(fd1, atoi(argv[1]), SEEK_END);

    char buf[BUF_SIZE];
    int fd2 = open(argv[3], O_RDONLY);
    while(read(fd2, buf, BUF_SIZE) > 0)
        write(fd1, buf, BUF_SIZE);

    return 0;
}
