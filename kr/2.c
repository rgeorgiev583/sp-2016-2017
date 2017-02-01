#include <unistd.h>
#include <fcntl.h>


int main(int argc, char** argv)
{
    if (argc < 5)
        return 1;

    close(0);
    open(argv[3], O_RDONLY);
    close(1);
    creat(argv[4], 0644);

    execlp("tr", "tr", argv[1], argv[2], NULL);
}
