#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SIZE 1000

int main(int argc, char** argv){
    if (argc < 5) return 1;
    close(0);
    open(argv[4], O_RDONLY);
	close(1);
	open(argv[5], O_WRONLY);
    execlp("tr", "tr", argv[1], argv[2], NULL);
    return 0;
}
