#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("foo", O_WRONLY);
    lseek(fd, 5, SEEK_END);  // премества офсета на позицията на шестия байт след края на файла
    char str[] = "quux";  // завършва с терминиращ нулев байт
    write(fd, str, sizeof(str));
    return 0;
}
