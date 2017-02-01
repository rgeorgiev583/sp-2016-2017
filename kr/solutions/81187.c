#define _POSIX_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

#define BUF_SIZE 256


//Task 1
int main(int argc, char **argv)
{
	if(argc<4)
		return 1;

	int fd1=open(argv[2], O_WRONLY);
	if(fd1==-1)
		return 1;

	int fd2=open(argv[3], O_RDONLY);
	if(fd2==-1)
		return 1;

	if(lseek(fd1, atoi(argv[1]), SEEK_END)==-1)
		return 1;		

	int n;
	char buf[BUF_SIZE];

	while((n=read(fd2, buff, BUF_SIZE)))
		write(fd1, buff, n);
	return 0;
}

//Task 2
int main(int argc, char **argv)
{
	if (argc<5)
		return 1;
	close(0);

	open(argv[3], O_RDONLY);

	close(1);
	open(argv[4], O_WRONLY | O_CREAT);

	execlp("tr", "tr", argv[1], argv[2], NULL);
	return 0;
}


//Task 3
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		execlp("tr", "tr", argv[1], argv[2], NULL);
		return 0;
	}

	for (int i = 3; i<argc; i++)
	{
		if (fork() == 0)
		{
			close(0);
			open(argv[i], O_RDONLY);
			execlp("tr", "tr", argv[1], argv[2], NULL);
		}
	}

	for (int i = 3; i<argc; i++)
	{
		int status;
		wait(&status);
	}

	return 0;
}

//Task 4
int main(int argc, char **argv)
{
	int fd[2];
	pipe(fd);

	if (!fork())
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		argv[0] = "grep";
		execvp("grep", argv);
	}
	else
	{
		int fd2[2];
		pipe(fd2);
		if (!fork())
		{
			dup2(fd[0], 0);
			dup2(fd2[1], 1);
			close(fd[1]);
			close(fd2[0]);
			execlp("sort", "sort", NULL);
		}
		else
		{
			int fd3[2];
			pipe(fd3);
			if (!fork())
			{
				dup(fd2[0], 0);
				dup(fd3[1], 1);
				close(fd2[1]);
				close(fd3[0]);
				close(fd);
				execlp("uniq", "uniq", NULL);
			}
			dup2(fd3[0], 0);
			close(fd);
			close(fd2);
			close(fd3[1]);
			execlp("wc", "wc", "-l", NULL);
		}
	}
	return 0;
}


//Bonus 1
int main(int argc, char **argv)
{

	for (int i = 1; i<argc; i++)
	{
		kill(atoi(argv[i]), SIGKILL);
	}
	return 0;
}
