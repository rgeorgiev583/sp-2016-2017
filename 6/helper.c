#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    if (argc < 4)
        exit(1);

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0x644);
    int start = atoi(argv[2]), len = atoi(argv[3]);

    for (int i = start; i < len; i++)
        write(fd, (const char*)&i, sizeof(i));

    return 0;
}
