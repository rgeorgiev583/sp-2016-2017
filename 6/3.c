#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    pid_t pid = fork();

    if (!pid)
        execv("./gennum", argv);
    else
    {
        int status;
        waitpid(pid, &status, 0);
        execv("./sumnum", argv);
    }
}
