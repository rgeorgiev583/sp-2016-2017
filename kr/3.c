#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char** argv)
{
    if (argc < 3)
        return 1;

    if (argc == 3)
        execlp("tr", "tr", argv[1], argv[2], NULL);

    for (int i = 3; i < argc; i++)
        if (!fork())
        {
            close(0);
            open(argv[i], O_RDONLY);
            execlp("tr", "tr", argv[1], argv[2], NULL);
        }

    for (int i = 3; i < argc; i++)
    {
        int status;
        wait(&status);
    }

    return 0;
}
