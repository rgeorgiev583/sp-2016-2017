
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SIZE 1000

int main(int argc, char** argv){
	if (argc == 1) return 1;
	for (int i = 2; i < argc; i++) kill(atoi(argv[i]), SIGKILL);
	return 0;
}
