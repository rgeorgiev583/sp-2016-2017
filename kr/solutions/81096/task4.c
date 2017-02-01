#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
		printf("Not enought arguments");
	else
	{
	    int fd[2];
	    if(pipe(fd) == 0)
        {
            int pid = fork();
            if(pid == 0)
            {
                close(0);
                close(1);
                dup(fd[0]);
                dup(fd[1]);

                close(fd[0]);
                close(fd[1]);

                execvp("grep", ++argv);
            }
            else
            {
                int status;
                wait(&status);

                if(!fork())
                {
                    close(0);
                    close(1);
                    dup(fd[0]);
                    dup(fd[1]);

                    close(fd[0]);
                    close(fd[1]);

                    execlp("sort", NULL);
                }
                else
                {
                    wait(&status);

                    if(!fork())
                    {
                        close(0);
                        close(1);
                        dup(fd[0]);
                        dup(fd[1]);

                        close(fd[0]);
                        close(fd[1]);

                        execlp("wc", "-l", NULL);
                    }
                    else
                    {
                        wait(&status);

                        if(!fork())
                        {
                            close(0);
                            close(1);
                            dup(fd[0]);
                            dup(fd[1]);

                            close(fd[0]);
                            close(fd[1]);

                            execlp("uniq", NULL);
                        }
                        else
                        {
                            waitpid(&status);

                            char buf[512];
                            while(int n = read(fd[0], buf, 512))
                            {
                                buf[n] = '\0';
                                printf(buf);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            int status;
            waitpid(&status);
        }

	}

    return 0;
}
