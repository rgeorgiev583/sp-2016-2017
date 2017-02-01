#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1000

int main(int argc, char** argv)
{
    if (argc < 4)
        return 1;

    int n = atoi(argv[1]);
    int fd1 = open(argv[2], O_WRONLY, 0644);
    int fd2 = open(argv[3], O_RDONLY);
    lseek(fd1, n, SEEK_END);

    int len;
    char buf[BUFSIZE];

    while ((len = read(fd2, buf, 1000)))
        write(fd1, buf, len);

    return 0;
}
