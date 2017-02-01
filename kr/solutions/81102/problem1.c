#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1000
int main(int argc, char** argv)
{

    //0 ime
    // 1 N
    // path1
    // path2

    if (argc < 4)
        return 1;

    int n = argv[1];
    char buf[BUF_SIZE];

    int fd = open(argv[2], O_RDWR | O_CREAT ,0664);
    int fd2 = open(argv[3], O_RDONLY | O_CREAT , 0664);
    if (fd == -1 || fd2 == -1){
      return 1;
    }

    int len;
    lseek(fd, n, SEEK_END);
    while ((len = read(fd2, buf, BUF_SIZE)))
          write(fd, buf, len);

    return 0;
}
