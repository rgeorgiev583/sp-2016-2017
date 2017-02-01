#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char buf[1024];
    int fd1, fd2;
    int n;
    
    if (argc < 4)
        return 1;
        
    fd1 = open(argv[2], O_WRONLY);
    fd2 = open(argv[3], O_RDONLY);
    
    lseek(fd1, atoi(argv[1]), SEEK_END);     
    while ((n = read(fd2, buf, 1024)) > 0) {
         if (write(fd1, buf, n) != n) {
             return 1;
         }
    }

    return 0;
}

