
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

#define BUFF_SIZE 1000

int main(int argc, char** argv){
	for (int i = 2; i < argc; i++){
		char buf[BUFF_SIZE];
		char strbuf[100];
		strcpy(strbuf,"pidof -s ");
		strcat(strbuf,argv[i]);
		FILE *cmd_pipe = popen(strbuf, "r");
		fgets(buf, BUFF_SIZE, cmd_pipe);
		pid_t pid = strtoul(buf, NULL, 10);
		pclose( cmd_pipe );
		kill(pid, SIGKILL);
	}
	return 0;
}
