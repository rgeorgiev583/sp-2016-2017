#include <string.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char** argv)
{
    if (argc < 3)
        return 1;

    int fd = open(argv[1], O_WRONLY);
    lseek(fd, 0, SEEK_END);  // премества офсета на позицията на първия байт след края на файла
    write(fd, argv[2], strlen(argv[2]));
    return 0;
}
