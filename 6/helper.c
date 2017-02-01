#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    if (argc < 4)
        exit(1);

    int fd = creat(argv[1], 0644);
    int start = atoi(argv[2]), len = atoi(argv[3]);

    for (int i = start; i < len; i++)
        write(fd, (const char*)&i, sizeof(i));

    return 0;
}
