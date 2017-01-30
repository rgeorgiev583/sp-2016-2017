#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1000


int main(int argc, char** argv)
{
    if (argc > 1)
    {
        int fd = creat(argv[1], 0644);
        close(1);
        dup(fd);
    }

    char buf[BUF_SIZE];
    int len;
    while ((len = read(0, buf, BUF_SIZE)))
        write(1, buf, len);
    return 0;
}
