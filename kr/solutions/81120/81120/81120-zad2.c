#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv) {

    if(argc < 5) {
        write(2,"Error!",6);
        exit(0);
    }

    int fdFile = open(argv[3], O_RDONLY, 0777);
	close(0);
	dup(fdFile);
	close(fdFile);

	inf fdDest = open(argv[4], O_WRONLY, 0777);
	close(1);
	dup(fdDest);
	close(fdDest);

	if(execlp("tr", "tr", arv[1],argv[2], NULL) < 0) {
        printf("cannot execute\n");
        exit(1);
	}

    return 0;
}


