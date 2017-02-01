#include <unistd.h>

int main(int argc, char **argv) {
  int fd[2];
  pipe(fd);

  if (!fork()) {
    close(1);
    close(fd[0]);
    dup(fd[1]);

    argv[0] = "grep";
    execvp(argv[0], argv);

  } else {

    int fd2[2];
    pipe(fd2);

    if (!fork()) {
      close(0);
      close(fd2[1]);
      dup(fd2[0]);

      execlp("wc", "wc", "-l", NULL);
    }
    close(0);
    close(fd[1]);
    dup(fd[0]);

    close(1);
    close(fd2[0]);
    dup(fd2[1]);

    execlp("sort", "sort", NULL);
  }

  return 0;
}
