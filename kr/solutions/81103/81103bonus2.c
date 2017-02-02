#define _POSIX_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFF_SIZE 1000

int main(int argc, char** argv){
	if (argc == 1) return 1;
	for (int i = 2; i < argc; i++){
		char buf[BUFF_SIZE];
		FILE *cmd_pipe = popen(strcat("pidof -s ", argv[i]), "r");
		fgets(buf, BUFF_SIZE, cmd_pipe);
		pid_t pid = strtoul(buf, NULL, 10);
		pclose( cmd_pipe );
		kill(pid, SIGKILL);
	}
	return 0;
}
