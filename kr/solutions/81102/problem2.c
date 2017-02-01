#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1000
int main(int argc, char** argv)
{
    if(argc < 4) {
        write(2,"Error!",6);
        exit(0);
    }

    int fd = open(argv[3], O_RDONLY, 0777);
	close(0);
	dup(fd);
	close(fd);

	inf fd1 = open(argv[4], O_WRONLY, 0777);
	close(1);
	dup(fd1);
	close(fd1);

	if (execlp("tr", "tr", arv[1], argv[2], NULL) < 0) {
        printf("Fatal error\n");
        exit(1);
	}
  return 0;
}
