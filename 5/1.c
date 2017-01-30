#include <unistd.h>


int main(int argc, char** argv)
{
    if (argc < 1)
        return 1;

    argv[0] = "cat";
    execvp("cat", argv);
}
