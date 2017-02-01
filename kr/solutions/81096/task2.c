#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	if (argc < 5)
		printf("Not enought arguments");
	else
	{
	    int pid = fork();
	    if(pid == 0)
        {
            int fdFile, fdDest;
            fdFile = open(argv[3], O_RDONLY);
            fdDest = open(argv[4], O_WRONLY);

            close(0);
            close(1);
            dup(fdFile);
            dup(fdDest);

            close(fdFile);
            close(fdDest);

            execlp("tr", argv[1], argv[2], NULL);
        }
        else
        {
            int status;
            wait(&status);
        }

	}

    return 0;
}

