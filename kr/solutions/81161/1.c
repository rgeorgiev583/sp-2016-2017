#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 100

int main(int argc, const char **argv) {
  if (argc < 4) {
    return 1;
  }

  int fd1 = open(argv[2], O_WRONLY);
  lseek(fd1, atoi(argv[1]), SEEK_END);
  int fd2 = open(argv[3], O_RDONLY);

  char buf[BUF_SIZE];
  int len;

  while ((len = read(fd2, buf, BUF_SIZE))) {
    write(fd1, buf, len);
  }

  return 0;
}
