#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUFF_SIZE 1000

//task 1
int main(int argc, char** argv){
    if (argc < 4) return 1;
	char buf[BUFF_SIZE];
	int len;
	int fd1 = open(argv[2], O_WRONLY);
	int fd2 = open(argv[3], O_RDONLY);
	lseek(fd1, argv[1], SEEK_END);
	while ((len = read(fd2, buf, BUFF_SIZE))) write(fd1, buf, len);
    return 0;
}

//task2
int main(int argc, char** argv){
    if (argc < 5) return 1;
    close(0);
    open(argv[4], O_RDONLY);
	close(1);
	open(argv[5], O_WRONLY);
    execlp("tr", argv[1], argv[2], NULL);
    return 0;
}

//task3
int main(int argc, char** argv){
    if (argc < 4) return 1;
    for (int i = 3; i < argc; i++){
		if (!fork()){
			close(0);
			open(argv[i], O_RDONLY);
			execlp("tr", argv[1], argv[2], NULL);
		}
	}
    for (int i = 3; i < argc; i++){
        int status;
        wait(&status);
    }
    return 0;
}

//task4
int main(int argc, char** argv){
	
	return 0;
}

//bonus1
int main(int argc, char** argv){
	if (argc == 1) return 1;
	for (int i = 2; i < argc; i++) kill(argv[i], SIGKILL);
	return 0;
}

//bonus2
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




























