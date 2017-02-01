#define _POSIX_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int zad1(int argc, char* argv[]) {
	if (argc != 4) {
		printf("Error: Insufficient parameters.\n");
		return 1;
	}
	
	int fd1 = open(argv[2], O_RDONLY);
	if(fd1 == -1) {
		printf("Error: couldn't open first file.\n");
		return 1;
	}

	int fd2 = open(argv[3], O_RDWR);
	if(fd2 == -1) {
		printf("Error: couldn't open second file.\n");
		return 1;
	}

	if(lseek(fd2, atoi(argv[1]), SEEK_END) == -1) {
		printf("Seek error\n");
		return 1;
	}
	
	int n;
	char buff[1024];
	while((n=read(fd1, buff, 1024)) > 0) 
		write(fd2, buff, n);
 	
	close(fd1);
	close(fd2);
	printf("Success\n");
	return 0;
}

int zad2(int argc, char* argv[]) {
	if(argc != 5) {
		printf("Error with argc\n");
		return 1;
	}

	close(0);
	if(open(argv[3], O_RDONLY) == -1) {
		printf("Open error\n");
		return 1;
	}
	close(1);
	if(open(argv[4], O_WRONLY | O_CREAT) == -1) {
		printf("Open for write error\n");
		return 1;
	}
	execlp("tr", "tr",  argv[1], argv[2], NULL); 	
	return 1;
}

int zad3(int argc, char* argv[]) {
	if(argc < 4) {
		printf("Argc error\n");
		return 1;
	}

	if(argc == 3) {
		execlp("tr", "tr", argv[1], argv[2]);
		printf("tr error\n");
		return 1;
	}

	for(int i = 3; i < argc; i++) {
		int pid = fork();
		if(pid == 0) {
			close(0);
			open(argv[i], O_RDONLY);
			execlp("tr", "tr", argv[1], argv[2], NULL);
			printf("Exec error\n");
			return 1;		
		}
	}

	for(int i = 3; i<argc; i++) {
		int status;
		wait(&status);
	}

	return 0;	
}

int zad4(int argc, char* argv[]) {
	if( argc < 2) {
		printf("Argc err\n");
		return 1;
	}

	int fd[2];
	if(pipe(fd) == -1) {
		printf("pipe error \n");
		return 1;
	}

	int pid = fork();
	if(!pid) {
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		close(0);
		argv[0] = "grep";
		execvp("grep", argv);
		printf("Grep error\n");
		exit(1);
	}
	
	int fd2[2];
	if(pipe(fd2) == -1) {
		printf("Second pipe error\n");
		exit(1);
	}

	pid = fork();
	if(!pid) {
		dup2(fd[0], 0);
		dup2(fd2[1], 1);
		close(fd[1]);
		close(fd2[0]);
		execlp("sort", "sort", NULL);
		printf("Sort error\n");
		exit(1);
	} else {
		int fd3[2];
		if(pipe(fd3) == -1) {
			printf("Third pipe error\n");
			return 1;
		}
		pid = fork();
		if(!pid) {
			dup2(fd2[0], 0);
			dup2(fd3[1], 1);
			close(fd2[1]);
			close(fd3[0]);
			execlp("uniq", "uniq", NULL);		
			printf("Uniq Error \n");
			exit(1);
		}
		close(fd3[1]);
		dup2(0, fd3[0]); 			
		execlp("wc", "wc", "-l", NULL);
	}
		
}

int bonus(int argc, char* argv[]) {
	for(int i = 1; i<argc; i++) {
		int status = kill(atoi(argv[i]), SIGKILL);
		if(status == -1) {
			printf("Couldn't kill %s\n", argv[i]);
		}
	}
	return 0;
}

int main(int argc, char* argv[]) {
	int rc;
	// rc = zad1(argc, argv);
	//rc = zad2(argc, argv);
	// rc = zad3(argc, argv);
	//rc = zad4(argc, argv);
	rc = bonus(argc, argv);
	
	return rc;
}
