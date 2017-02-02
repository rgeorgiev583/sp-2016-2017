#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SIZE 1000

int main(int argc, char** argv){
    if (argc < 4) return 1;
	char buf[BUFF_SIZE];
	int len;
	int fd1 = open(argv[2], O_WRONLY);
	int fd2 = open(argv[3], O_RDONLY);
	lseek(fd1, atoi(argv[1]), SEEK_END);
	while ((len = read(fd2, buf, BUFF_SIZE))) write(fd1, buf, len);
    return 0;
}

