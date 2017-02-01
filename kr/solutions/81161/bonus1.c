#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    kill(atoi(argv[i]), SIGTERM);
  }

  return 0;
}
