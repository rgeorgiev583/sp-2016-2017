#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc < 5) {
    return 1;
  }

  close(0);
  open(argv[3], O_RDONLY);
  close(1);
  open(argv[4], O_WRONLY);

  argv[0] = "tr";
  execlp(argv[0], argv[0], argv[1], argv[2], NULL);
}
