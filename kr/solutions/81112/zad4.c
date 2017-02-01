#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char** argv) {

    int wc[2];
	int sort[2];
	int uq[2];
    //pipe(wc);
    //pipe(sort);
    //pipe(unique);

    if(!fork()){
        /*exec grep */
        pipe(sort);
        close(sort[0]);
        dup2(sort[1],1);

        if(!fork()){
            /*exec sort*/
            close(sort[1]);
            dup2(sort[1],0);
            pipe(uq);
            close(uq[0]);
            dup2(uq[1],1);

            if(!fork()){
                /* exec unique */
                close(uq[1]);
                dup2(uq[1], 0);
                pipe(wc);
                close(wc[0]);
                dup2(wc[1],1);

                if(!fork()){
                    /* exec wc */
                    close(wc[1]);
                    dup2(wc[1],0);
                    execlp("wc", "-l", NULL);
                }else{
                    execlp("unique");
                }
            }else{
                execlp("sort");
            }
        }else{
            execlp("grep", argv + 1);
        }
    }
}
