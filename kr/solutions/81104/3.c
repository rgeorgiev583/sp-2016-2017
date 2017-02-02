#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SIZE 1000

int main(int argc, char** argv){
    if (argc < 4) return 1;
    for (int i = 3; i < argc; i++){
		if (!fork()){
			close(0);
			open(argv[i], O_RDONLY);
			execlp("tr", "tr", argv[1], argv[2], NULL);
		}
	}
    for (int i = 3; i < argc; i++){
        int status;
        wait(&status);
    }
    return 0;
}
