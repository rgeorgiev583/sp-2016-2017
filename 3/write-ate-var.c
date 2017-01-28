#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    if (argc < 4)
        return 1;

    int fd = open(argv[1], O_WRONLY);
    lseek(fd, atoi(argv[3]), SEEK_END);  // премества офсета на позицията на първия байт след края на файла
    const char* str = argv[2];  // завършва с терминиращ нулев байт
    write(fd, str, strlen(str));
    return 0;
}
