#include <unistd.h>


int main(int argc, char** argv)
{
    argv[0] = "cat";
    execvp("cat", argv);
}
