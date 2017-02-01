#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	if (argc < 4)
		printf("Not enought arguments");
	else
	{
	    int i;

	    for(i = 3; i < argc; i++)
        {
            int fd = open(argv[i], O_RDWR);
            int pid = fork();
            if(pid == 0)
            {
                close(0);
                close(1);
                dup(fd);
                dup(fd);
                close(fd);

                execlp("tr", argv[1], argv[2], NULL);
            }
            else
            {
                int status;
                wait(&status);
            }

            close(fd);
        }


	}

    return 0;
}

