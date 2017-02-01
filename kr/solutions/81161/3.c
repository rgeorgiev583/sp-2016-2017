#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  if (argc < 4) {
    return 1;
  }

  for (int i = 3; i < argc; i++) {
    if (!fork()) { // in the child process
      close(0);
      open(argv[i], O_RDONLY);

      argv[0] = "tr";
      execlp(argv[0], argv[0], argv[1], argv[2], NULL);
    }
  }

  for (int i = 3; i < argc; i++) {
    wait(NULL);
  }

  return 0;
}
