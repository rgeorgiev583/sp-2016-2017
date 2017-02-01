#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	if (argc < 3)
		printf("Not enought arguments");
	else
	{
	    int fd[2];
	    for(int i = 1; i < argc; i += 2)
        {
            if(i > 1)
            {
                close(0);
                dup(fd[0]);
            }

            if(pipe(fd) == 0)
            {
                if(!fork())
                {
                    close(1);
                    dup(fd[1]);

                    execlp(argv[i], argv[i+1], NULL);
                }
                else
                {
                    int status;
                    wait(&status);
                }
            }
        }

	}

    return 0;
}

